#ifndef BASIC_ITEM_HPP
#define BASIC_ITEM_HPP


#include <QObject>
#include <QtGui>
#include <QGraphicsItem>


class BasicItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

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

#endif // BASIC_ITEM_HPP
