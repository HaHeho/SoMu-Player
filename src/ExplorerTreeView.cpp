#include "ExplorerTreeView.hpp"


ExplorerTreeView::ExplorerTreeView(QWidget* parent)
    : QTreeWidget(parent)
{
}

void ExplorerTreeView::init()
{
    this->setColumnCount(2);
    this->setHeaderHidden(true);
    this->setAnimated(true);
    this->setMinimumWidth(200);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->header()->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->header()->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    this->header()->setResizeMode(0, QHeaderView::ResizeToContents);
    this->header()->setStretchLastSection(false);

    this->categoryTitles = new QTreeWidgetItem(QStringList("Titel"));
    this->addTopLevelItem(this->categoryTitles);
    this->categoryAlbums = new QTreeWidgetItem(QStringList("Alben"));
    this->addTopLevelItem(this->categoryAlbums);
    this->categoryArtists = new QTreeWidgetItem(QStringList("Künstler"));
    this->addTopLevelItem(this->categoryArtists);
    this->categoryGenres = new QTreeWidgetItem(QStringList("Genres"));
    this->addTopLevelItem(this->categoryGenres);
}

void ExplorerTreeView::sort()
{
    this->categoryTitles->sortChildren(0, Qt::AscendingOrder);
    this->categoryAlbums->sortChildren(0, Qt::AscendingOrder);
    this->categoryArtists->sortChildren(0, Qt::AscendingOrder);
    this->categoryGenres->sortChildren(0, Qt::AscendingOrder);
}

void ExplorerTreeView::myDoubleClicked(QTreeWidgetItem* item, int /*col*/)
{
    // 2nd column ist number of index
    emit showAlbum(item->text(1).toInt());
}

void ExplorerTreeView::addItem(AlbumTrack* track)
{
    QString title = track->getTitle();
    addElement(this->categoryTitles, title);
    QString albumName = track->getAlbumName();
    addElement(this->categoryAlbums, albumName);
    QString artist = track->getArtist();
    addElementWithChild(this->categoryArtists, artist, albumName);
    QString genre = track->getGenre();
    addElementWithChild(this->categoryGenres, genre, albumName);
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
    {
        QTreeWidgetItem* item = new QTreeWidgetItem(QStringList(element));
        parent->addChild(item);

        connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),
                this, SLOT(myDoubleClicked(QTreeWidgetItem*,int)), Qt::UniqueConnection);
    }
}

void ExplorerTreeView::addElementWithChild(QTreeWidgetItem* parent, QString& element, QString& child)
{
    // if element doesn't exist ... new one is created
    int index = checkIfElementExists(parent, element);
    if (index < 0)
    {
        parent->addChild(new QTreeWidgetItem(QStringList(element)));
        index = 0;
    }

    addElement(parent->child(index), child);
}
