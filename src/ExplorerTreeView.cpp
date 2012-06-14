#include "ExplorerTreeView.hpp"


ExplorerTreeView::ExplorerTreeView(QWidget* parent)
    : QTreeWidget(parent)
{
}

void ExplorerTreeView::init()
{
    this->setColumnCount(1);
    this->setHeaderHidden(true);
    this->setAnimated(true);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->header()->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->header()->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    this->header()->setResizeMode(0, QHeaderView::ResizeToContents);
    this->header()->setStretchLastSection(false);

    this->categoryTitles = new QTreeWidgetItem(QStringList("Titel"));
    this->addTopLevelItem(categoryTitles);
    this->categoryAlbums = new QTreeWidgetItem(QStringList("Alben"));
    this->addTopLevelItem(categoryAlbums);
    this->categoryArtists = new QTreeWidgetItem(QStringList("Künstler"));
    this->addTopLevelItem(categoryArtists);
    this->categoryGenres = new QTreeWidgetItem(QStringList("Genres"));
    this->addTopLevelItem(categoryGenres);
}

void ExplorerTreeView::sort()
{
    this->categoryTitles->sortChildren(0, Qt::AscendingOrder);
    this->categoryAlbums->sortChildren(0, Qt::AscendingOrder);
    this->categoryArtists->sortChildren(0, Qt::AscendingOrder);
    this->categoryGenres->sortChildren(0, Qt::AscendingOrder);
}

void ExplorerTreeView::addItem(AlbumTrack* track)
{
    addTitle(track->getTitle());
    addAlbum(track->getAlbum()->getName());
    addArtist(track->getArtist());
    addGenre(track->getGenre());
    sort();
}

void ExplorerTreeView::addTitle(QString title)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(QStringList(title));
    categoryTitles->addChild(item);
}

void ExplorerTreeView::addAlbum(QString album)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(QStringList(album));
    categoryAlbums->addChild(item);
}

void ExplorerTreeView::addArtist(QString artist)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(QStringList(artist));
    categoryArtists->addChild(item);
}

void ExplorerTreeView::addGenre(QString genre)
{
    QTreeWidgetItem* item = new QTreeWidgetItem(QStringList(genre));
    categoryGenres->addChild(item);
}

