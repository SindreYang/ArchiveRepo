#!/usr/bin/python
# -*- coding: UTF-8 -*-
import sqlite3
import requests

# conn = sqlite3.connect('userData.sqlite')
# print "Opened database successfully"
# c = conn.cursor()
# c.execute('''CREATE TABLE COMPANY
#       (
#         ID            INT         NOT NULL,
#         DOUYIN_ID     CHAR(20),
#         NAME          CHAR(20),
#         SIGNA         CHAR(120),
#         LOCATION      CHAR(10),
#         CONSTELLATION CHAR(5),
#         FOCUS         INT,
#         FOLLOWER      INT,
#         Liked         INT,
#         VIDEO         INT,
#         like          INT
#       );''')
# print "Table created successfully"
# conn.commit()
# conn.close()

# 抖音密码字典
mapList = {
    'xe60d': '0',
    'xe616': '0',
    'xe610': '2',
    'xe61a': '3',
    'xe618': '1',
    'xe611': '3',
    'xe60e': '1',
    'xe602': '1',
    'xe605': '2',
    'xe617': '2',
    'xe613': '7',
    'xe604': '3',
    'xe60c': '4',
    'xe619': '4',
    'xe606': '4',
    'xe607': '5',
    'xe61b': '5',
    'xe60f': '5',
    'xe608': '6',
    'xe61f': '6',
    'xe612': '6',
    'xe603': '0',
    'xe61c': '7',
    'xe60a': '7',
    'xe60b': '8',
    'xe615': '9',
    'xe614': '8',
    'xe61d': '8',
    'xe61e': '9',
    'xe609': '9',
    '.': '.',
    'w': 'w'
  }

# 截取字符串
def subString(str, start, end, startInd = 0):
  startIndex = str.find(start.decode('utf-8'), startInd)
  if (startIndex == -1): return ''
  # print(startIndex)
  endIndex = str.find(end.decode('utf-8'), startIndex + 1)
  if (endIndex == -1): return ''
  # print(endIndex)
  # print(str[startIndex + len(start):endIndex])
  return str[startIndex + len(start.decode('utf-8')):endIndex]

# 截取字符串组
def subStringArr(str, start, end):
  arr = []
  nextIndex = 0
  while True:
    nextIndex = str.find(start.decode('utf-8'), nextIndex + 1)
    if nextIndex == -1:
      return arr
    temp = subString(str, start, end, nextIndex)
    if str == '':
      return arr
    arr.append(temp)
    # print start.decode('utf-8')
    
    # print nextIndex
  # endIndex = str.index(end.decode('utf-8'), startIndex + 1)
  # print(endIndex)

## 字体解码方法
def fontDecrypt(arr):
  str = ''
  for item in arr:
    if (item in mapList):
      str += mapList[item]
    else:
      print( item)
  return str

## 数字字体特殊处理
def subFontHtml(str, start):
  html = subString(res.text, start, '<span class="text"')
  # 针对小数点做特殊处理
  html = html.replace('.', '&#.;')
  # 针对万做特殊处理
  html = html.replace('</i>w </span>', '&#w;')
  font = subStringArr(html, '&#', ';')
  return fontDecrypt(font)

# 抖音ID特殊处理
def subDouyinID(str):
  str = subString(str, '抖音ID：     ', '</p>')
  # 清洗掉所有空格
  str = str.replace(' ', '')
  # 清洗出文本
  str = str.replace('<iclass="iconiconfont">', '')
  str = str.replace('</i>', '')
  # 将字体清洗为字符串
  for fontKey in mapList:
    str = str.replace('&#' + fontKey + ';', mapList[fontKey])
  return str

# 没有headers会返回页面不存在
headers = {
  "user-agent": 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.67 Safari/537.36'
}
res = requests.get('https://www.douyin.com/share/user/6796248446', headers = headers)
res.encoding = 'utf-8'

# print(res.text)
# 名字

print(subString(res.text, 'class="nickname">', '</p>'))
# 抖音ID
print(subDouyinID(res.text))

# 签名
# print(subString(res.text, '"signature">', '</p>'))
# 城市
print(subString(res.text, '"location">', '</span>'))
# 星座
print(subString(res.text, '"constellation">', '</span>'))
# 关注
print(subFontHtml(res.text, 'class="focus block">'))
# 粉丝
print(subFontHtml(res.text, 'class="follower block">'))
# 粉丝
print(subFontHtml(res.text, 'class="liked-num block">'))

# 作品
