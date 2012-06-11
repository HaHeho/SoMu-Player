#include "PlaylistControllerViewList.hpp"


PlaylistControllerViewList::PlaylistControllerViewList(PlaylistController* pc, float w, float h) : BasicItem(w, h)
{
    this->pc = pc;
}


void PlaylistControllerViewList::init()
{
    /*createPlaylistItem("media/jaguar.wav");
    createPlaylistItem("media/swish.wav");
    createPlaylistItem("media/drumloop.wav");*/
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
    qDebug() << "Got a new Drag! Path: " << path;

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
