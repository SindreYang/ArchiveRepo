from setuptools import setup, find_packages

GFICLEE_VERSION = '2023.9.11'

setup(
    name='sindre-lmdb',
    version=GFICLEE_VERSION,
    packages=find_packages(),
    install_requires=[
        "numpy", "psutil", "lmdb", "msgpack"
    ],
    url='https://github.com/SindreYang/pylmdb',
    license='GNU General Public License v3.0',
    author='SindreYang',
    description='simple lmdb wrapper'
)