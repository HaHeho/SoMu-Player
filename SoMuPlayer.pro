#-------------------------------------------------
#
# Project created by QtCreator 2012-05-19T15:51:24
#
#-------------------------------------------------

QT       += core gui

TARGET = SoMuPlayer
TEMPLATE = app

LIBS += -L$$PWD/lib/fmod -lfmodex_vc

INCLUDEPATH += \
    $$PWD/lib \
    $$PWD/lib/fmod/inc \
    $$PWD/src

DEPENDPATH += \
    $$PWD/lib \
    $$PWD/lib/fmod/inc \
    $$PWD/src

SOURCES += main.cpp\
    src/SoundSystem.cpp \
    src/SoundControllerView.cpp \
    src/SoundController.cpp \
    src/PlaylistItem.cpp \
    src/PlaylistControllerView.cpp \
    src/PlaylistController.cpp \
    src/Player.cpp \
    src/DragArea.cpp \
    src/Button.cpp \
    src/BasicItem.cpp

HEADERS  += \
    src/SoundSystem.hpp \
    src/SoundControllerView.hpp \
    src/SoundController.hpp \
    src/PlaylistItem.hpp \
    src/PlaylistControllerView.hpp \
    src/PlaylistController.hpp \
    src/Player.hpp \
    src/DragArea.hpp \
    src/Button.hpp \
    src/BasicItem.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    ressources.qrc
