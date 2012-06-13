#ifndef EXPLORER_TREE_VIEW_HPP
#define EXPLORER_TREE_VIEW_HPP


#include "BasicItem.hpp"


class ExplorerTreeView : public BasicItem
{
public:

    Q_OBJECT

public:
    explicit ExplorerTreeView(float w, float h);
    virtual void init();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:

public slots:

signals:

};

#endif // EXPLORER_TREE_VIEW_HPP
