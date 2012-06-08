#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include "BasicItem.hpp"


class Button : public BasicItem
{
    Q_OBJECT

public:
    explicit Button(float w, float h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void init();
    void setNormalImage(std::string path);
    void setRolloverImage(std::string path);


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);


private:
    QPixmap normalImage;
    QPixmap rolloverImage;
    bool mouseOver;


signals:
    void clicked();


public slots:


};

#endif // BUTTON_HPP
