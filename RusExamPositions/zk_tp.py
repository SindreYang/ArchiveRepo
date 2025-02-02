from splinter.browser import Browser
from time import sleep
import smtplib
from email.mime.text import MIMEText

import os


class tp(object):
    """初始化"""
    driver_name=''
    executable_path=''
    #用户名，密码
    username = "？"
    passwd = "？"
    # 城市，地区
    starts = "sc01"
    ends = "sc0108"
    """网址"""
    ticket_url = "http://wb.zk789.cn/ApplyExamination/EditApplyExamination.aspx"
    login_url = "http://wb.zk789.cn/Login.aspx"
    initmy_url = "http://wb.zk789.cn/Notice.aspx"
    relay_url="http://wb.zk789.cn/Main.aspx"
    
    
    def __init__(self):
        self.driver_name='chrome'
        self.executable_path='D:/ProgramData/chromedriver'

    def send (self):
        self.msg_from = '550549443@qq.com'  # 发送方邮箱
        self.passwd = 'ndnatjdouhdkbbha'  # 填入发送方邮箱的授权码
        self.msg_to = 'sindre1997@sina.com'  # 收件人邮箱
    
        self.subject = "已抢到座位，速来付款"  # 主题
        self.content = "来自新——邮箱"
        msg = MIMEText (self.content)
        msg ['Subject'] = self.subject
        msg ['From'] = self.msg_from
        msg ['To'] = self.msg_to
        try:
            s = smtplib.SMTP_SSL ("smtp.qq.com", 465)  # 邮件服务器及端口号
            s.login (self.msg_from, self.passwd)
            s.sendmail (self.msg_from, self.msg_to, msg.as_string ())
            print ("发送成功")
        except:
            print ("发送失败")
        finally:
            s.quit ()

    def login(self):
        self.driver.visit(self.login_url)
        self.driver.fill("ctl00$ContentPlaceHolder1$TBZjhm", self.username)
        self.driver.fill("ctl00$ContentPlaceHolder1$TBPassWord", self.passwd)
        print ("等待验证码，自行输入...")
        while True:
            if self.driver.url != self.initmy_url:
                sleep(1)
            else:
                break
        
    def start(self):
        self.driver=Browser(driver_name=self.driver_name,executable_path=self.executable_path)
        self.driver.driver.set_window_size(1400, 1000)
        self.login()
        #同意
        sleep (3)
        self.driver.find_by_xpath ('//input[@type="checkbox"]').click ()
        self.driver.find_by_xpath ('//input[@type="submit"]').click ()
        sleep (2)
        #self.driver.visit (self.relay_url)
        self.driver.find_by_xpath ('//a[@id="ctl00_ContentPlaceHolder1_lbtnBKEdit"]').click ()
        # sleep(1)s
        #self.driver.visit(self.ticket_url)
        i=0
        while True:
            if self.driver.url == self.ticket_url:
                try:
                    print ("考位页面开始...")
                    # 加载信息
                    sleep(2)
                    self.driver.select('ctl00$ContentPlaceHolder1$aecEdit$fvData$ddlKSDSZ', self.starts)
                    if i==0:
                        print ('选择成华区')
                        self.driver.select('ctl00$ContentPlaceHolder1$aecEdit$fvData$ddlKSQX', self.ends)
                        i+=1
                    else:
                        print('选择双流区')
                        self.driver.select ('ctl00$ContentPlaceHolder1$aecEdit$fvData$ddlKSQX','sc0122')
                        i-=1
                    #print(self.driver.find_by_xpath('//*[@id="ctl00_ContentPlaceHolder1_aecEdit_fvData_ddlKSQX"]/option[6]').bkrl)
                    self.driver.find_by_xpath ('//input[@id="btnAddCourse"]').first.click ()
                    
                    print('进入科目选择')
                    
                    sleep(2)
                    if  self.driver.find_by_xpath ('//*[@id="msg_statistic_pay"]').first.value!=0:
                        sleep(2)
                        with self.driver.get_iframe (0) as iframe:
                            print('选择科目')
                            iframe.find_by_xpath ('//*[@id="gvData_ctl03_cbSelect"]').first.check ()
                            sleep (1)
                            #iframe.find_by_xpath ('//*[@id="gvData_ctl05_cbSelect"]').first.check ()
                            #sleep (1)
                            #iframe.find_by_xpath ('//*[@id="gvData_ctl07_cbSelect"]').first.check ()
                            #sleep (1)
                            self.driver.find_by_xpath ('//*[@id="btnConfirm"]').first.click ()
                            sleep(2)
                        self.driver.find_by_xpath ('// *[ @ id = "ext-gen29"]').first.click()
                        # print(self.driver.find_by_xpath ('//*[@id="msg_statistic_pay"]').first.value)
                    else:
                        self.send()
                        break
                    
                except :
                    print ('程序崩溃了，刷新中')
                    self.driver.reload ()
                    sleep(5)
            else:
                print ('服务器无响应，刷新中')
                self.driver.quit ()
                self.start()
                os.system ('shutdown -s -t 60')
                print('60s 后关机')
        



if __name__ == '__main__':
    zk=tp()
    zk.start()

