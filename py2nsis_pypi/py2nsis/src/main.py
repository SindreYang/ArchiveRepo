# -*- coding: UTF-8 -*-
"""
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
@path   ：py2nsis -> main.py
@IDE    ：PyCharm
@Author ：sindre
@Email  ：yx@mviai.com
@Date   ：2023/7/26 13:29
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
import sys
import os
sys.path.append(os.path.join(os.path.dirname(sys.executable),"py2nsis/src"))
import logging
import shutil
import argparse
import tool
import installer_pipeline

__version__ = '1.0'
logger = logging.getLogger(__name__)



def main(argv=None):
    
    """
    从命令行获取安装程序。
    """
    
    logger.setLevel(logging.INFO)
    logger.handlers = [logging.StreamHandler()]

    argp = argparse.ArgumentParser(prog='py2nsis')
    argp.add_argument('-c', '--config_file', help='ini安装配置文件')

    argp.add_argument('-d', '--debug', action='store_false', help='保留缓存')

    argp.add_argument('-g', '--generate', action='store_true', help='生成样例')
    options = argp.parse_args(argv)
    if len(sys.argv) == 1:
        print("No arguments provided.\n -c ini安装配置文件\n -d 保留缓存\n -g 生成样例.")

    if options.generate:
        file_dir = os.path.dirname(os.path.abspath(__file__))
        parent_dir = os.path.dirname(file_dir)
        shutil.copytree(f"{parent_dir}/examples",f"{os.getcwd()}/examples")
        print(f"创建成功：{os.getcwd()}/examples")
        return 0
    if options.config_file:
        dirname, config_file = os.path.split(options.config_file)
        if dirname:
            os.chdir(dirname)

        args = tool.get_installer_builder_args(config_file)
        IPB=installer_pipeline.InstallerBuilder(**args)
        IPB.run(clean=options.debug)

    



if __name__ == '__main__':
    main()
