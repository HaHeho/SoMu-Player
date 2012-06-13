#include "ExplorerController.hpp"


ExplorerController::ExplorerController(ExplorerView* view, ExplorerTreeView* treeView, QObject* parent) : QObject(parent)
{
    this->view = view;
    this->treeView = treeView;
}
