#include "PlaylistController.hpp"


PlaylistController::PlaylistController(PlaylistControllerViewList* viewList, SoundSystem* ss, QObject* parent) : QObject(parent)
{
    this->viewList = viewList;
    this->soundSystem = ss;
    this->currentIndex = -1;
    this->isInit = false;

    connect(viewList, SIGNAL(delegateDraggedObject(QString)),
            this, SLOT(getDraggedObject(QString)), Qt::DirectConnection);
}

void PlaylistController::init()
{
    this->isInit = true;

    initStartPlaylist();

    this->isInit = false;
}


void PlaylistController::addToPlaylist(AlbumTrack* track)
{
    qDebug() << "PlaylistController::addToPlaylist(AlbumTrack* track)";

    track->setSound(this->soundSystem->createNewSound(track->getPath().toStdString()));

    PlaylistItem* item = new PlaylistItem(track, 150, 20);
    item->setParentItem(this->viewList);
    item->setPos(0, item->getHeight() * (getPlaylistLength()));
    item->init();

    this->playlist.append(item);

    connect(item, SIGNAL(doubleClicked(PlaylistItem*)),
            this, SLOT(startSound(PlaylistItem*)));

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

    QString path1 = "../SoMu-Player/media/jaguar.wav";
    AlbumTrack* track1 = new AlbumTrack(album, path1);
    addToPlaylist(track1);

    QString path2 = "../SoMu-Player/media/wave.mp3";
    AlbumTrack* track2 = new AlbumTrack(album, path2);
    addToPlaylist(track2);

    QString path3 = "../SoMu-Player/media/stereo.ogg";
    AlbumTrack* track3 = new AlbumTrack(album, path3);
    addToPlaylist(track3);
}

void PlaylistController::startNextSound()
{
    this->currentIndex++;

    // if not last elememt + 1
    if (this->currentIndex != this->playlist.size())
    {
        startSound(this->playlist.at(this->currentIndex));
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
    this->soundSystem->stopCurrentSound();

    this->currentIndex = this->playlist.indexOf(sender);
    this->soundSystem->playSound(sender->getSound());

    updateItemColors();
    emit setPlaylistCover(sender->getCoverImage());
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
    AlbumTrack* track = new AlbumTrack(album, path);
    addToPlaylist(track);
}
