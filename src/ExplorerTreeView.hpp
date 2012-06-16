#ifndef EXPLORER_TREE_VIEW_HPP
#define EXPLORER_TREE_VIEW_HPP


#include <QTreeWidget>
#include <QHeaderView>

#include "AlbumTrack.hpp"


class ExplorerTreeView : public QTreeWidget
{
public:

    Q_OBJECT

public:
    explicit ExplorerTreeView(QWidget* parent = 0);
    void init();
    void addItem(AlbumTrack* track);

private:
    QTreeWidgetItem* categoryTitles;
    QTreeWidgetItem* categoryAlbums;
    QTreeWidgetItem* categoryArtists;
    QTreeWidgetItem* categoryGenres;

    void addElement(QTreeWidgetItem* parent, QString& element);
    void addElementWithChild(QTreeWidgetItem* parent, QString& element, QString& child);
    int checkIfElementExists(QTreeWidgetItem* parent, QString& element);
    void sort();

public slots:


signals:

};

#endif // EXPLORER_TREE_VIEW_HPP
