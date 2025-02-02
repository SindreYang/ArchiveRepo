# -*- coding: UTF-8 -*-
"""
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
@path   ：py2nsis -> installer_pipeline.py
@IDE    ：PyCharm
@Author ：sindre
@Email  ：yx@mviai.com
@Date   ：2023/7/26 14:21
@Version: V0.1
@License: (C)Copyright 2021-2023 , UP3D
@Reference: 
@History:
- 2023/7/26 :
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
(一)本代码的质量保证期（简称“质保期”）为上线内 1个月，质保期内乙方对所代码实行包修改服务。
(二)本代码提供三包服务（包阅读、包编译、包运行）不包熟
(三)本代码所有解释权归权归神兽所有，禁止未开光盲目上线
(四)请严格按照保养手册对代码进行保养，本代码特点：
      i. 运行在风电、水电的机器上
     ii. 机器机头朝东，比较喜欢太阳的照射
    iii. 集成此代码的人员，应拒绝黄赌毒，容易诱发本代码性能越来越弱
声明：未履行将视为自主放弃质保期，本人不承担对此产生的一切法律后果
如有问题，热线: 114

                                                    __----~~~~~~~~~~~------___
                                   .  .   ~~//====......          __--~ ~~         江城子 . 程序员之歌
                   -.            \_|//     |||\\  ~~~~~~::::... /~
                ___-==_       _-~o~  \/    |||  \\            _/~~-           十年生死两茫茫，写程序，到天亮。
        __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~                    千行代码，Bug何处藏。
    _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /                   纵使上线又怎样，朝令改，夕断肠。
  .~       .~       |   \\ -_    /  /-   /   ||      \   /
 /  ____  /         |     \\ ~-_/  /|- _/   .||       \ /                     领导每天新想法，天天改，日日忙。
 |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\                          相顾无言，惟有泪千行。
          '         ~-|      /|    |-~\~~       __--~~                        每晚灯火阑珊处，夜难寐，加班狂。
                      |-~~-_/ |    |   ~\_   _-~            /\
                           /  \     \__   \/~                \__
                       _--~ _/ | .-~~____--~-/                  ~~==.
                      ((->/~   '.|||' -_|    ~~-/ ,              . _||
                                 -_     ~\      ~~---l__i__i__i--~~_/
                                 _-~-__   ~)  \--______________--~~
                               //.-~~~-~_--~- |-------~~~~~~~~
                                      //.-~~~--\
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                              神兽保佑                                 永无BUG

"""
__author__ = 'sindre'

import glob
import logging
import os

import shutil
import subprocess
import sys
import zipfile

import tool

logger = logging.getLogger(__name__)


