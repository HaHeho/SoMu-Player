#include "Player.hpp"


Player::Player(QGraphicsScene *pScene) : QGraphicsView(pScene)
{
    ss = new SoundSystem();

    sc = new SoundController(ss);

    scv = new SoundControllerView(sc, ss, 500, 60);
    scene()->addItem(scv);
    scv->setPos(100, 540);
    scv->init();

    pc = new PlayListController(ss);

    pcv = new PlaylistControllerView(pc, 200, 600);
    pcv->setPos(600, 0);
    pcv->initDragArea(scene());
    scene()->addItem(pcv);
    pcv->init();

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlayer()));
    timer->start(1000 / 60);
}


void Player::updatePlayer()
{
    scene()->update(0, 0, 800, 600);
    scv->updateView();
}
