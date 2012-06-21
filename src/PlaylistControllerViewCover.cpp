#include "PlaylistControllerViewCover.hpp"


PlaylistControllerViewCover::PlaylistControllerViewCover(float w, float h) : BasicItem(w, h)
{
}

void PlaylistControllerViewCover::init()
{
    container = new QGroupBox();
    QVBoxLayout* layout = new QVBoxLayout();

    container->setLayout(layout);
    container->setAutoFillBackground(true);
    container->setStyleSheet( "background-color: rgb( 220,120,100 )" );

    this->label = new QLabel(this);

    this->setImage(":/albums/no-cover");
}

void PlaylistControllerViewCover::setImage(QString path)
{
    QFileInfo fi(path);
    if (!fi.exists())
    {
        qDebug() << "The file " << path << " doesnt exists anymore.";
        return;
    }

    QImage image = QImage(path);
    label->setPixmap(QPixmap::fromImage(image.scaled(200,200,Qt::KeepAspectRatio,Qt::FastTransformation)));
    this->setMinimumSize(200, 200);
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
