#ifndef BASICITEM_H
#define BASICITEM_H

#include <QGraphicsItem>


class BasicItem : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    BasicItem(float w, float h);
    QRectF boundingRect() const;
    void setBackgroundColor(QColor color);
    virtual void init();
    float getHeight();
    float getWidth();


protected:
    QColor color;
    float height;
    float width;

signals:


public slots:

};

#endif // BASICITEM_H
