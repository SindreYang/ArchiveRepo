TEMPLATE    = app

SOURCES     =src/jack_engine.cpp \
src/rhdz.cpp \
src/main.cpp \
        ../C++/qjackctl/qjackctlAlsaConnect.cpp \
        ../C++/qjackctl/qjackctlAlsaGraph.cpp \
        ../C++/qjackctl/qjackctlConnect.cpp \
        ../C++/qjackctl/qjackctlAliases.cpp \
        ../C++/qjackctl/qjackctlGraph.cpp \
        ../C++/qjackctl/qjackctlGraphCommand.cpp \
        ../C++/qjackctl/qjackctlInterfaceComboBox.cpp \
        ../C++/qjackctl/qjackctlJackConnect.cpp \
        ../C++/qjackctl/qjackctlJackGraph.cpp \
        ../C++/qjackctl/qjackctlPatchbay.cpp \
        ../C++/qjackctl/qjackctlPatchbayFile.cpp \
        ../C++/qjackctl/qjackctlPatchbayRack.cpp \
        ../C++/qjackctl/qjackctlSession.cpp \
        ../C++/qjackctl/qjackctlSetup.cpp \
        ../C++/qjackctl/qjackctlSystemTray.cpp \
        ../C++/qjackctl/qjackctlAboutForm.cpp \
        ../C++/qjackctl/qjackctlConnectionsForm.cpp \
        ../C++/qjackctl/qjackctlGraphForm.cpp \
        ../C++/qjackctl/qjackctlMainForm.cpp \
        ../C++/qjackctl/qjackctlMessagesStatusForm.cpp \
        ../C++/qjackctl/qjackctlPatchbayForm.cpp \
        ../C++/qjackctl/qjackctlSessionForm.cpp \
        ../C++/qjackctl/qjackctlSetupForm.cpp \
        ../C++/qjackctl/qjackctlPaletteForm.cpp \
        ../C++/qjackctl/qjackctlSocketForm.cpp \

HEADERS     = src/jack_engine.h \
src/rhdz.h \
qt_h/buttongroup.h \
qt_h/cpumemorylabel.h \
qt_h/gaugeprogress.h \
qt_h/navlabel.h \
qt_h/panelitem.h \
qt_h/switchbutton.h \
src/ui_mainUI.h \
src/ui_setup.h



HEADERS += ../C++/qjackctl/config.h \
        \
        ../C++/qjackctl/qjackctlAlsaConnect.h \
        ../C++/qjackctl/qjackctlAlsaGraph.h \
        ../C++/qjackctl/qjackctlConnect.h \
        ../C++/qjackctl/qjackctlAliases.h \
        ../C++/qjackctl/qjackctlGraph.h \
        ../C++/qjackctl/qjackctlGraphCommand.h \
        ../C++/qjackctl/qjackctlInterfaceComboBox.h \
        ../C++/qjackctl/qjackctlJackConnect.h \
        ../C++/qjackctl/qjackctlJackGraph.h \
        ../C++/qjackctl/qjackctlPatchbay.h \
        ../C++/qjackctl/qjackctlPatchbayFile.h \
        ../C++/qjackctl/qjackctlPatchbayRack.h \
        ../C++/qjackctl/qjackctlSession.h \
        ../C++/qjackctl/qjackctlSetup.h \
        ../C++/qjackctl/qjackctlStatus.h \
        ../C++/qjackctl/qjackctlSystemTray.h \
        ../C++/qjackctl/qjackctlAboutForm.h \
        ../C++/qjackctl/qjackctlConnectionsForm.h \
        ../C++/qjackctl/qjackctlGraphForm.h \
        ../C++/qjackctl/qjackctlMainForm.h \
        ../C++/qjackctl/qjackctlMessagesStatusForm.h \
        ../C++/qjackctl/qjackctlPatchbayForm.h \
        ../C++/qjackctl/qjackctlSessionForm.h \
        ../C++/qjackctl/qjackctlSetupForm.h \
        ../C++/qjackctl/qjackctlPaletteForm.h \
        ../C++/qjackctl/qjackctlSocketForm.h


FORMS += \
            src/mainUI.ui \
            src/setup.ui \
            ../C++/qjackctl/qjackctlAboutForm.ui \
            ../C++/qjackctl/qjackctlConnectionsForm.ui \
            ../C++/qjackctl/qjackctlGraphForm.ui \
            ../C++/qjackctl/qjackctlMainForm.ui \
            ../C++/qjackctl/qjackctlMessagesStatusForm.ui \
            ../C++/qjackctl/qjackctlPatchbayForm.ui \
            ../C++/qjackctl/qjackctlSessionForm.ui \
            ../C++/qjackctl/qjackctlSetupForm.ui \
            ../C++/qjackctl/qjackctlPaletteForm.ui \
            ../C++/qjackctl/qjackctlSocketForm.ui

QT += core gui widgets xml dbus


INSTALLS += target resource/pics


CONFIG += release
DESTDIR=bin
MOC_DIR = build
OBJECTS_DIR = build
UI_DIR = build

RESOURCES= resource/application.qrc ../C++/resources_qjack.qrc 	../C++/qjackctl/qjackctl.qrc


LIBS += -L$$PWD/lib/ -lqjack -lportaudio -lasound -lm -lpthread -ljack

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

unix:!macx: PRE_TARGETDEPS += $$PWD/lib/libqjack.a


unix:!macx: LIBS += -L/home/sindre/my_library/QT/5.15.2/gcc_64/plugins/designer/ -lqucd

INCLUDEPATH +=/home/sindre/my_library/QT/5.15.2/gcc_64/plugins/designer

DEPENDPATH += /home/sindre/my_library/QT/5.15.2/gcc_64/plugins/designer


SUBDIRS += \
    ../C++/libqjack.pro




