#ifndef PLAYLIST_CONTROLLER_VIEW_COVER_HPP
#define PLAYLIST_CONTROLLER_VIEW_COVER_HPP


#include "BasicItem.hpp"


class PlaylistControllerViewCover : public BasicItem
{
    Q_OBJECT

public:
    explicit PlaylistControllerViewCover(float w, float h);
    virtual void init();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:
    QPixmap* image;

public slots:
    void setImage(QPixmap* image);

signals:

};

#endif // PLAYLIST_CONTROLLER_VIEW_COVER_HPP
