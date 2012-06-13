#ifndef EXPLORER_VIEW_HPP
#define EXPLORER_VIEW_HPP


#include "BasicItem.hpp"


class ExplorerView : public BasicItem
{
public:

    Q_OBJECT

public:
    explicit ExplorerView(float w, float h);
    virtual void init();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

private:

public slots:

signals:

};

#endif // EXPLORER_VIEW_HPP
