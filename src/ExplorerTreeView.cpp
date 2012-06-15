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
    QString album = track->getAlbum()->getName();
    addElement(this->categoryTitles, track->getTitle());
    addElement(this->categoryAlbums, album);
    addElementWithChild(this->categoryArtists, track->getArtist(), album);
    addElementWithChild(this->categoryGenres, track->getGenre(), album);
    //sort();
}

int ExplorerTreeView::checkIfElementExists(QTreeWidgetItem* parent, QString& element)
{
    for (int i = 0; i < parent->childCount(); i++)
    {
        if (parent->child(i)->text(0) == element)
            return i;
    }
    return -1;
}

void ExplorerTreeView::addElement(QTreeWidgetItem* parent, QString& element)
{
    if (checkIfElementExists(parent, element) < 0)
        parent->addChild(new QTreeWidgetItem(QStringList(element)));
}

void ExplorerTreeView::addElementWithChild(QTreeWidgetItem* parent, QString& element, QString& child)
{
    int index = checkIfElementExists(parent, element);
    if (index < 0)
    {
        parent->addChild(new QTreeWidgetItem(QStringList(element)));
        index = 0;
    }

    addElement(parent->child(index), child);
}
