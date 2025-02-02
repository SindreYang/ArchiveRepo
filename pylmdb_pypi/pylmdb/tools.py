import numpy as np
import os
import sys
import psutil

def encode_str(string, encoding="utf-8", errors="strict"):
    """返回输入字符串的编码字节对象。

    Parameters
    ----------
    string : string
    encoding : string
        Default is `utf-8`.
    errors : string
       指定应如何处理编码错误。默认为 `strict`.
    """
    return str(string).encode(encoding=encoding, errors=errors)


def decode_str(obj, encoding="utf-8", errors="strict"):
    """将输入字节对象解码为字符串。

    Parameters
    ----------
    obj : byte object
    encoding : string
        Default is `utf-8`.
    errors : string
       指定应如何处理编码错误。默认为 `strict`.
    """
    return obj.decode(encoding=encoding, errors=errors)

# 支持的序列化类型
TYPES = {"str": 1, "ndarray": 2}

# 默认数据库数
NB_DBS = 2

# 默认数据库的名称
DATA_DB = encode_str("data_db")
META_DB = encode_str("meta_db")

# 元数据的默认键
NB_SAMPLES = encode_str("nb_samples")



def encode_data(obj):
    """Return a dictionary with information encoding the input data object.

    Parameter
    ---------
    obj : data object
        If the incoming data object is neither a string nor an ordinary NumPy
        array, then the object will simply be returned as is.
    """
    if isinstance(obj, str):
        return {b"type": TYPES["str"], b"data": obj}
    elif isinstance(obj, np.ndarray):
        return {
            b"type": TYPES["ndarray"],
            b"dtype": obj.dtype.str,
            b"shape": obj.shape,
            b"data": obj.tobytes(),
        }
    else:
        # Assume the user know what they are doing
        return obj


def decode_data(obj):
    """Decode a serialised data object.

    Parameter
    ---------
    obj : Python dictionary
        A dictionary describing a serialised data object.
    """
    try:
        if TYPES["str"] == obj[b"type"]:
            return obj[b"data"]
        elif TYPES["ndarray"] == obj[b"type"]:
            return np.frombuffer(obj[b"data"], dtype=np.dtype(obj[b"dtype"])).reshape(obj[b"shape"])
        else:
            # Assume the user know what they are doing
            return obj
    except KeyError:
        # Assume the user know what they are doing
        return obj



def check_filesystem_type(current_path):
    """
    检测硬盘是否为ext4
    :param current_path:路径
    :return:
    """
    current_path = os.path.abspath(current_path)

    partitions = psutil.disk_partitions()

    for partition in partitions:
        if current_path.startswith(partition.mountpoint):
            fs_type = partition.fstype
            if fs_type == 'NTFS':
                print(f"当前路径<<{current_path}>>的文件系统类型是NTFS,不是ext4"
                      f"\n\033[91m注意lmdb会在window上无法按实际大小变化,mapsize为多,则申请多少空间（建议按需要写入的文件大小申请空间)\033[0m\n")
            else:
                print(f"\n当前路径<<{current_path}>>的文件系统类型不是NTFS.\033[92m\n可将mapsize最大化,db大小会按实际大小变化\033[0m\n")
