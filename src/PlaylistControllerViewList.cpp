#include "PlaylistControllerViewList.hpp"


PlaylistControllerViewList::PlaylistControllerViewList(float w, float h)
    : BasicItem(w, h)
{
    setBackgroundColor(QColor(200, 200, 200));
}

void PlaylistControllerViewList::initDragArea(QGraphicsScene* areaParent)
{
    dragArea = new DragArea();
    dragArea->setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    dragArea->setAutoFillBackground(false);
    dragArea->setGeometry(pos().x(), pos().y(), getWidth(), getHeight());
    areaParent->addWidget(dragArea);

    connect(dragArea, SIGNAL(dragAccepted(QString)),
            this, SLOT(handleDragObject(QString)), Qt::DirectConnection);
}


void PlaylistControllerViewList::handleDragObject(QString path)
{
    qDebug() << "PlaylistControllerViewList::handleDragObject() " << path;

    QRegExp rx("(?:\\.wav|\\.mp3|\\.ogg)");
    rx.setCaseSensitivity(Qt::CaseInsensitive);

    bool isMusicFile = path.indexOf(rx) != -1;

    if (isMusicFile)
        emit delegateDraggedObject(path);
    else
        qDebug() << "The file isn't a valid musicfile.";
}

void PlaylistControllerViewList::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawRect(boundingRect());
}

void PlaylistControllerViewList::init()
{
}
