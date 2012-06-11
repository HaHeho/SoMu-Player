#ifndef PLAYLIST_ITEM_HPP
#define PLAYLIST_ITEM_HPP


#include <QtGui>
#include "BasicItem.hpp"
//#include "AlbumTrack.hpp"
#include "Album.hpp"


class PlayListItem : public BasicItem
{
    Q_OBJECT

public:
    explicit PlayListItem(AlbumTrack* track, float w, float h);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void init();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    FMOD::Sound* getSound();

private:
    AlbumTrack* track;
    QGraphicsTextItem* titleText;
    QGraphicsTextItem* durationText;

signals:
    void doubleClicked(PlayListItem* item);

public slots:

};

#endif // PLAYLIST_ITEM_HPP
