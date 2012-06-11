#include "PlaylistController.hpp"


PlaylistController::PlaylistController(SoundSystem *ss, QObject *parent) : QObject(parent)
{
    this->soundSystem = ss;
}


PlaylistItem* PlaylistController::addToPlaylist(AlbumTrack* track)
{
    track->setSound(this->soundSystem->createNewSound(track->getPath().toStdString()));

    PlaylistItem* item = new PlaylistItem(track, 150, 20);
    connect(item, SIGNAL(doubleClicked(PlaylistItem*)), this, SLOT(startSound(PlaylistItem*)));
    playList.append(item);
    return item;
}

void PlaylistController::startSound(PlaylistItem* sender)
{
    this->soundSystem->stopCurrentSound();
    this->soundSystem->playSound(sender->getSound());
    emit setPlaylistCover(sender->getImage());
}

int PlaylistController::getPlayListLength()
{
    return playList.count();
}

PlaylistItem* PlaylistController::getItemAt(int i)
{
    return playList.at(i);
}

void PlaylistController::removeItemAt(int i)
{
    playList.removeAt(i);
}
