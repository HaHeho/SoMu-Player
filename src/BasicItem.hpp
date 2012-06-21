#ifndef BASIC_ITEM_HPP
#define BASIC_ITEM_HPP

#include <QObject>
#include <QtGui>


class BasicItem : public QWidget
{
    Q_OBJECT

public:
    BasicItem(float w, float h);
    QRectF boundingRect() const;
    void setBackgroundColor(QColor color);
    virtual void init();
    float getHeight();
    float getWidth();
    QGroupBox* container;


protected:
    QColor color;
    float height;
    float width;

signals:

public slots:

};

#endif // BASIC_ITEM_HPP
