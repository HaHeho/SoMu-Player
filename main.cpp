#include <QtGui/QApplication>
#include "src/player.h"
#include "api/inc/fmod.hpp"
#include "api/inc/fmod_errors.h"
#include "common/wincompat.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene(0, 0, 800, 600);
    Player player(&scene);
    player.setRenderHint(QPainter::Antialiasing);
    player.setWindowTitle("SoMu-Player");
    player.show();
    
    return a.exec();
}
