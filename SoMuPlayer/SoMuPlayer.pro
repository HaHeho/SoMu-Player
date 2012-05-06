#-------------------------------------------------
#
# Project created by QtCreator 2012-05-06T14:04:19
#
#-------------------------------------------------

QT       += core gui phonon

TARGET = SoMuPlayer
TEMPLATE = app


SOURCES +=\
        MainWindow.cpp \
    Main.cpp \
    Menu.cpp

HEADERS  += MainWindow.hpp \
    Menu.hpp

wince*{
    DEPLOYMENT_PLUGIN += phonon_ds9 phonon_waveout
}