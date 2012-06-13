#include "PlaylistController.hpp"


PlaylistController::PlaylistController(SoundSystem* ss, QObject* parent) : QObject(parent)
{
    this->soundSystem = ss;
    this->currentIndex = -1;
}


PlaylistItem* PlaylistController::addToPlaylist(AlbumTrack* track)
{
    track->setSound(this->soundSystem->createNewSound(track->getPath().toStdString()));

    PlaylistItem* item = new PlaylistItem(track, 150, 20);
    connect(item, SIGNAL(doubleClicked(PlaylistItem*)), this, SLOT(startSound(PlaylistItem*)));
    playList.append(item);

    /*
    // if first item ... start playing
    if (playList.size() == 1)
        startSound(item);
    */

    return item;
}

void PlaylistController::startNextSound()
{
    qDebug() << "PlaylistController::startNextSound()";
    this->currentIndex++;

    // if not last elememt + 1
    if (this->currentIndex != this->playList.size())
    {
        startSound(this->playList.at(this->currentIndex));
    }
    else
    {
        this->soundSystem->stopCurrentSound();
        updateItemColors();
        emit setPlaylistCover(new QPixmap());
    }
}

void PlaylistController::startSound(PlaylistItem* sender)
{
    qDebug() << "PlaylistController::startSound()";
    this->soundSystem->stopCurrentSound();

    this->currentIndex = this->playList.indexOf(sender);
    this->soundSystem->playSound(sender->getSound());

    updateItemColors();
    emit setPlaylistCover(sender->getCoverImage());
}

void PlaylistController::updateItemColors()
{
    for (int i = 0; i < this->playList.size(); i++)
    {
        if (i < this->currentIndex)
            this->playList.at(i)->setStatus(PlaylistItem::PAST);
        else if (i == this->currentIndex)
            this->playList.at(i)->setStatus(PlaylistItem::NOW);
        else if (i > this->currentIndex)
            this->playList.at(i)->setStatus(PlaylistItem::FUTURE);
    }
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
