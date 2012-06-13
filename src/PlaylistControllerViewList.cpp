#include "PlaylistControllerViewList.hpp"


PlaylistControllerViewList::PlaylistControllerViewList(PlaylistController* pc, float w, float h) : BasicItem(w, h)
{
    this->pc = pc;
}


void PlaylistControllerViewList::init()
{
    ///*
    Album* album = new Album("");
    QString path1 = "C:/Users/User/Documents/Git-Projekte/SoMu-Player/media/jaguar.wav";
    AlbumTrack* track1 = album->addTrack(path1);
    createPlaylistItem(track1);
    QString path2 = "C:/Users/User/Documents/Git-Projekte/SoMu-Player/media/wave.mp3";
    AlbumTrack* track2 = album->addTrack(path2);
    createPlaylistItem(track2);
    QString path3 = "C:/Users/User/Documents/Git-Projekte/SoMu-Player/media/stereo.ogg";
    AlbumTrack* track3 = album->addTrack(path3);
    createPlaylistItem(track3);
    //*/

    /*
    Album* album = new Album("");
    AlbumTrack* track1 = album->addTrack(":/tracks/jaguar.wav");
    createPlaylistItem(track1);
    AlbumTrack* track2 = album->addTrack(":/tracks/wave.mp3");
    createPlaylistItem(track2);
    AlbumTrack* track3 = album->addTrack(":/tracks/stereo.ogg");
    createPlaylistItem(track3);
    */
}


void PlaylistControllerViewList::initDragArea(QGraphicsScene* areaParent)
{
    dragArea = new DragArea();
    dragArea->setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    dragArea->setAutoFillBackground(false);
    dragArea->setGeometry(pos().x(), pos().y(), getWidth(), getHeight());
    areaParent->addWidget(dragArea);
    connect(dragArea, SIGNAL(dragAccepted(QString)), this, SLOT(handleDragObject(QString)));
}


void PlaylistControllerViewList::handleDragObject(QString path)
{
    qDebug() << "PlaylistControllerViewList::handleDragObject() " << path;

    QRegExp rx("(?:\\.wav|\\.mp3|\\.ogg)");
    rx.setCaseSensitivity(Qt::CaseInsensitive);

    bool isMusicFile = path.indexOf(rx) != -1;

    if (isMusicFile)
    {
        Album* album = new Album(path);
        AlbumTrack* track = album->addTrack(path);
        createPlaylistItem(track);
    }
    else
        qDebug() << "The file isn't a valid musicfile.";
}


void PlaylistControllerViewList::createPlaylistItem(AlbumTrack* track)
{
    PlaylistItem* item = this->pc->addToPlaylist(track);
    item->setParentItem(this);
    item->setPos(0, item->getHeight() * (this->pc->getPlayListLength() - 1));
    item->init();
}


void PlaylistControllerViewList::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawRect(boundingRect());
}
