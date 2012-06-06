#include <QDebug>
#include "src/playlistcontroller.h"


PlayListController::PlayListController(SoundSystem *ss, QObject *parent) : QObject(parent)
{
    this->soundSystem = ss;
}


PlayListItem* PlayListController::addToPlaylist(QString soundPath)
{
    FMOD::Sound* newSound = soundSystem->createNewSound(soundPath.toStdString());
    PlayListItem* item = new PlayListItem(newSound, 200, 20);
    connect(item, SIGNAL(doubleClicked(PlayListItem*)), this, SLOT(startSound(PlayListItem*)));
    playList.append(item);
    return item;
}


void PlayListController::startSound(PlayListItem* sender)
{
    this->soundSystem->stopCurrentSound();
    this->soundSystem->playSound(sender->getSound());
}


int PlayListController::getPlayListLength()
{
    return playList.count();
}


PlayListItem* PlayListController::getItemAt(int i)
{
    return playList.at(i);
}


void PlayListController::removeItemAt(int i)
{
    playList.removeAt(i);
}
