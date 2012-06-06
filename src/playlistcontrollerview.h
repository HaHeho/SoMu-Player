#ifndef PLAYLISTCONTROLLERVIEW_H
#define PLAYLISTCONTROLLERVIEW_H


#include <QLabel>
#include "src/basicitem.h"
#include "src/playlistcontroller.h"
#include "src/dragarea.h"


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

#endif // PLAYLISTCONTROLLERVIEW_H
