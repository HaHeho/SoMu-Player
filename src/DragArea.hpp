#ifndef DRAG_AREA_HPP
#define DRAG_AREA_HPP

#include <QtGui>
#include <QLabel>


class DragArea : public QGroupBox
{
    Q_OBJECT

public:
    DragArea();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);

signals:
    void dragAccepted(QString path);
};

#endif // DRAG_AREA_HPP
