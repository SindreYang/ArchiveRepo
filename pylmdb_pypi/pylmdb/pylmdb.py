from .tools import *

try:
    import lmdb
    import msgpack
except ImportError:
    raise ImportError(
        "Could not import the LMDB library `lmdb` or  `msgpack`. Please refer "
        "to https://github.com/dw/py-lmdb/  or https://github.com/msgpack/msgpack-python for installation "
        "instructions."
    )

__all__ = ["Reader", "Writer", "merge_db", "repair_windows_size", "check_filesystem_type"]


class Reader(object):
    """用于读取包含张量（`numpy.ndarray`）数据集的对象。

    这些张量是通过使用MessagePack从Lightning Memory-Mapped Database (LMDB)中读取的。

    参数
    ---------
    dirpath : 字符串
        包含LMDB的目录路径。

    lock : 布尔值
        是否在读取器上使用锁定阻塞方法。
        如果为False，则确保在读取数据集时没有并发写入。

    """

    def __init__(self, dirpath, lock=True):
        self.dirpath = dirpath

        # 以只读模式打开LMDB环境
        self._lmdb_env = lmdb.open(dirpath, readonly=True, max_dbs=NB_DBS, lock=lock)

        # 打开与环境关联的默认数据库
        self.data_db = self._lmdb_env.open_db(DATA_DB)
        self.meta_db = self._lmdb_env.open_db(META_DB)

        # 读取元数据,BODGE:修复读取空数据库报错
        try:
            self.nb_samples = int(self.get_meta_str(NB_SAMPLES))
        except ValueError:
            self.nb_samples = 0


    def get_meta_key_info(self):
        """获取元数据库所有键"""
        key_set = set()
        # 创建一个读事务和游标
        with self._lmdb_env.begin(db=self.meta_db) as txn:
            cursor = txn.cursor()
            # 遍历游标并获取键值对
            for key, value in cursor:
                key_set.add(decode_str(key))
        return key_set

    def get_data_key_info(self):
        """获取元数据库所有键"""
        key_set = set()
        # 创建一个读事务和游标
        with self._lmdb_env.begin(db=self.data_db) as txn:
            cursor = txn.cursor()
            # 遍历游标并获取键值对
            for key, value in cursor:
                dict_v = msgpack.unpackb(value, raw=False, use_list=True)
                for k in dict_v.keys():
                    key_set.add(k)
        return key_set

    def get_meta_str(self, key):
        """将输入键对应的值作为字符串返回。

        该值从`meta_db`中检索。

        参数
        ---------
        key : 字符串或字节字符串
        """
        if isinstance(key, str):
            _key = encode_str(key)
        else:
            _key = key

        with self._lmdb_env.begin(db=self.meta_db) as txn:
            _k = txn.get(_key)
            if isinstance(_k, bytes):
                return decode_str(_k)
            else:
                return str(_k)

    def get_data_keys(self, i=0):
        """返回第i个样本在`data_db`中的所有键的列表。

        如果所有样本包含相同的键，则只需要检查第一个样本，因此默认值为`i=0`。

        参数
        ---------
        i : 整数，可选
        """
        return list(self[i].keys())

    def get_data_value(self, i, key):
        """返回第i个样本对应于输入键的值。

        该值从`data_db`中检索。

        因为每个样本都存储在一个msgpack中，所以在返回值之前，我们需要先读取整个msgpack。

        参数
        ----------
        i : 整数
        key : 字符串
        """
        try:
            return self[i][key]
        except KeyError:
            raise KeyError("键不存在：{}".format(key))

    def get_data_specification(self, i):
        """返回第i个样本的所有数据对象的规范。

        规范包括形状和数据类型。这假设每个数据对象都是`numpy.ndarray`。

        参数
        ---------
        i : 整数
        """
        spec = {}
        sample = self[i]
        for key in sample.keys():
            spec[key] = {}
            try:
                spec[key]["dtype"] = sample[key].dtype
                spec[key]["shape"] = sample[key].shape
            except KeyError:
                raise KeyError("键不存在：{}".format(key))

        return spec

    def get_sample(self, i):
        """从`data_db`返回第i个样本。

        参数
        ---------
        i : 整数
        """
        if 0 > i or self.nb_samples <= i:
            raise IndexError("所选样本编号超出范围： %d" % i)

        # 将样本编号转换为带有尾随零的字符串
        key = encode_str("{:010}".format(i))

        obj = {}
        with self._lmdb_env.begin(db=self.data_db) as txn:
            # 从LMDB读取msgpack，并解码其中的每个值
            _obj = msgpack.unpackb(txn.get(key), raw=False, use_list=True)
            for k in _obj:
                # 如果键存储为字节对象，则必须对其进行解码
                if isinstance(k, bytes):
                    _k = decode_str(k)
                else:
                    _k = str(k)
                obj[_k] = msgpack.unpackb(
                    _obj[_k], raw=False, use_list=False, object_hook=decode_data
                )

        return obj

    def get_samples(self, i, size):
        """返回从`i`到`i + size`的所有连续样本。

        假设：
        * 从`i`到`i + size`的每个样本具有相同的键集。
        * 样本中的所有数据对象都是`numpy.ndarray`类型。
        * 与同一个键关联的值具有相同的张量形状和数据类型。

        参数
        ----------
        i : 整数
        size : 整数
        """
        if 0 > i or self.nb_samples <= i + size - 1:
            raise IndexError(
                "所选样本编号超出范围： %d 到 %d（大小：%d）" % (i, i + size, size)
            )

        # 基于第i个样本做出关于数据的假设
        samples_sum = []
        with self._lmdb_env.begin(db=self.data_db) as txn:
            for _i in range(i, i + size):
                samples = {}
                # 将样本编号转换为带有尾随零的字符串
                key = encode_str("{:010}".format(_i))
                # 从LMDB读取msgpack，解码其中的每个值，并将其添加到检索到的样本集合中
                obj = msgpack.unpackb(txn.get(key), raw=False, use_list=True)
                for k in obj:
                    # 如果键存储为字节对象，则必须对其进行解码
                    if isinstance(k, bytes):
                        _k = decode_str(k)
                    else:
                        _k = str(k)
                    samples[_k] = msgpack.unpackb(
                        obj[_k], raw=False, use_list=False, object_hook=decode_data
                    )
                samples_sum.append(samples)

        return samples_sum

    def __getitem__(self, key):
        """使用`get_sample()`从`data_db`返回样本。

        参数
        ---------
        key : 整数或切片对象
        """
        if isinstance(key, (int, np.integer)):
            _key = int(key)
            if 0 > _key:
                _key += len(self)
            if 0 > _key or len(self) <= _key:
                raise IndexError("所选样本超出范围：`{}`".format(key))
            return self.get_sample(_key)
        elif isinstance(key, slice):
            return [self[i] for i in range(*key.indices(len(self)))]
        else:
            raise TypeError("无效的参数类型：`{}`".format(type(key)))

    def __len__(self):
        """返回数据集中的样本数量。
        """
        return self.nb_samples

    def __enter__(self):
        return self

    def __exit__(self, type, value, traceback):
        self.close()

    def __repr__(self):
        spec = self.get_data_specification(0)
        # 使用ANSI转义序列将输出文本设置为黄色
        out = "\033[93m"
        out += "类名:\t\t{}\n".format(self.__class__.__name__)
        out += "位置:\t\t'{}'\n".format(os.path.abspath(self.dirpath))
        out += "样本数量:\t{}\n".format(len(self))
        out += f"data_db所有键:\n\t{self.get_data_key_info()}\n"
        out += f"meta_db所有键:\n\t{self.get_meta_key_info()}\n"
        out += "数据键（第0个样本）:"
        for key in self.get_data_keys():
            out += "\n\t'{}' <- 数据类型: {}, 形状: {}".format(
                key, spec[key]["dtype"], spec[key]["shape"]
            )
        out += "\n\t提示：如果需要查看更多键类型可以使用-->get_data_specification(i=1)查看. "
        out += "\033[0m\n"
        return out

    def close(self):
        """关闭环境。

        使打开的任何迭代器、游标和事务无效。
        """
        self._lmdb_env.close()


