#include "PlayListItem.hpp"


PlayListItem::PlayListItem(AlbumTrack* track, float w, float h) : BasicItem(w, h)
{
    this->track = track;
    this->color = QColor(230, 100, 20);

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

void PlayListItem::init()
{
}

void PlayListItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawRect(boundingRect());
}

void PlayListItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED (event);
    emit doubleClicked(this);
}

FMOD::Sound* PlayListItem::getSound()
{
    return this->track->getSound();
}
