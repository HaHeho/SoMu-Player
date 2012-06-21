#include "Button.hpp"


Button::Button(float w, float h) : BasicItem(w, h)
{
    this->mouseOver = false;
}


void Button::init()
{
    background = new QLabel(this);
}


void Button::setNormalImage(std::string path)
{
    QString str(path.c_str());
    normalImage = QPixmap(str);

    background->setPixmap(normalImage);
    this->setMinimumSize(normalImage.width(), normalImage.height());
    this->setMaximumSize(normalImage.width(), normalImage.height());
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


void Button::mousePressEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
}


void Button::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);

    if (mouseOver)
    {
        emit clicked();
    }
}


void Button::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    mouseOver = true;
    background->setPixmap(rolloverImage);
}


void Button::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    mouseOver = false;
    background->setPixmap(normalImage);
}
