#ifndef PLAYLIST_ITEM_HPP
#define PLAYLIST_ITEM_HPP


#include <QtGui>
#include "BasicItem.hpp"
#include "Album.hpp"


class PlaylistItem : public BasicItem
{
    Q_OBJECT

public:
    enum Status {PAST, NOW, FUTURE};

    explicit PlaylistItem(AlbumTrack* track, float w, float h);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void init();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
    void emitDoubleClicked();

    void setStatus(Status newStatus);

    FMOD::Sound* getSound();
    QPixmap*     getCoverImage();


private:
    Status             status;
    QColor             colorNow;
    QColor             colorPast;
    AlbumTrack*        track;
    QGraphicsTextItem* titleText;
    QGraphicsTextItem* durationText;

signals:
    void doubleClicked(PlaylistItem* item);

public slots:

};

#endif // PLAYLIST_ITEM_HPP
