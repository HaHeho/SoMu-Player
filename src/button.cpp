#include "Button.hpp"


Button::Button(float w, float h) : BasicItem(w, h)
{
    mouseOver = false;
}


void Button::init()
{
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::LeftButton);
}


void Button::setNormalImage(std::string path)
{
    QString str(path.c_str());
    normalImage = QPixmap(str);
}


void Button::setRolloverImage(std::string path)
{
    QString str(path.c_str());
    rolloverImage = QPixmap(str);
}


void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (!normalImage.isNull())
    {
        QRectF rect = boundingRect();
        if (!mouseOver || (mouseOver && rolloverImage.isNull()))
        {
            painter->drawPixmap(rect, normalImage, rect);
        }
        else
        {
            painter->drawPixmap(rect, rolloverImage, rect);
        }
    }
    else
    {
        Q_UNUSED(option);
        Q_UNUSED(widget);
        painter->setPen(QPen(Qt::black, 1));
        painter->setBrush(QBrush(color));
        painter->drawRect(boundingRect());
    }
}


void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
}


void Button::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);

    if (mouseOver)
    {
        emit clicked();
    }
}


void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    mouseOver = true;
}


void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    mouseOver = false;
}
