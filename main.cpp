#include <QtGui/QApplication>
#include "Player.hpp"


int main(int argc, char *argv[])
{
    qDebug();
    QApplication a(argc, argv);

    QGraphicsScene* scene = new QGraphicsScene(0, 0, 800, 600);

    Player* player = new Player(scene);
    player->setRenderHint(QPainter::Antialiasing);
    player->setWindowTitle("SoMu-Player");
    player->fitInView(0, 0, 800, 600);
    player->show();

    return a.exec();
}
