# qjackctl.pro
#
#建立一个库的makefile
TEMPLATE    = lib
TARGET = qjackctl

INCLUDEPATH += .

include(src.pri)

#DEFINES += DEBUG

HEADERS += 	qjackctl.h \
        config.h \
	qjackctlAbout.h \
	qjackctlAlsaConnect.h \
	qjackctlAlsaGraph.h \
	qjackctlConnect.h \
	qjackctlAliases.h \
	qjackctlGraph.h \
	qjackctlGraphCommand.h \
	qjackctlInterfaceComboBox.h \
	qjackctlJackConnect.h \
	qjackctlJackGraph.h \
	qjackctlPatchbay.h \
	qjackctlPatchbayFile.h \
	qjackctlPatchbayRack.h \
	qjackctlSession.h \
	qjackctlSetup.h \
	qjackctlStatus.h \
	qjackctlSystemTray.h \
	qjackctlAboutForm.h \
	qjackctlConnectionsForm.h \
	qjackctlGraphForm.h \
	qjackctlMainForm.h \
	qjackctlMessagesStatusForm.h \
	qjackctlPatchbayForm.h \
	qjackctlSessionForm.h \
	qjackctlSetupForm.h \
	qjackctlPaletteForm.h \
	qjackctlSocketForm.h

SOURCES += \
        qjackctl.cpp \
	qjackctlAlsaConnect.cpp \
	qjackctlAlsaGraph.cpp \
	qjackctlConnect.cpp \
	qjackctlAliases.cpp \
	qjackctlGraph.cpp \
	qjackctlGraphCommand.cpp \
	qjackctlInterfaceComboBox.cpp \
	qjackctlJackConnect.cpp \
	qjackctlJackGraph.cpp \
	qjackctlPatchbay.cpp \
	qjackctlPatchbayFile.cpp \
	qjackctlPatchbayRack.cpp \
	qjackctlSession.cpp \
	qjackctlSetup.cpp \
	qjackctlSystemTray.cpp \
	qjackctlAboutForm.cpp \
	qjackctlConnectionsForm.cpp \
	qjackctlGraphForm.cpp \
	qjackctlMainForm.cpp \
	qjackctlMessagesStatusForm.cpp \
	qjackctlPatchbayForm.cpp \
	qjackctlSessionForm.cpp \
	qjackctlSetupForm.cpp \
	qjackctlPaletteForm.cpp \
	qjackctlSocketForm.cpp

FORMS += \
	qjackctlAboutForm.ui \
	qjackctlConnectionsForm.ui \
	qjackctlGraphForm.ui \
	qjackctlMainForm.ui \
	qjackctlMessagesStatusForm.ui \
	qjackctlPatchbayForm.ui \
	qjackctlSessionForm.ui \
	qjackctlSetupForm.ui \
	qjackctlPaletteForm.ui \
	qjackctlSocketForm.ui

RESOURCES += \
	qjackctl.qrc


TRANSLATIONS += \
	translations/qjackctl_cs.ts \
	translations/qjackctl_de.ts \
	translations/qjackctl_es.ts \
	translations/qjackctl_fr.ts \
	translations/qjackctl_it.ts \
	translations/qjackctl_ja.ts \
	translations/qjackctl_nl.ts \
	translations/qjackctl_pt.ts \
	translations/qjackctl_ru.ts


#链接到项目中的库列表
LIBS += -ljack -lasound
QT += core gui widgets xml dbus

#安装的文件
INSTALLS += target
INSTALLS += headers
#资源文件
RESOURCES= qjackctl.qrc
#将以release模式连编,静态库
CONFIG += release staticlib
#放置可执行程序目标的目录
DESTDIR=$$PWD/../../main_program/lib
#moc转换文件路径
MOC_DIR = build
#放置obj中间文件的目录
OBJECTS_DIR = build
#ui文件转换的路径
UI_DIR = build

