#ifndef EXPLORER_VIEW_HPP
#define EXPLORER_VIEW_HPP


#include <QTreeWidget>
#include <QHeaderView>

#include "AlbumTrack.hpp"
#include "PlaylistController.hpp"


class ExplorerView : public QTreeWidget
{
public:

    Q_OBJECT

public:
    ExplorerView(QWidget* parent = 0);
    void init();
    void addItem(AlbumTrack* track);

private:

public slots:
    void myDoubleClicked(QTreeWidgetItem* item, int col);

signals:
    void playItem(int index);

};

#endif // EXPLORER_VIEW_HPP
