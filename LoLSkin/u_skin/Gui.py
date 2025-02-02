# -*- utf-8 -*-

import sys
import time

from PyQt5.QtCore import Qt, QRect, QThread, pyqtSignal
from PyQt5.QtGui import QPixmap, QFont, QPainter
from PyQt5.QtWidgets import QDesktopWidget
from PyQt5.QtWidgets import QWidget, QPushButton, QApplication, QLabel, QVBoxLayout, QHBoxLayout

from Update_Gui import Local
from Update_Gui import Network


class Update(QThread):
    finish = pyqtSignal()
    def __init__(self):
        super().__init__()

    def __del__(self):
        self.wait()

    def run(self):
        a = Local()
        b = Network()

        b.get_download_url()
        b.download_update()

        a.uncompression()

        a.del_old_version()
        a.run_leagueskin()

        time.sleep(4)
        a.reset()
        self.finish.emit()


class StartLeagueSkin(QThread):
    def __init__(self):
        super().__init__()

    def __del__(self):
        self.wait()

    def run(self):
        Local._run_leagueskin()


class MyWidget(QWidget):
    def __init__(self):
        super(QWidget, self).__init__()
        self.animation = None

    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.m_drag = True
            self.m_DragPosition = event.globalPos() - self.pos()
            event.accept()

    def mouseMoveEvent(self, QMouseEvent):
        if QMouseEvent.buttons() and Qt.LeftButton:
            try:
                self.move(QMouseEvent.globalPos() - self.m_DragPosition)
            except:
                pass
            QMouseEvent.accept()

    def mouseReleaseEvent(self, QMouseEvent):
        self.m_drag = False

    def center(self):
        screen = QDesktopWidget().screenGeometry()
        size = self.geometry()
        self.move((screen.width() - size.width()) / 2,
                  (screen.height() - size.height()) / 2)


