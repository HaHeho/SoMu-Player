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
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);


private:
    QPixmap normalImage;
    QPixmap rolloverImage;
    QLabel* background;
    bool mouseOver;


signals:
    void clicked();


public slots:


};

#endif // BUTTON_HPP
