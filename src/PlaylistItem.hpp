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

    explicit PlaylistItem(AlbumTrack* track, int index);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void init();
    void mouseDoubleClickEvent(QMouseEvent* event);
    void emitDoubleClicked();
    void setStatus(Status newStatus);
    void actBackgroundColor();
    FMOD::Sound* getSound();
    AlbumTrack* getTrack();


private:
    Status          status;
    QColor          colorNow;
    QColor          colorPast;
    AlbumTrack*     track;
    QLabel*         titleText;
    QLabel*         durationText;
    int             playlistIndex;

signals:
    void doubleClicked(PlaylistItem* item);

public slots:

};

#endif // PLAYLIST_ITEM_HPP
