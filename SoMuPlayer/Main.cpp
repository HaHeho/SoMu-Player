#include <QtGui/QApplication>
#include "MainWindow.hpp"

int main(int argv, char **args)
{
    QApplication app(argv, args);
    app.setApplicationName("SoMuPlayer");
    app.setQuitOnLastWindowClosed(true);

    MainWindow window;
    window.showMaximized();
    //window.show();

    return app.exec();
}
