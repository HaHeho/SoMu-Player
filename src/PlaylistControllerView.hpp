#ifndef PLAYLIST_CONTROLLER_VIEW_HPP
#define PLAYLIST_CONTROLLER_VIEW_HPP


#include <QLabel>
#include <QtGui>
#include <QGraphicsRectItem>
#include "BasicItem.hpp"
#include "PlaylistController.hpp"
#include "DragArea.hpp"


class PlaylistControllerView : public BasicItem
{
    Q_OBJECT


public:
    explicit PlaylistControllerView(PlayListController *pc, float w, float h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void init();
    void initDragArea(QGraphicsScene* areaParent);


private:
    PlayListController *playListController;
    void createPlayListItem(QString soundPath);
    DragArea* dragArea;

signals:

public slots:
    void handleDragObject(QString path);
};

#endif // PLAYLIST_CONTROLLER_VIEW_HPP
