#include "ExplorerView.hpp"


ExplorerView::ExplorerView(QWidget* parent)
    : QTreeWidget(parent)
{
}

void ExplorerView::init()
{
    this->setAnimated(true);
    this->setSortingEnabled(true);

    QStringList header;
    header << "#" << "Titel" << "Interpret" << "Album" << "Genre" << "Länge" << "~index";
    this->setHeaderLabels(header);
    this->header()->setResizeMode(0, QHeaderView::ResizeToContents); // Number
    this->header()->setResizeMode(4, QHeaderView::ResizeToContents); // Genre
    this->header()->setResizeMode(5, QHeaderView::ResizeToContents); // Duration
    this->header()->setDefaultAlignment(Qt::AlignHCenter);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->header()->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->header()->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    this->header()->setStretchLastSection(false);
}

void ExplorerView::addItem(AlbumTrack* track)
{
    QStringList trackInfo;
    trackInfo << QString::number(track->getNumber()) << track->getTitle() << track->getArtist() << track->getAlbumName() << track->getGenre() << track->getDurationAsString() << QString::number(track->getLibraryIndex());

    QTreeWidgetItem* item = new QTreeWidgetItem(trackInfo);
    item->setTextAlignment(0, Qt::AlignRight);   // Number
    item->setTextAlignment(4, Qt::AlignHCenter); // Genre
    item->setTextAlignment(5, Qt::AlignRight);   // Duration
    this->addTopLevelItem(item);

    connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),
            this, SLOT(myDoubleClicked(QTreeWidgetItem*,int)), Qt::UniqueConnection);
}

void ExplorerView::myDoubleClicked(QTreeWidgetItem* item, int /*col*/)
{
    // 6th column ist number of index
    emit playItem(item->text(6).toInt());
}
