#include "ExplorerView.hpp"


ExplorerView::ExplorerView(float w, float h) : BasicItem(w, h)
{
    setBackgroundColor(QColor(240, 240, 240));
}

void ExplorerView::init()
{
}

void ExplorerView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawRect(boundingRect());
}
