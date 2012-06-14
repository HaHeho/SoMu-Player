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
    QList<QString*> listedArtists;
    QList<QString*> listedGenres;

    QTreeWidgetItem* categoryTitles;
    QTreeWidgetItem* categoryAlbums;
    QTreeWidgetItem* categoryArtists;
    QTreeWidgetItem* categoryGenres;

    void addTitle(QString title);
    void addAlbum(QString album);
    void addArtist(QString artist);
    void addGenre(QString genre);

    void sort();

public slots:

signals:

};

#endif // EXPLORER_TREE_VIEW_HPP
