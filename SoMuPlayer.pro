#-------------------------------------------------
#
# Project created by QtCreator 2012-05-19T15:51:24
#
#-------------------------------------------------

QT       += core gui

TARGET = SoMuPlayer
TEMPLATE = app

win32: LIBS += -L$$PWD/lib/fmod -lfmodex_vc
else:unix:!macx:!symbian: LIBS += -L$$PWD/lib/fmod -lfmodex64

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
    src/PlaylistController.cpp \
    src/Player.cpp \
    src/DragArea.cpp \
    src/Button.cpp \
    src/BasicItem.cpp \
    src/PlaylistControllerViewList.cpp \
    src/PlaylistControllerViewCover.cpp \
    src/AlbumCover.cpp \
    src/Album.cpp \
    src/AlbumTrack.cpp

HEADERS  += \
    src/SoundSystem.hpp \
    src/SoundControllerView.hpp \
    src/SoundController.hpp \
    src/PlaylistItem.hpp \
    src/PlaylistController.hpp \
    src/Player.hpp \
    src/DragArea.hpp \
    src/Button.hpp \
    src/BasicItem.hpp \
    src/PlaylistControllerViewList.hpp \
    src/PlaylistControllerViewCover.hpp \
    src/AlbumCover.hpp \
    src/Album.hpp \
    src/AlbumTrack.hpp

FORMS    += mainwindow.ui

RESOURCES += \
    ressources.qrc
