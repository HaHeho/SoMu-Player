#ifndef PLAYLIST_CONTROLLER_VIEW_LIST_HPP
#define PLAYLIST_CONTROLLER_VIEW_LIST_HPP


#include <QLabel>
#include <QGraphicsRectItem>
#include "BasicItem.hpp"
#include "DragArea.hpp"
#include "PlaylistItem.hpp"
#include "Album.hpp"


class PlaylistControllerViewList : public BasicItem
{
    Q_OBJECT

public:
    explicit PlaylistControllerViewList(float w, float h);
    void init();
    void showItem(PlaylistItem* item);

signals:
    void delegateDraggedObject(QString path);

public slots:
    void handleDragObject(QString path);
};

#endif // PLAYLIST_CONTROLLER_VIEW_LIST_HPP
