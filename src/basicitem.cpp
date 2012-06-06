#include <QtGui>
#include "src/basicitem.h"

BasicItem::BasicItem(float w, float h)
{
    color = QColor(100, 100, 100);
    width = w;
    height = h;
}


void BasicItem::setBackgroundColor(QColor bgColor)
{
    color = bgColor;
}


QRectF BasicItem::boundingRect() const
{
    return QRectF(0,0,width,height);
}


void BasicItem::init()
{

}


float BasicItem::getHeight()
{
    return height;
}


float BasicItem::getWidth()
{
    return width;
}
