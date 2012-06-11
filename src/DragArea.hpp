#ifndef DRAG_AREA_HPP
#define DRAG_AREA_HPP

#include <QtGui>
#include <QLabel>


QT_BEGIN_NAMESPACE
class QMimeData;
QT_END_NAMESPACE



class DragArea : public QLabel
{
    Q_OBJECT

public:
    DragArea(QWidget *parent = 0);

private:
    QLabel *label;

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);

signals:
    void dragAccepted(QString path);
};

#endif // DRAG_AREA_HPP
