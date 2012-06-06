#ifndef PLAYLISTITEM_H
#define PLAYLISTITEM_H

#include <QtGui>
#include "src/basicitem.h"
#include "api/inc/fmod.hpp"


class PlayListItem : public BasicItem
{
    Q_OBJECT

public:
    explicit PlayListItem(FMOD::Sound* sound, float w, float h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void init();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    FMOD::Sound* getSound();

private:
    FMOD::Sound* sound;
    QGraphicsTextItem* titleText;
    QGraphicsTextItem* durationText;


signals:
    void doubleClicked(PlayListItem* item);


public slots:


};

#endif // PLAYLISTITEM_H
