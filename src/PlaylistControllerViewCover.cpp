#include "PlaylistControllerViewCover.hpp"


PlaylistControllerViewCover::PlaylistControllerViewCover(float w, float h) : BasicItem(w, h)
{
    //setImage(new QPixmap(":/albums/no-cover"));
    this->image = new QPixmap();
}

void PlaylistControllerViewCover::init()
{
}

void PlaylistControllerViewCover::setImage(QPixmap* image)
{
    qDebug() << "PlaylistControllerViewCover::setImage()";
    this->image = new QPixmap(image->scaledToWidth(this->width));
}

void PlaylistControllerViewCover::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    if (!(this->image)->isNull())
    {
        painter->drawPixmap(boundingRect(), *(this->image), boundingRect());
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
