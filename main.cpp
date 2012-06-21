#include <QtGui/QApplication>
#include <QtGui/QGraphicsScene>
#include "common/wincompat.h"
#include "src/Player.hpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Player player;
    player.setWindowTitle("SoMu-Player");
    player.show();
    
    return a.exec();
}
