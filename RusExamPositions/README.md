# 信息

每次参加考试，地区名额有限，通过html元素自动抢位置；

## 使用方法

1. 填上自己的学号

    ```python
    #用户名，密码
    username = "？"
    passwd = "？"
    # 城市，地区(以下为四川成都各区域代码)
    starts = "sc01"
    ends = "sc0108"
    ```

2. 输入自己的考区xpath,(不知道则F12-->选取考区元素-->查看xpath)

   ```python

    # 代码80行开始
    self.driver.select('ctl00$ContentPlaceHolder1$aecEdit$fvData$ddlKSDSZ', self.starts)

   ```