class Writer(object):
    """用于编写张量数据集的对象 ('numpy.ndarray')。

    张量被写入闪电内存映射数据库 (LMDB)，并带有MessagePack的帮助。

    Parameters
    ----------
    dirpath : string
        应该写入LMDB的目录的路径。
    map_size_limit : int
        LMDB的map大小，单位为MB。必须足够大以捕获打算存储在LMDB中所有数据。
    ram_gb_limit : float
       同时放入RAM的数据的最大大小。此对象尝试写入的数据大小不能超过此数字。默认为 “2” GB。
    """

    def __init__(self, dirpath: str, map_size_limit: int, ram_gb_limit: float = 3):
        self.dirpath = dirpath
        self.map_size_limit = map_size_limit  # Megabytes (MB)
        self.ram_gb_limit = ram_gb_limit  # Gigabytes (GB)
        self.keys = []
        self.nb_samples = 0

        # 检测参数
        if self.map_size_limit <= 0:
            raise ValueError(
                "LMDB map 大小必须为正:{}".format(self.map_size_limit)
            )
        if self.ram_gb_limit <= 0:
            raise ValueError(
                "每次写入的RAM限制 (GB) 必须为为正：{}".format(self.ram_gb_limit)
            )

        # 将 `map_size_limit` 从 MB 转换到 B
        map_size_limit <<= 20

        # 打开LMDB环境
        self._lmdb_env = lmdb.open(dirpath, map_size=map_size_limit, max_dbs=NB_DBS)

        # 打开与环境关联的默认数据库
        self.data_db = self._lmdb_env.open_db(DATA_DB)
        self.meta_db = self._lmdb_env.open_db(META_DB)

        # 启动检测服务
        self.check_db_stats()

    def change_db_value(self, key: int, value: dict, safe_model: bool = True):
        """
        修改键值
        Parameters
        ----------
        key : 键
        value   :内容
        safe_model : 安全模式，如果开启，则修改会提示；

        Returns
        -------

        """
        num_size = self.nb_samples
        if key < num_size:
            if safe_model:
                _ok = input("\033[93m请确认你的行为,因为这样做,会强制覆盖数据,无法找回!\n"
                            f"当前数据库大小为<< {num_size} >>,索引从< 0 >>0开始计数,现在准备将修改<< {key} >>的值,同意请输入yes! 请输入:\033[93m")
                if _ok.strip().lower() != "yes":
                    print(f"用户选择退出! 您输入的是{_ok.strip().lower()}")
                    sys.exit(0)
            self.change_value(key, value)
        else:
            raise ValueError(
                f"当前数据库大小为<< {num_size} >>,将修改<< {key} >>应该小于当前数据库大小,索引从<< 0 >>开始计数! \033[0m\n")

    def change_value(self, num_id: int, samples: dict):
        """
        通过指定索引，修改内容
        Parameters
        ----------
        num_id : int 索引
        samples : dict 内容


        """

        # 检查数据类型
        gb_required = 0
        for key in samples:
            # 所有数据对象的类型必须为`numpy.ndarray`
            if not isinstance(samples[key], np.ndarray):
                raise ValueError(
                    "不支持的数据类型：" "`numpy.ndarray` != %s" % type(samples[key])
                )
            else:
                gb_required += np.uint64(samples[key].nbytes)

        # 确保用户指定的假设RAM大小可以容纳要存储的样本数
        gb_required = float(gb_required / 10 ** 9)
        if self.ram_gb_limit < gb_required:
            raise ValueError(
                "正在写入的数据大小大于`ram_gb_limit`,%d < %f" % (self.ram_gb_limit, gb_required)
            )

        # 对于每个样本，构建一个msgpack并将其存储在LMDB中
        with self._lmdb_env.begin(write=True, db=self.data_db) as txn:
            # 为每个数据对象构建一个msgpack
            msg_pkgs = {}
            for key in samples:
                # 确保当前样本是`numpy.ndarray`
                obj = samples[key]
                if not isinstance(obj, np.ndarray):
                    obj = np.array(obj)
                # 创建msgpack
                msg_pkgs[key] = msgpack.packb(obj, use_bin_type=True, default=encode_data)

                # LMDB键：样本编号作为带有尾随零的字符串
                key = encode_str("{:010}".format(num_id))

                # 构建最终的msgpack并将其存储在LMDB中
                pkg = msgpack.packb(msg_pkgs, use_bin_type=True)
                txn.put(key, pkg)

    def check_db_stats(self):
        """
        # 检查lmdb是继续写，还是新写
        Returns
        -------

        """

        with self._lmdb_env.begin(db=self.meta_db) as txn:
            _k = txn.get(encode_str("nb_samples"))
            if not _k:
                self.db_stats = "create_stats"
                print(
                    f"\n\033[92m检测到{self.dirpath}数据库\033[93m<数据为空>,\033[92m 启动创建模式，键从<< {self.nb_samples} >>开始 \033[0m\n")
            else:
                if isinstance(_k, bytes):
                    self.nb_samples = int(decode_str(_k))
                else:
                    self.nb_samples = int(_k)
                self.db_stats = "auto_update_stats"
                print(
                    f"\n\033[92m检测到{self.dirpath}数据库\033[93m<已有数据存在>,\033[92m启动自动增量更新模式,键从<< {self.nb_samples} >>开始\033[0m\n")

    def put_samples(self, samples: dict):
        """将传入内容的键和值放入`data_db` LMDB中。

        * 作为Python字典：
            * `put_samples({'key1': value1, 'key2': value2, ...})`

        函数假设所有值的第一个轴表示样本数。因此，单个样本必须在`numpy.newaxis`之前。

        参数
        ---------
        samples: dict 类型，由字符串和numpy数组组成
        """

        # 检查数据类型
        gb_required = 0
        for key in samples:
            # 所有数据对象的类型必须为`numpy.ndarray`
            if not isinstance(samples[key], np.ndarray):
                raise ValueError(
                    "不支持的数据类型：" "`numpy.ndarray` != %s" % type(samples[key])
                )
            else:
                gb_required += np.uint64(samples[key].nbytes)

        # 确保用户指定的假设RAM大小可以容纳要存储的样本数
        gb_required = float(gb_required / 10 ** 9)
        if self.ram_gb_limit < gb_required:
            raise ValueError(
                "正在写入的数据大小大于`ram_gb_limit`：%d < %f" % (self.ram_gb_limit, gb_required)
            )

        try:
            # 对于每个样本，构建一个msgpack并将其存储在LMDB中
            with self._lmdb_env.begin(write=True, db=self.data_db) as txn:
                # 为每个数据对象构建一个msgpack
                msg_pkgs = {}
                for key in samples:
                    # 确保当前样本是`numpy.ndarray`
                    obj = samples[key]
                    if not isinstance(obj, np.ndarray):
                        obj = np.array(obj)
                    # 创建msgpack
                    msg_pkgs[key] = msgpack.packb(obj, use_bin_type=True, default=encode_data)

                    # LMDB键：样本编号作为带有尾随零的字符串
                    key = encode_str("{:010}".format(self.nb_samples))

                    # 构建最终的msgpack并将其存储在LMDB中
                    pkg = msgpack.packb(msg_pkgs, use_bin_type=True)
                    txn.put(key, pkg)

                # 增加全局样本计数器
                self.nb_samples += 1
        except lmdb.MapFullError as e:
            raise AttributeError(
                "LMDB 的map_size 太小：%s MB, %s" % (self.map_size_limit, e)
            )

        # 将当前样本数写入`meta_db`
        self.set_meta_str(NB_SAMPLES, str(self.nb_samples))

    def set_meta_str(self, key, string):
        """将输入的字符串写入`meta_db`中的输入键。

        Parameters
        ----------
        key : string or bytestring
        string : string
        """
        if isinstance(key, str):
            _key = encode_str(key)
        else:
            _key = key

        with self._lmdb_env.begin(write=True, db=self.meta_db) as txn:
            txn.put(_key, encode_str(string))

    def __enter__(self):
        return self

    def __exit__(self, type, value, traceback):
        self.close()

    def __repr__(self):
        out = "\033[94m"
        out += f"类名:\t\t\t{self.__class__.__name__}\n"
        out += f"位置:\t\t\t'{os.path.abspath(self.dirpath)}'\n"
        out += f"LMDB的map_size:\t\t{self.map_size_limit}MB\n"
        out += f"RAM 限制:\t\t{self.ram_gb_limit}GB\n"
        out += f"当前模式:\t\t{self.db_stats}\n"
        out += f"当前开始序号为:\t\t{self.nb_samples}\n"
        out += "\033[0m\n"
        return out

    def close(self):
        """关闭环境。

        在关闭之前，将样本数写入`meta_db`。

        使所有打开的迭代器、游标和事务无效。
        """
        self.set_meta_str(NB_SAMPLES, str(self.nb_samples))
        self._lmdb_env.close()


