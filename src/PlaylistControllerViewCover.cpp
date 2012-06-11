#include "PlaylistControllerViewCover.hpp"


PlaylistControllerViewCover::PlaylistControllerViewCover(PlaylistController* pc, float w, float h) : BasicItem(w, h)
{
    this->pc = pc;
    connect(pc, SIGNAL(setPlaylistCover(QPixmap*)), this, SLOT(setImage(QImage*));
}

void PlaylistControllerViewCover::init()
{
}

void PlaylistControllerViewCover::setImage(QImage* image)
{
    this->image = image;
}

void PlaylistControllerViewCover::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    if (!this->image.isNull())
    {
        painter->drawPixmap(boundingRect(), this->image, boundingRect());
    }
    else
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);
        painter->setPen(QPen(Qt::black, 1));
        painter->setBrush(QBrush(color));
        painter->drawRect(boundingRect());
    }
}
