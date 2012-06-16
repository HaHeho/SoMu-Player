#include "PlaylistItem.hpp"


PlaylistItem::PlaylistItem(AlbumTrack* track, float w, float h) : BasicItem(w, h)
{
    this->status = this->FUTURE;
    this->colorNow = QColor(100, 230, 20);
    this->colorPast = QColor(230, 230, 230);
    this->color = QColor(230, 100, 20);

    this->track = track;

    //create Textfield for the Name
    this->titleText = new QGraphicsTextItem(this);
    this->titleText->setPlainText(this->track->getTitle());

    //create Textfield for duration
    unsigned int duration = this->track->getDuration();
    QTime displayTime(0, (duration / 60000) % 60, (duration / 1000) % 60);
    this->durationText = new QGraphicsTextItem(this);
    this->durationText->setTextWidth(getWidth());
    this->durationText->setPlainText(displayTime.toString("m:ss"));

    //set Alignment
    QTextCursor cursor = this->durationText->textCursor();
    QTextBlockFormat bfmt = cursor.blockFormat();
    bfmt.setAlignment(Qt::AlignRight);
    cursor.setBlockFormat(bfmt);
    this->durationText->setTextCursor(cursor);
}

void PlaylistItem::init()
{
}

void PlaylistItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));

    QColor c;
    if (this->status == this->PAST)
        c = this->colorPast;
    else if (this->status == this->NOW)
        c = this->colorNow;
    else if (this->status == this->FUTURE)
        c = this->color;
    painter->setBrush(QBrush(c));
    painter->drawRect(boundingRect());
}

void PlaylistItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
    Q_UNUSED (event);
    emit doubleClicked(this);
}

void PlaylistItem::emitDoubleClicked()
{
    emit doubleClicked(this);
}

FMOD::Sound* PlaylistItem::getSound()
{
    return this->track->getSound();
}

QPixmap* PlaylistItem::getCoverImage()
{
    return this->track->getCoverImage();
}

void PlaylistItem::setStatus(Status newStatus)
{
    this->status = newStatus;
}
