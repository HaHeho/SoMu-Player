#include "PlaylistControllerViewCover.hpp"


PlaylistControllerViewCover::PlaylistControllerViewCover(PlayListController *pc, float w, float h) : BasicItem(w, h)
{
    this->playListController = pc;
}

void PlaylistControllerViewCover::init()
{
}

void PlaylistControllerViewCover::setImage(QImage* image)
{
    this->image = image;
}

void PlaylistControllerViewCover::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawRect(boundingRect());
}
