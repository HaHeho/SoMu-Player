#include "PlaylistController.hpp"


PlaylistController::PlaylistController(PlaylistControllerViewList* viewList, SoundSystem* ss, QObject* parent) : QObject(parent)
{
    this->viewList = viewList;
    this->soundSystem = ss;
    this->currentIndex = -1;
    this->isInit = false;

    connect(viewList, SIGNAL(delegateDraggedObject(QString)),this, SLOT(getDraggedObject(QString)), Qt::DirectConnection);
}

void PlaylistController::init()
{
    this->isInit = true;

    initStartPlaylist();

    this->isInit = false;
}


void PlaylistController::addToPlaylist(AlbumTrack* track)
{
    qDebug() << "Add To Playlist: " << track->getPath();

    track->setSound(this->soundSystem->createNewSound(track->getPath().toStdString()));

    PlaylistItem* item = new PlaylistItem(track, playlist.length());
    viewList->showItem(item);
    item->init();

    this->playlist.append(item);

    connect(item, SIGNAL(doubleClicked(PlaylistItem*)), this, SLOT(startSound(PlaylistItem*)));

    // if first item ... start playing
    if ((this->playlist.size() == 1 || !(this->soundSystem->isPlaying()))
            && (!this->isInit))
        startSound(item);
}

void PlaylistController::addToPlaylistAndPlay(AlbumTrack* track)
{
    addToPlaylist(track);
    startSound(this->playlist.last());
}

void PlaylistController::initStartPlaylist()
{
    Album* album = new Album("");

    QString path1 = "../SoMuPlayer/media/jaguar.wav";
    AlbumTrack* track1 = album->addTrack(path1);
    addToPlaylist(track1);

    QString path2 = "../SoMuPlayer/media/wave.mp3";
    AlbumTrack* track2 = album->addTrack(path2);
    addToPlaylist(track2);

    QString path3 = "../SoMuPlayer/media/stereo.ogg";
    AlbumTrack* track3 = album->addTrack(path3);
    addToPlaylist(track3);
}

void PlaylistController::startNextSound()
{
    this->currentIndex++;
    if (currentIndex == playlist.size())
        currentIndex = 0;

    startSound(this->playlist.at(this->currentIndex));
}

void PlaylistController::startPrevSound()
{
    this->currentIndex--;

    if (this->currentIndex == -1)
        currentIndex = playlist.size()-1;

    startSound(this->playlist.at(this->currentIndex));
}

void PlaylistController::startSound(PlaylistItem* sender)
{
    this->soundSystem->stopCurrentSound();

    this->currentIndex = this->playlist.indexOf(sender);
    this->soundSystem->playSound(sender->getSound());

    updateItemColors();

    emit setPlaylistCover(sender->getTrack()->getAlbum()->getCover()->getImagePath());
}

void PlaylistController::updateItemColors()
{
    for (int i = 0; i < this->playlist.size(); i++)
    {
        if (i < this->currentIndex)
            this->playlist.at(i)->setStatus(PlaylistItem::PAST);
        else if (i == this->currentIndex)
            this->playlist.at(i)->setStatus(PlaylistItem::NOW);
        else if (i > this->currentIndex)
            this->playlist.at(i)->setStatus(PlaylistItem::FUTURE);
    }
}

int PlaylistController::getPlaylistLength()
{
    return this->playlist.count();
}

PlaylistItem* PlaylistController::getItemAt(int i)
{
    return this->playlist.at(i);
}

void PlaylistController::removeItemAt(int i)
{
    this->playlist.removeAt(i);
}

void PlaylistController::getDraggedObject(QString path)
{
    Album* album = new Album(path);
    AlbumTrack* track = album->addTrack(path);
    addToPlaylist(track);
}
