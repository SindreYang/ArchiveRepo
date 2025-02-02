from PyQt5.QtCore import  *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import  *
from PyQt5.QtWebEngineWidgets import *
import sys
import random

from PyQt5 import QtCore, QtGui, QtWidgets
import sys
class Ui_widget(object):
    def setupUi(self, widget):
        widget.setObjectName("widget")
        widget.setEnabled(True)
        widget.resize(416, 667)
        widget.setFixedSize(widget.width(), widget.height())
        self.label = QtWidgets.QLabel(widget)
        self.label.setGeometry(QtCore.QRect(30, 10, 191, 17))
        self.label.setObjectName("label")
        self.lineEdit = QtWidgets.QLineEdit(widget)
        self.lineEdit.setGeometry(QtCore.QRect(0, 35, 301, 21))
        self.lineEdit.setObjectName("lineEdit")
        self.label_2 = QtWidgets.QLabel(widget)
        self.label_2.setGeometry(QtCore.QRect(0, 60, 391, 21))
        self.label_2.setObjectName("label_2")
        self.pushButton_run = QtWidgets.QPushButton(widget)
        self.pushButton_run.setGeometry(QtCore.QRect(310, 30, 89, 31))
        self.pushButton_run.setObjectName("pushButton_run")
        self.label_3 = QtWidgets.QLabel(widget)
        self.label_3.setGeometry(QtCore.QRect(90, 170, 211, 20))
        self.label_3.setObjectName("label_3")


        self.gridLayoutWidget = QtWidgets.QWidget(widget)
        self.gridLayoutWidget.setGeometry(QtCore.QRect(10, 200, 401, 451))
        self.gridLayoutWidget.setObjectName("gridLayoutWidget")
        self.gridLayout = QtWidgets.QGridLayout(self.gridLayoutWidget)
        names=['优酷','土豆','爱奇艺','芒果','乐视','腾讯','搜狐','PPTV','360视','暴风影音','M1905','咪咕视频',
        '音悦台','哔哩哔哩','华数TV','网易公开课','新浪视频','范特西','M3U8','私有云','韩国DAUM'	,'品善网','开眼视频'
        ,'优米网','好看视频','美拍','2MM','凤凰视频','Naver','糖豆网','秒拍','快手','17173','梨视频','中国蓝','第一视频'
        ,'爱拍视频','汽车之家','ECHOMV','东方头条','今日头条','阳光宽频','西瓜视频','酷6视频','CCTV央视','27盘','91广场舞',
        '爆米花','火猫直播','酷狗MV','酷狗MV','QQ音乐MV','酷狗直播','酷狗LIVE','天天看看','激动网','斗鱼视频','斗鱼直播',
        '虎牙视频','虎牙直播','熊猫星颜','熊猫直播','战旗视频','战旗直播','龙珠视频','龙珠直播','来疯直播','触手视频','触手直播','花椒直播','花椒视频'
        ,'全民直播','全民视频','CC直播','CC视频','印客直播','YY神曲','YY回放','YY小','一直播','NOW直播' ]

        posittions=[(i,j)for  i in range(19) for j in range(5)]

        for posittions,name in zip(posittions,names):
            label=QtWidgets.QLabel(name)
            label.setStyleSheet("font:10pt;color:rgb(0,0, 255);font-weight:40px;")
            self.gridLayout.addWidget(label,*posittions)
        self.gridLayout.setContentsMargins(0, 1, 2, 0)
        self.gridLayout.setObjectName("gridLayout")



        self.pushButton_switch = QtWidgets.QPushButton(widget)
        self.pushButton_switch.setGeometry(QtCore.QRect(100, 110, 171, 31))
        self.pushButton_switch.setObjectName("pushButton_switch")

        self.retranslateUi(widget)
        QtCore.QMetaObject.connectSlotsByName(widget)

    def retranslateUi(self, widget):
        _translate = QtCore.QCoreApplication.translate
        widget.setWindowTitle(_translate("widget", "VIP会员-新"))
        self.label.setText(_translate("widget", "视频网页最上面网址(链接):"))
        self.label_2.setText(_translate("widget", "复制VIP视频的地址到↑↑↑上栏中点击立即播放就行了"))
        self.pushButton_run.setText(_translate("widget", "开始播放"))
        self.pushButton_run.setStyleSheet("color:rgb(255,0,0)")
        self.label_3.setText(_translate("widget", "↓↓现支持以下免费播放↓↓"))
        self.pushButton_switch.setText(_translate("widget", "如果不能播放用力点我"))
        self.pushButton_switch.setStyleSheet("background: rgb(0,191,255);color:rgb(128,0,0)")
        self.pushButton_run.setStyleSheet ("background: rgb(0,191,255);color:rgb(128,0,0)")








class ScreenWindow (QMainWindow):
    def __init__ (self,url):
        super (ScreenWindow, self).__init__ ()
        self.setWindowTitle('vip视频影院')
        self.setGeometry(5,30,1355,730)

        self.browser=QWebEngineView()
        self.browser.settings().setAttribute(QWebEngineSettings.PluginsEnabled, True)  # 支持视频播放
        self.browser.settings().setAttribute(QWebEngineSettings.JavascriptEnabled, True)
        self.browser.settings().setAttribute(QWebEngineSettings.FullScreenSupportEnabled, True)
        # self.browser.page().fullScreenRequested.connect(self._fullScreenRequested)

        self.browser.load (QUrl (url))

        self.setCentralWidget(self.browser)
    #
    # def _fullScreenRequested(request):
    #     request.accept()
    #     w.showFullScreen()


    def screendisplay(self):
        if not self.isVisible ():
            self.show ()





class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        self.ui = Ui_widget()
        self.ui.setupUi(self)
        url=self.switch()
        #print(url)


        self.setIcon()
        self.ui.pushButton_run.clicked.connect (self.TwoT)
        self.ui.pushButton_switch.clicked.connect (self.TwoT)

    def TwoT(self):
        url = self.switch ()
        self.win2 = ScreenWindow (url)
        self.win2.screendisplay()

    def setIcon (self):
        palette1 = QPalette ()

        # palette1.setColor(self.backgroundRole(), QColor(192,253,123))   # 设置背景颜色.scaled(self.width(), self.height()
        palette1.setBrush (self.backgroundRole (), QBrush (QPixmap ('d.png')))  # 设置背景图片
        self.setPalette (palette1)
        self.setAutoFillBackground(True) # 不设置也可以


        self.setWindowIcon (QIcon ('d.png'))


    def addurl(self):
        url = self.ui.lineEdit.text ()
        return url

    def switch(self):
        countmax = len (open ('url', 'r').readlines ())
        count=random.randint(0,countmax-1)
        if count >= countmax-1:
            count = random.randint(0,countmax-1)
        else:
            count += 1
        with open ('url', 'r') as f:
            vurl = f.readlines ()
            vurl = vurl [count].replace ('\n', '')
            qurl = vurl + self.addurl()
            #print(qurl)
        return qurl

if __name__ =='__main__':
    #argvs = sys.argv
    # 支援flash
    #argvs.append('--ppapi-flash-path=./pepflashplayer.dll')
    app = QApplication (sys.argv)
    win1 = MainWindow ()
    win1.show ()
    app.exec_ ()
