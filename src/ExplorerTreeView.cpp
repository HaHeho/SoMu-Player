#include "ExplorerTreeView.hpp"


ExplorerTreeView::ExplorerTreeView(float w, float h) : BasicItem(w, h)
{
    setBackgroundColor(QColor(200, 200, 200));
}

void ExplorerTreeView::init()
{
}

void ExplorerTreeView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawRect(boundingRect());
}
