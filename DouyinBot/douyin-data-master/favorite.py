#!/usr/bin/python
# -*- coding: UTF-8 -*-
import sqlite3
import time
import base64
from douyin import *

conn = sqlite3.connect('./data/userDataSimple.sqlite')
print("Opened database successfully")
c = conn.cursor()
c.execute('''CREATE TABLE IF NOT EXISTS SIMPLE
      (
        DOUYIN_ID     CHAR(20),
        NAME          CHAR(20),
        SIGNA         CHAR(120),
        BIRTHDAY      CHAR(10),
        GET_TIME      INT(10)
      );''')
print("Table created successfully")
conn.commit()
conn.close()

UnknownUserList = ['69528936131']

# 获取用户关注列表
async def getUserFavorite(user):
  saveUserDataNum = 0
  # 时间
  Time = time.time()
  dy = DouyinTool()
  logging.info("start get follow list")
  # 链接数据库
  conn = sqlite3.connect('./data/userDataSimple.sqlite')
  c = conn.cursor()
  async for video in dy.get_follow_list(user):
    # 从数据库中查找结果
    cursor = c.execute(f"select * from SIMPLE where DOUYIN_ID = {video['user_id']}")
    res = cursor.fetchall()
    # 判断结果是否存在
    if (len(res) == 0):
      # print('save user data:')
      # print(video)
      # 去除换行符
      video['nickname'] = video['nickname'].replace('\n', '')
      video['nickname'] = video['nickname'].replace("'", "''")
      video['signature'] = video['signature'].replace('\n', '')
      video['signature'] = video['signature'].replace("'", "''")
      # 插入用户数据
      # print("Opened database successfully")
      c.execute(f"INSERT INTO SIMPLE (DOUYIN_ID, NAME, SIGNA, BIRTHDAY, GET_TIME) \
        VALUES ({video['user_id']}, '{video['nickname']}', '{video['signature']}', '{video['birthday']}', {int(Time)} )");
      conn.commit()
      # print("Records created successfully")
      saveUserDataNum += 1
      # 用户池上限100防止溢出
      if (len(UnknownUserList) < 100):
        UnknownUserList.append(video['user_id'])
  UnknownUserList.remove(user)
  # print(str(user))
  logging.info(f"user {str(user)} clear! save data number {str(saveUserDataNum)} strip")
  logging.info(f"current user pool:{str(UnknownUserList)}")
  conn.close()

save_dir = 'C:/Users/my/Documents/GitHub/douyin-hack/data/video'
concurrency = 20
user = '69528936131'
action = 'favorite'
follow = False
# trio.run(main, user, action, follow, save_dir, concurrency)
while len(UnknownUserList) > 0:
  trio.run(getUserFavorite, UnknownUserList[0])
logging.info('all over!')