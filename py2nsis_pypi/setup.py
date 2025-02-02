from setuptools import setup, find_packages
import os


import os 

def find_files(path='.'):
    dir_files = []
    for root, dirs, files in os.walk(path):
        file_list = [os.path.join(root, file) for file in files]
        if file_list:  # Only add directories that have files
            dir_files.append((root, file_list))
    return dir_files

examples_files = find_files("py2nsis/examples")
bin_files = find_files("py2nsis/bin")
config_files = find_files("py2nsis/config")
src_files = find_files("py2nsis/src")



data_files = []

for dir_tuple in examples_files:
    data_files.append(dir_tuple)
for dir_tuple in bin_files:
    data_files.append(dir_tuple)
for dir_tuple in config_files:
    data_files.append(dir_tuple)
for dir_tuple in src_files:
    data_files.append(dir_tuple)

setup(
    name='py2nsis',
    version='1.0',
    author='SindreYang',
    author_email='yx@mviai.com',
    description='Under Windows, convert Python to exe',
    long_description=open('README.md').read(),
    packages=find_packages(),
    data_files=data_files,
    entry_points={'console_scripts':['py2nsis=py2nsis.src.main:main']},
    include_package_data=True,
)