class InstallerBuilder(object):
    """控制构建安装程序。这包括三个主要步骤:

    1.在构建目录中安排必要的文件
    2.填写模板NSI文件以控制NSIS
    3.运行 “makensis” 来构建安装程序

    """
    python_template = """

    
    {extra_preamble}
    
    if __name__ == '__main__':
        from {module} import {func}
        {func}()    
        
        
        """

    def __init__(self,
                 name,
                 version,
                 requirementstxt,
                 entry_point,
                 source_path,
                 icon="config/logo.ico",
                 author="SindreYang",
                 licence="config/licence.rtf",
                 onefile=1,
                 tobinary=1,
                 thirdpriority=1,
                 build_dir="./build_py2nsis",
                 python_version=None):
        self.appname =name.replace(" ","")
        self.version = version
        self.requirementsTxT = os.path.abspath(requirementstxt)
        self.icon = os.path.abspath(icon)
        self.author = os.path.abspath(author)
        self.licence = os.path.abspath(licence)
        self.OneFile = bool(int(onefile))
        self.ToBinary = bool(int(tobinary))
        self.ThirdPriority = bool(int(thirdpriority))
        self.build_dir = os.path.abspath(build_dir)
        self.third_dir = os.path.abspath(os.path.join(build_dir, "third"))
        self.entry_point = entry_point
        self.source_path = os.path.abspath(source_path)
        self.work_dir = os.getcwd()
        self.tmp_path = os.path.abspath(os.path.join(self.build_dir, "tmp"))
        self.python_path = os.path.abspath(os.path.join(self.build_dir, "py"))
        if python_version is None:
            version = sys.version_info
            version_number = f"{version.major}.{version.minor}.{version.micro}"
            self.python_version= version_number
        else:
            self.python_version = python_version



    def install_third(self):
        from pip._internal import main as pip_main
        #pip_main(['install', "pyinstaller", '--target', self.tmp_path])
        pip_main(['install', "pip", '--target', self.third_dir])
        # 读取 requirements.txt 文件
        with open(self.requirementsTxT, 'r') as file:
            requirements = file.readlines()
        name_str = self.entry_point.split(':')
        import_name, fun_name = name_str[0], name_str[1]

        if self.ThirdPriority:

            # 安装所有的whl文件到指定目录下
            for requirement in requirements:
                pip_main(['install', requirement.strip(), '--target', self.third_dir])
                code = f"""
import sys, os
import site
scriptdir, script = os.path.split(os.path.abspath(__file__))
installdir = scriptdir
thirddir = os.path.join(scriptdir, 'third')
appdir  =os.path.join(scriptdir, 'app')
sys.path.insert(0, thirddir)
sys.path.insert(0, appdir)
site.addsitedir(thirddir)
site.addsitedir(appdir)


if __name__ == '__main__':
    import qtmain
    {import_name}.{fun_name}()
"""
            with open(os.path.join(self.build_dir, 'app.py', ), 'w', encoding="utf-8") as f:
                f.write(code)

        else:
            shutil.copy(self.requirementsTxT, self.build_dir)
            # 否则写入脚本中，用户启动时在安装
            code = f"""
import sys, os
import site
scriptdir, script = os.path.split(os.path.abspath(__file__))
installdir = scriptdir
thirddir = os.path.join(scriptdir, 'third')
appdir  =os.path.join(scriptdir, 'app')
sys.path.insert(0, thirddir)
sys.path.insert(0, appdir)
site.addsitedir(thirddir)
site.addsitedir(appdir)


if __name__ == '__main__':
    try:
        import qtmain
    except Exception as e:
        print("import error:",sys.path)
        try:
            from pip._internal import main as pip_main
            pip_main(['install', '-r', 'requirements.txt', '--target','third'])
        except Exception as e:
            print("pip error:",e)
    {import_name}.{fun_name}()
"""

            with open(os.path.join(self.build_dir, 'app.py', ), 'w', encoding="utf-8") as f:
                f.write(code)

    def py2pyd(self):
        target_path = os.path.join(self.build_dir, "app")
        try:
            shutil.rmtree(target_path)
        except FileNotFoundError:
            pass
        shutil.copytree(self.source_path, target_path)
        if self.ToBinary:
            from setuptools import Extension, setup
            from Cython.Build import cythonize
            extensions = []
            py_files = []
            # 遍历目录下的所有文件
            for root, dirs, files in os.walk(target_path):
                for file in files:
                    # 判断文件名是否以 .py 结尾
                    if file.endswith('.py'):
                        # 构建文件的完整路径
                        file_path = os.path.join(root, file)
                        py_files.append(file_path)

                        # 构建扩展模块名称
                        module_name = os.path.splitext(file)[0]

                        # 构建扩展模块对象
                        extension = Extension(module_name, sources=[file_path])
                        extensions.append(extension)

            setup(
                ext_modules=cythonize(extensions, compiler_directives={'language_level': "3"}),
                script_args=["build_ext", "--inplace", "--build-lib", f"{target_path}", "--build-temp",
                             f"{self.tmp_path}"])

            # 删除.c和.py文件
            for file in glob.glob(os.path.join(target_path, "**/*"), recursive=True):
                if file.endswith((".c", ".py")):
                    os.remove(file)

    def py2exe_pyinstaller(self):
        # 调用命令行执行PyInstaller编译代码
        os.chdir(self.build_dir)
        check_file = "onedir"
        if self.OneFile:
            check_file = "onefile"

        code = f"""
import os
import sys
scriptdir, script = os.path.split(os.path.abspath(__file__))
thirddir = os.path.join(scriptdir, fR"{self.tmp_path}")
thirddir2 = os.path.join(scriptdir, 'third')
sys.path.insert(0, thirddir)
sys.path.insert(0, thirddir2)
import PyInstaller.__main__
PyInstaller.__main__.run([
    'app.py',
    f'--{check_file}',
    '--add-data=app;app',
    '--add-data=third;third',
    '--specpath=./',
    '--distpath=./',
    '--workpath=./tmp',
])        
        
        """
        with open('installer.py', 'w', encoding="utf-8") as f:
            f.write(code)

        subprocess.run(["./py/python.exe", "./installer.py"])
    def py2exe(self):
        # 调用命令行执行PyInstaller编译代码
        os.chdir(self.build_dir)
        code_c = R"""

#include <windows.h>

int main() {
    // 获取当前可执行文件的路径
    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);

    // 去除文件名部分，只保留目录路径
    char drive[_MAX_DRIVE];
    char dir[MAX_PATH];
    _splitpath_s(exePath, drive, sizeof(drive), dir, sizeof(dir), NULL, 0, NULL, 0);

    // 组合目录路径
    char dirPath[MAX_PATH];
    sprintf_s(dirPath, sizeof(dirPath), "%s%s", drive, dir);

    // 构建app.py的绝对路径
    char appPath[MAX_PATH];
    sprintf_s(appPath, sizeof(appPath), "%sapp.py", dirPath);

    // 构建python的绝对路径
    char pythonPath[MAX_PATH];
    sprintf_s(pythonPath, sizeof(pythonPath), "%spy/python.exe", dirPath);

    // 构建启动命令
    char command[MAX_PATH * 2];
    sprintf_s(command, sizeof(command), "\"%s\" \"%s\"", pythonPath, appPath);

    // 创建进程并执行命令
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    
    if (CreateProcessA(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        // 等待进程结束
        WaitForSingleObject(pi.hProcess, INFINITE);
        
        // 关闭进程和线程的句柄
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}
        
        """
        with open('app.c', 'w', encoding="utf-8") as f:
            f.write(code_c)
        code_steup = """
from distutils.ccompiler import new_compiler
import distutils.sysconfig
import sys
import os
from pathlib import Path

def compile(src):
    src = Path(src)
    cc = new_compiler()
    exe = src.stem
    cc.add_include_dir(distutils.sysconfig.get_python_inc())
    cc.add_library_dir(os.path.join(sys.base_exec_prefix, 'libs'))
    # First the CLI executable
    objs = cc.compile([str(src)])
    cc.link_executable(objs, exe)
    # Now the GUI executable
    cc.define_macro('WINDOWS')
    objs = cc.compile([str(src)])
    cc.link_executable(objs, exe + 'w')

if __name__ == "__main__":
    compile("app.c")  
        
        """
        with open('app_setup.py', 'w', encoding="utf-8") as f:
            f.write(code_steup)


        subprocess.run(["./py/python.exe", "./app_setup.py"])

    def exe2nsis(self):
        # 获取当前脚本的绝对路径
        os.chdir(os.path.dirname(os.path.realpath(__file__)))
        print(f"exe2nsis工作目录：{os.getcwd()}")
        self.exe_7z_path = os.path.abspath("../bin/7z/7z.exe")
        self.exe_nsis_path = os.path.abspath("../bin/NSIS/makensis.exe")
        self.config_path = os.path.abspath("../config")
        # 压缩app目录
        files_to_compress =[f"{os.path.abspath(self.build_dir)}/{i}" for i in  ["app", "py","third","app.exe","app.py","requirements.txt"]]
        subprocess.run([f"{self.exe_7z_path}", "a",f"{self.work_dir}/app.7z"]+files_to_compress)
        # 替换文件
        nsis_code =f"""
# ====================== 自定义宏 产品信息==============================
!define PRODUCT_NAME           		"{self.appname}"
!define PRODUCT_PATHNAME           	"{self.appname}"     #安装卸载项用到的KEY
!define INSTALL_APPEND_PATH         "{self.appname}"     #安装路径追加的名称 
!define INSTALL_DEFALT_SETUPPATH    ""       #默认生成的安装路径 
!define EXE_NAME               		"app.exe" # 指定主运行程序，快捷方式也是用此程序生成
!define PRODUCT_VERSION        		"{self.version}"
!define PRODUCT_PUBLISHER      		"{self.author}"
!define PRODUCT_LEGAL          		""${{PRODUCT_PUBLISHER}} Copyright（c）2023""
!define INSTALL_OUTPUT_NAME    		"{self.appname}_V{self.version}.exe"

# ====================== 自定义宏 安装信息==============================
!define INSTALL_7Z_PATH 	   		"{self.work_dir}\\app.7z"
!define INSTALL_7Z_NAME 	   		"app.7z"
!define INSTALL_RES_PATH       		"skin.zip"
!define INSTALL_LICENCE_FILENAME    "{self.licence}"
!define INSTALL_ICO 				"{self.icon}"


!include "ui.nsh"

# ==================== NSIS属性 ================================

# 针对Vista和win7 的UAC进行权限请求.
# RequestExecutionLevel none|user|highest|admin
RequestExecutionLevel admin

#SetCompressor zlib

; 安装包名字.
Name "${{PRODUCT_NAME}}"

# 安装程序文件名.

OutFile "{self.work_dir}\\{self.appname}_V{self.version}.exe"

InstallDir "1"

# 安装和卸载程序图标
Icon              "${{INSTALL_ICO}}"
UninstallIcon     "uninst.ico"

        
        """

        # 执行封装命令
        os.chdir(self.config_path)
        with open("output.nsi", "w") as file:
            file.write(nsis_code)
        subprocess.run([f"{self.exe_nsis_path}", "./output.nsi"])




    def run(self,clean=False):
        """
        运行构建安装程序的所有步骤。
        """

        try:
            # 从干净的构建目录开始
            shutil.rmtree(self.build_dir)
        except FileNotFoundError:
            pass
        os.makedirs(self.build_dir)
        os.makedirs(self.tmp_path)

        # 安装python
        tool.python_installer(self.python_path,version=self.python_version)


        #转换二进制
        self.py2pyd()

        # 安装依赖到指定文件夹
        self.install_third()

        # 生成单文件
        self.py2exe()


        # # 封装nsis
        self.exe2nsis()

        if clean:
            shutil.rmtree(self.build_dir)
            os.remove(f"{self.work_dir}\\app.7z")
