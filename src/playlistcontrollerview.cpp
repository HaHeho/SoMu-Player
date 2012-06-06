#include <QtGui>
#include <QGraphicsRectItem>
#include "src/playlistcontrollerview.h"


PlaylistControllerView::PlaylistControllerView(PlayListController *pc, float w, float h) : BasicItem(w, h)
{
    this->playListController = pc;
}


void PlaylistControllerView::init()
{
    /*createPlayListItem("media/jaguar.wav");
    createPlayListItem("media/swish.wav");
    createPlayListItem("media/drumloop.wav");*/
}


void PlaylistControllerView::initDragArea(QGraphicsScene* areaParent)
{
    dragArea = new DragArea();
    dragArea->setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    dragArea->setAutoFillBackground(false);
    dragArea->setGeometry(pos().x(), pos().y(), getWidth(), getHeight());
    areaParent->addWidget(dragArea);
    connect(dragArea, SIGNAL(dragAccepted(QString)), this, SLOT(handleDragObject(QString)));
}


void PlaylistControllerView::handleDragObject(QString path)
{
    qDebug() << "Got a new Drag! Path: " << path;

    QRegExp rx("(?:\\.wav|\\.mp3|\\.ogg)");
    rx.setCaseSensitivity(Qt::CaseInsensitive);

    bool isMusicFile = path.indexOf(rx) != -1;

    if (isMusicFile)
        createPlayListItem(path);
    else
        qDebug() << "The File isnt a valid Musicfile.";
}


void PlaylistControllerView::createPlayListItem(QString soundPath)
{
    PlayListItem* item = playListController->addToPlaylist(soundPath);
    item->setParentItem(this);
    item->setPos(0, item->getHeight() * (playListController->getPlayListLength()-1));
    item->init();
}


void PlaylistControllerView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawRect(boundingRect());
}
