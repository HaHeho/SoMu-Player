#include "PlaylistControllerViewList.hpp"
#include "Button.hpp"


PlaylistControllerViewList::PlaylistControllerViewList(float w, float h) : BasicItem(w, h)
{
    setBackgroundColor(QColor(200, 200, 200));
}


void PlaylistControllerViewList::init()
{
    DragArea* dragArea = new DragArea();
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignTop);
    layout->setSpacing(1);

    dragArea->setLayout(layout);
    dragArea->setAutoFillBackground(true);
    dragArea->setStyleSheet( "margin: 1px; background-color: rgb( 71, 71, 71)" );

    connect(dragArea, SIGNAL(dragAccepted(QString)), this, SLOT(handleDragObject(QString)));
    container = dragArea;
}


void PlaylistControllerViewList::handleDragObject(QString path)
{
    qDebug() << "PlaylistControllerViewList::handleDragObject() " << path;

    QRegExp rx("(?:\\.mp3|\\.wav|\\.wma|\\.ogg|\\.flac)");
    rx.setCaseSensitivity(Qt::CaseInsensitive);

    bool isMusicFile = path.indexOf(rx) != -1;

    if (isMusicFile)
        emit delegateDraggedObject(path);
    else
        qDebug() << "The file isn't a valid musicfile.";
}


void PlaylistControllerViewList::showItem(PlaylistItem* item)
{
    this->container->layout()->addWidget(item);
}