class MainWindow(MyWidget):
    def __init__(self):
        super(QWidget, self).__init__()

        self.netVersion = None
        self.localVersion = None
        self.checkTime = time.strftime("%Y-%m-%d %H:%M:%S",time.localtime())
        self.result = None
        self.updateBool = False
        self.startBool = False
        self.repairBool = False

        self.initRoot()

        self.setAttribute(Qt.WA_TranslucentBackground, True)  # 设置窗口背景色为透明
        self.setStyleSheet(open("./MainUi.qss").read())
        self.SHADOW_WIDTH = 15
        self.resize(465, 215)
        self.center()
        self.setWindowTitle('LeagueSkinUpdate')
        self.setFixedSize(self.width(), self.height())
        self.setWindowFlags(Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint)  # 此句将窗口设为无边框并置顶

        self.setButton(True)
        self.setInfo(True)
        self.setLogo(True)
        self.setCloseButton(True)
        self.setMinMaxButtons(True)

        self.initLayout()

    def drawShadow(self, painter):
        """
        :param painter: 画笔
        :return:
        """
        # 绘制左上角、左下角、右上角、右下角、上、下、左、右边框
        self.pixmaps = list()
        self.pixmaps.append(str("./ico/frame/left_top.png"))
        self.pixmaps.append(str("./ico/frame/left_bottom.png"))
        self.pixmaps.append(str("./ico/frame/right_top.png"))
        self.pixmaps.append(str("./ico/frame/right_bottom.png"))
        self.pixmaps.append(str("./ico/frame/top_mid.png"))
        self.pixmaps.append(str("./ico/frame/bottom_mid.png"))
        self.pixmaps.append(str("./ico/frame/left_mid.png"))
        self.pixmaps.append(str("./ico/frame/right_mid.png"))

        painter.drawPixmap(0, 0, self.SHADOW_WIDTH, self.SHADOW_WIDTH, QPixmap(self.pixmaps[0]))  # 左上角
        painter.drawPixmap(self.width() - self.SHADOW_WIDTH, 0, self.SHADOW_WIDTH, self.SHADOW_WIDTH,
                           QPixmap(self.pixmaps[2]))  # 右上角
        painter.drawPixmap(0, self.height() - self.SHADOW_WIDTH, self.SHADOW_WIDTH, self.SHADOW_WIDTH,
                           QPixmap(self.pixmaps[1]))  # 左下角
        painter.drawPixmap(self.width() - self.SHADOW_WIDTH, self.height() - self.SHADOW_WIDTH, self.SHADOW_WIDTH,
                           self.SHADOW_WIDTH, QPixmap(self.pixmaps[3]))  # 右下角
        painter.drawPixmap(0, self.SHADOW_WIDTH, self.SHADOW_WIDTH, self.height() - 2 * self.SHADOW_WIDTH,
                           QPixmap(self.pixmaps[6]).scaled(self.SHADOW_WIDTH,
                                                           self.height() - 2 * self.SHADOW_WIDTH))  # 左
        painter.drawPixmap(self.width() - self.SHADOW_WIDTH, self.SHADOW_WIDTH, self.SHADOW_WIDTH,
                           self.height() - 2 * self.SHADOW_WIDTH, QPixmap(self.pixmaps[7]).scaled(self.SHADOW_WIDTH,
                                                                                                  self.height() - 2
                                                                                                  * self.SHADOW_WIDTH))
        # 右
        painter.drawPixmap(self.SHADOW_WIDTH, 0, self.width() - 2 * self.SHADOW_WIDTH, self.SHADOW_WIDTH,
                           QPixmap(self.pixmaps[4]).scaled(self.width() - 2 * self.SHADOW_WIDTH,
                                                           self.SHADOW_WIDTH))  # 上
        painter.drawPixmap(self.SHADOW_WIDTH, self.height() - self.SHADOW_WIDTH,
                           self.width() - 2 * self.SHADOW_WIDTH, self.SHADOW_WIDTH,
                           QPixmap(self.pixmaps[5]).scaled(self.width() - 2 * self.SHADOW_WIDTH,
                                                           self.SHADOW_WIDTH))  # 下

    def paintEvent(self, event):
        painter = QPainter(self)
        self.drawShadow(painter)
        painter.setPen(Qt.NoPen)
        painter.setBrush(Qt.white)
        painter.drawRect(QRect(self.SHADOW_WIDTH, self.SHADOW_WIDTH, self.width() - 2 * self.SHADOW_WIDTH,
                               self.height() - 2 * self.SHADOW_WIDTH))

    def initLayout(self):
        self.feedbackButton = QPushButton()
        self.feedbackButton.setText('问题反馈')
        self.feedbackButton.clicked.connect(self.fb_)
        self.aboutButton = QPushButton()
        self.aboutButton.setText('　关于　')
        self.aboutButton.clicked.connect(self.ab_)

        self.bottomLayout = QHBoxLayout()
        self.bottomLayout.setContentsMargins(8, 0, 8, 8)
        self.bottomLayout.addWidget(self.feedbackButton)
        self.bottomLayout.addStretch()
        self.bottomLayout.addWidget(self.aboutButton)

        self.titleBottonLayout = QHBoxLayout()
        self.titleBottonLayout.addWidget(self._MinimumButton)
        self.titleBottonLayout.addWidget(self._CloseButton)

        self.titleTLayout = QHBoxLayout()
        self.titleTLayout.addStretch()
        self.titleTLayout.addLayout(self.titleBottonLayout)

        self.titleRLayout = QVBoxLayout()
        self.titleRLayout.addLayout(self.titleTLayout)
        self.titleRLayout.addStretch()

        self.logoLayout = QVBoxLayout()
        self.logoLayout.setContentsMargins(8, 8, 0, 0)
        self.logoLayout.addWidget(self.logo)
        self.logoLayout.addStretch()

        self.titleLayout = QHBoxLayout()
        self.titleLayout.addLayout(self.logoLayout)
        self.titleLayout.addLayout(self.titleRLayout)

        self.infoLayout = QHBoxLayout()
        self.infoLayout.addWidget(self.info)

        self.buttonLayout = QHBoxLayout()
        self.buttonLayout.addWidget(self.updateButton)
        self.buttonLayout.addWidget(self.repairButton)
        self.buttonLayout.addWidget(self.startButton)

        self._mainLayout = QVBoxLayout()
        self._mainLayout.setContentsMargins(15, 15, 15, 15)
        self._mainLayout.setSpacing(0)
        self._mainLayout.addLayout(self.titleLayout)
        self._mainLayout.addLayout(self.infoLayout)
        self._mainLayout.addLayout(self.buttonLayout)
        self._mainLayout.addStretch()
        self._mainLayout.addLayout(self.bottomLayout)
        self.setLayout(self._mainLayout)

    def setButton(self, bool):
        if bool:
            self.repairButton = QPushButton()
            self.repairButton.setText('修复翻译错误')
            self.repairButton.setFixedWidth(100)
            self.repairButton.setEnabled(self.repairBool)
            self.repairButton.clicked.connect(self.repair_)

            self.updateButton = QPushButton()
            self.updateButton.setText('更新LeagueSkin')
            self.updateButton.setFixedWidth(100)
            self.updateButton.setEnabled(self.updateBool)
            self.updateButton.clicked.connect(self.update_)

            self.startButton = QPushButton()
            self.startButton.setText('启动LeagueSkin')
            self.startButton.setFixedWidth(100)
            self.startButton.setEnabled(self.startBool)
            self.startButton.clicked.connect(self.start_)

    def ab_(self):
        self.info.setText('该程序基于Python3.6.6开发,\n用于检测并更新LeagueSkin;\n'
                          '使用它,可以最大限度的避免\n因软件未及时更新而导致的其他后果\n(封号, 无法使用等);')

    def fb_(self):
        self.info.setText('Bug反馈请邮件至550549443')

    def start_(self):
        self.startButton.setEnabled(False)
        self.a = StartLeagueSkin()
        self.a.start()
        self.info.setText('正在启动LeagueSkin...\n如果未能成功启动,\n请检查是否赋予了管理员权限?')

    def repair_(self):
        Local.repair_language()
        self.info.setText('修复完成, 下次启动LeagueSkin有效.')
        self.repairButton.setEnabled(False)

    def update_(self):
        self.updateButton.setEnabled(False)
        self.info.setText('正在更新LeagueSkin, 请稍后...\n这个过程可能需要持续几分钟')
        self.thread = Update()
        self.thread.finish.connect(self.update_finish)
        self.thread.start()

    def update_finish(self):
        self.info.setText('更新已完成.\n正在启动LeagueSkin...')
        self.repairButton.setEnabled(True)

    def setInfo(self, bool):
        if bool:
            self.info = QLabel()
            self.info.setText("最新版本:%s\n当前版本:%s\n检测时间:%s\n检测结果:%s" % (
                self.netVersion, self.localVersion, self.checkTime, self.result))
            self.info.setFixedSize(200, 80)
            self.info.setAlignment(Qt.AlignCenter)

    def setLogo(self, bool):
        if bool:
            self.logo = QLabel()
            self.logo.setScaledContents(True)
            self.logo.setPixmap(QPixmap('ico\\icon.ico'))
            self.logo.setFixedSize(25, 25)
            self.logo.setObjectName('TitleLabel')

    def setCloseButton(self, bool):
        # 给widget定义一个setCloseButton函数，为True时设置一个关闭按钮
        if bool:
            self._CloseButton = QTitleButton(b'\xef\x81\xb2'.decode("utf-8"), self)
            self._CloseButton.setObjectName("CloseButton") # 设置按钮的ObjectName以在qss样式表内定义不同的按钮样式
            self._CloseButton.setToolTip("关闭")
            self._CloseButton.setMouseTracking(True) # 设置按钮鼠标跟踪（如不设，则按钮在widget上层，无法实现跟踪）
            self._CloseButton.setFixedHeight(20) # 设置按钮高度为标题栏高度
            self._CloseButton.clicked.connect(self.close) # 按钮信号连接到关闭窗口的槽函数

    def setMinMaxButtons(self, bool):
        # 给widget定义一个setMinMaxButtons函数，为True时设置一组最小化最大化按钮
        if bool == True:
            self._MinimumButton = QTitleButton(b'\xef\x80\xb0'.decode("utf-8"), self)
            self._MinimumButton.setObjectName("MinMaxButton") # 设置按钮的ObjectName以在qss样式表内定义不同的按钮样式
            self._MinimumButton.setToolTip("最小化")
            self._MinimumButton.setMouseTracking(True) # 设置按钮鼠标跟踪（如不设，则按钮在widget上层，无法实现跟踪）
            self._MinimumButton.setFixedHeight(20) # 设置按钮高度为标题栏高度
            self._MinimumButton.clicked.connect(self.showMinimized) # 按钮信号连接到最小化窗口的槽函数

    def initRoot(self):
        a = Local()
        a.get_local_version()
        b = Network()
        b.get_network_version()

        self.localVersion = a.version
        self.netVersion = b.version

        if a.version == b.version:
            self.result = '当前为最新版本.'
            self.startBool = True
            self.repairBool = True
        else:
            self.result = '需要下载最新版本.'
            self.updateBool = True


class QTitleButton(QPushButton):
    """
    新建标题栏按钮类
    """
    def __init__(self, *args):
        super(QTitleButton, self).__init__(*args)
        self.setFont(QFont("Webdings")) # 特殊字体以不借助图片实现最小化最大化和关闭按钮
        self.setFixedWidth(25)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())