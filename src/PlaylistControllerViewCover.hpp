#ifndef PLAYLIST_CONTROLLER_VIEW_COVER_HPP
#define PLAYLIST_CONTROLLER_VIEW_COVER_HPP


#include "BasicItem.hpp"
#include "PlaylistController.hpp"


class PlaylistControllerViewCover : public BasicItem
{
    Q_OBJECT

public:
    explicit PlaylistControllerViewCover(PlayListController *pc, float w, float h);
    virtual void init();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setImage(QImage* image);

private:
    PlayListController* playListController;
    QImage* image;
};

#endif // PLAYLIST_CONTROLLER_VIEW_COVER_HPP
