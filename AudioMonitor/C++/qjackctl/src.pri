# qjackctl.pri
#
PREFIX  = /usr/local
BINDIR  = /usr/local/bin
LIBDIR  = /usr/local/lib
DATADIR = /usr/local/share
MANDIR  = /usr/local/share/man

VERSION = 0.6.2
CONFIG += release

INCLUDEPATH += /home/sindre/my_software/Qt5.12.9/5.12.9/gcc_64/include 
LIBS += -L/home/sindre/my_software/Qt5.12.9/5.12.9/gcc_64/lib  -ljack -lasound -L/usr/local/lib -lportaudio -lasound -lm -lpthread
# Extra optimization flags
QMAKE_CXXFLAGS +=   -I/usr/include/alsa -pthread -I/usr/local/include


# D-BUS support
QDBUS = dbus
!isEmpty(QDBUS) {
	QT += dbus
}

# Network support
QNETWORK = network
!isEmpty(QNETWORK) {
	QT += network
}
