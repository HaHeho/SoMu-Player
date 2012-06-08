#include <QtGui/QApplication>
#include "Player.hpp"


int main(int argc, char *argv[])
{
    qDebug();
    QApplication a(argc, argv);

    QGraphicsScene scene(10, 10, 800, 600);
    Player player(&scene);
    player.setRenderHint(QPainter::Antialiasing);
    player.setWindowTitle("SoMu-Player");
    player.show();

    return a.exec();
}
