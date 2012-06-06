#ifndef DRAGAREA_H
#define DRAGAREA_H

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


signals:
    void dragAccepted(QString path);


protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // DRAGAREA_H
