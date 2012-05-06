#ifndef MENU_HPP
#define MENU_HPP

#include <QMenu>
#include <QAction>
#include <QMessageBox>


class Menu : public MainWindow
{
    Q_OBJECT

    public:
        Menu();

    private slots:

    private:
        QMenu* fileMenu;
        QMenu* aboutMenu;

        QAction* addFilesAction;
        QAction* aboutAction;
        QAction* aboutQtAction;
        QAction* exitAction;

        void setup();
        void about();
};

#endif
