#include <QtGui>
#include "src/playlistitem.h"
#include "api/inc/fmod.hpp"


PlayListItem::PlayListItem(FMOD::Sound* sound, float w, float h) : BasicItem(w, h)
{
    this->sound = sound;
    this->color = QColor(230, 100, 20);
}


void PlayListItem::init()
{
    //get Name of the Song
    QRegExp rx("\\..*");
    char name[100];
    sound->getName(name, 100);
    QString strName = QString(name);
    strName.remove(rx);


    //create Textfield for the Name
    titleText = new QGraphicsTextItem(this);
    titleText->setPlainText(strName);


    //calculate Duration
    unsigned int duration;
    sound->getLength(&duration, FMOD_TIMEUNIT_MS);
    QTime displayTime(0, (duration / 60000) % 60, (duration / 1000) % 60);


    //create Textfield for duration
    durationText = new QGraphicsTextItem(this);
    durationText->setTextWidth(getWidth());
    durationText->setPlainText(displayTime.toString("m:ss"));


    //set Alignment
    QTextCursor cursor = durationText->textCursor();
    QTextBlockFormat bfmt = cursor.blockFormat();
    bfmt.setAlignment(Qt::AlignRight);
    cursor.setBlockFormat(bfmt);
    durationText->setTextCursor(cursor);
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
    return this->sound;
}
