#ifndef PLAYLIST_CONTROLLER_VIEW_LIST_HPP
#define PLAYLIST_CONTROLLER_VIEW_LIST_HPP


#include <QLabel>
#include <QGraphicsRectItem>
#include "BasicItem.hpp"
#include "PlaylistController.hpp"
#include "DragArea.hpp"
#include "Album.hpp"


class PlaylistControllerViewList : public BasicItem
{
    Q_OBJECT

public:
    explicit PlaylistControllerViewList(PlayListController *pc, float w, float h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void init();
    void initDragArea(QGraphicsScene* areaParent);

private:
    PlayListController* playListController;
    void createPlayListItem(AlbumTrack* track);
    DragArea* dragArea;

signals:

public slots:
    void handleDragObject(QString path);
};

#endif // PLAYLIST_CONTROLLER_VIEW_LIST_HPP
