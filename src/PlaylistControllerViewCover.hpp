#ifndef PLAYLIST_CONTROLLER_VIEW_COVER_HPP
#define PLAYLIST_CONTROLLER_VIEW_COVER_HPP


#include "BasicItem.hpp"
#include "PlaylistController.hpp"


class PlaylistControllerViewCover : public BasicItem
{
    Q_OBJECT

public:
    PlaylistControllerViewCover(PlaylistController* pc, float w, float h);
    virtual void init();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    PlaylistController* pc;
    QImage* image;

public slots:
    void setImage(QImage* image);

signals:

};

#endif // PLAYLIST_CONTROLLER_VIEW_COVER_HPP
