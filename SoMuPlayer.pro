#-------------------------------------------------
#
# Project created by QtCreator 2012-05-19T15:51:24
#
#-------------------------------------------------

QT       += core gui

TARGET = SoMuPlayer
TEMPLATE = app


SOURCES += main.cpp\
    src/basicitem.cpp \
    src/soundsystem.cpp \
    src/soundcontrollerview.cpp \
    src/soundcontroller.cpp \
    src/playlistitem.cpp \
    src/playlistcontrollerview.cpp \
    src/playlistcontroller.cpp \
    src/player.cpp \
    src/dragarea.cpp \
    src/button.cpp

HEADERS  += \
    src/basicitem.h \
    src/soundsystem.h \
    src/soundcontrollerview.h \
    src/soundcontroller.h \
    src/playlistitem.h \
    src/playlistcontrollerview.h \
    src/playlistcontroller.h \
    src/player.h \
    src/dragarea.h \
    src/button.h

FORMS    += mainwindow.ui

RESOURCES += \
    ressources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/api/lib/release/ -lfmodex64
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/api/lib/debug/ -lfmodex64
else:unix:!macx:!symbian: LIBS += -L$$PWD/api/lib/ -lfmodex64

INCLUDEPATH += $$PWD/api
DEPENDPATH += $$PWD/api
