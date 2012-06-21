#include "DragArea.hpp"


DragArea::DragArea() : QGroupBox()
{
    setAcceptDrops(true);
}


void DragArea::dragEnterEvent(QDragEnterEvent* event)
{
    event->acceptProposedAction();
}


void DragArea::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}


void DragArea::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls())
    {
        QList<QUrl> urlList = mimeData->urls();
        for (int i = 0; i < urlList.size(); i++)
        {
            QString url = urlList.at(i).toLocalFile();
            emit dragAccepted(url);
        }
    }
}


void DragArea::dragLeaveEvent(QDragLeaveEvent* event)
{
    event->accept();
}
