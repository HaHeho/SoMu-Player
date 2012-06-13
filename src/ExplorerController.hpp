#ifndef EXPLORER_CONTROLLER_HPP
#define EXPLORER_CONTROLLER_HPP


#include <QObject>

#include "ExplorerView.hpp"
#include "ExplorerTreeView.hpp"


class ExplorerController : public QObject
{

    Q_OBJECT

public:
    ExplorerController(ExplorerView* view, ExplorerTreeView* treeView, QObject* parent = 0);

private:
    ExplorerView*     view;
    ExplorerTreeView* treeView;

signals:

public slots:

};

#endif // EXPLORER_CONTROLLER_HPP
