import os
import configparser
import logging
import subprocess
import zipfile

import requests
from tqdm import tqdm

logger = logging.getLogger(__name__)


def get_installer_builder_args(configfile):
    # 创建ConfigParser对象
    config = configparser.ConfigParser()
    # 读取配置文件
    config.read(configfile, encoding='utf-8')

    # 创建字典用于存储参数
    config_dict = {}

    # 遍历所有的section和option，并将它们添加到字典中
    for section in config.sections():
        for option, value in config.items(section):
            config_dict[option] = value
    return config_dict




def python_installer(install_dir, version='3.9.6'):
    #url = f'https://www.python.org/ftp/python/{version}/python-{version}-embed-amd64.zip'
    url = f'https://mirrors.huaweicloud.com/python/{version}/python-{version}-embed-amd64.zip'
    file_path = os.path.join(install_dir, 'tmp')
    python_path = os.path.join(file_path, f"python.zip")
    if not os.path.exists(file_path):
        os.makedirs(file_path)
    if not os.path.exists(python_path):
        try:
            # 发送下载请求
            print("Python安装包开始下载！")
            with requests.get(url, stream=True) as r, open(python_path, 'wb') as f:
                total_size = int(r.headers.get('Content-Length', 0))
                progress_bar = tqdm(total=total_size, unit='B', unit_scale=True, ncols=80)
                for data in r.iter_content(chunk_size=8192):
                    progress_bar.update(len(data))
                    f.write(data)
                progress_bar.close()
            print("Python安装包下载完成！")
        except Exception as e:
            print("下载过程出现错误:", str(e))
            return 0

    try:
        # 执行安装命令
        # install_command = [
        #     python_path,
        #     '/quiet',
        #     'InstallAllUsers=0',
        #     'DefaultJustForMeTargetDir=' + install_dir,
        #     'AssociateFiles=0',
        #     'CompileAll=1',
        #     'AppendPath=0',
        #     'Shortcuts=0',
        #     'Include_doc=0',
        #     'Include_dev=0',
        #     'Include_exe=0',
        #     'Include_launcher=0',
        #     'Include_lib=1',
        #     'Include_tcltk=0',
        #     'Include_pip=1',
        #     'Include_test=0',
        #     'Include_tools=0',
        # ]
        # uninstall_command = [
        #     python_path,
        #     '/quiet',
        #     '/uninstall',
        #     'DefaultJustForMeTargetDir=' + install_dir,
        #     ]
        # subprocess.run(uninstall_command, check=True,capture_output=True)
        # print("Python开始安装！")
        # result = subprocess.run(install_command, check=True,capture_output=True)
        # print(result.stdout.decode())
        # print("Python安装完成！")
        #shutil.rmtree(file_path)

        print("Python开始安装！")
        with zipfile.ZipFile(python_path, 'r') as zip_ref:
            zip_ref.extractall(install_dir)
    except subprocess.CalledProcessError as e:
        print("安装过程出现错误:", str(e))




