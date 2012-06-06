#include <QtGui>
#include "src/dragarea.h"


DragArea::DragArea(QWidget *parent) : QLabel(parent)
{
    setAcceptDrops(true);
}


void DragArea::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug("enter");

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

    /*
    const QMimeData *mimeData = event->mimeData();

    if (mimeData->hasImage()) {
        setPixmap(qvariant_cast<QPixmap>(mimeData->imageData()));
    } else if (mimeData->hasHtml()) {
        setText(mimeData->html());
        setTextFormat(Qt::RichText);
    } else if (mimeData->hasText()) {
        setText(mimeData->text());
        setTextFormat(Qt::PlainText);
    } else if (mimeData->hasUrls()) {
        QList<QUrl> urlList = mimeData->urls();
        QString text;
        for (int i = 0; i < urlList.size() && i < 32; ++i) {
            QString url = urlList.at(i).path();
            text += url + QString("\n");
        }
        setText(text);
    } else {
        setText(tr("Cannot display data"));
    }
    */
    event->acceptProposedAction();
}


void DragArea::dragLeaveEvent(QDragLeaveEvent *event)
{
    qDebug("leave");

    event->accept();
}
