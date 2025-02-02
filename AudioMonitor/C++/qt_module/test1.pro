


LIBS += -ljack
QT += core gui widgets
QT += xml

RESOURCES= ../resources_qjack.qrc


DESTDIR=bin
MOC_DIR = build
OBJECTS_DIR = build
UI_DIR = build

HEADERS += \
    ../algorithms_sever/audio_tools.h \
    midi_widgets.h \
    vumeter.h \
    control_meter.h


SOURCES += \
    ../algorithms_sever/audio_tools.cpp \
    midi_widgets.cpp \
    vumeter.cpp \
    control_meter.cpp \
    main.cpp