def repair_windows_size(dirpath):
    # windows没法实时变化大小问题：
    db = Writer(dirpath=dirpath, map_size_limit=1)
    db.close()


def merge_db(merge_dirpath, A_dirpath, B_dirpath, map_size_limit=10000):
    """
    合并数据库
    Parameters
    ----------
    merge_dirpath
    A_dirpath
    B_dirpath
    map_size_limit

    Returns
    -------

    """
    merge_db = Writer(dirpath=merge_dirpath, map_size_limit=map_size_limit)
    A_db = Reader(dirpath=A_dirpath)
    B_db = Reader(dirpath=B_dirpath)

    # 开始合并数据
    # 将第一个数据库的数据复制到合并后的数据库
    for i in range(A_db.nb_samples):
        merge_db.put_samples(A_db[i])
    for i in A_db.get_meta_key_info():
        # nb_samples采用自增，不能强制覆盖
        if i != "nb_samples":
            merge_db.set_meta_str(i, A_db.get_meta_str(i))

    for i in range(B_db.nb_samples):
        merge_db.put_samples(B_db[i])
    for i in B_db.get_meta_key_info():
        # nb_samples采用自增，不能强制覆盖
        if i != "nb_samples":
            merge_db.set_meta_str(i, B_db.get_meta_str(i))

    A_db.close()
    B_db.close()
    merge_db.close()
