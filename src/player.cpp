#include "Player.hpp"


Player::Player(QGraphicsScene *pScene) : QGraphicsView(pScene)
{
    ss = new SoundSystem();

    sc = new SoundController(ss);

    scv = new SoundControllerView(sc, ss, 500, 60);
    scene()->addItem(scv);
    scv->setPos(150, 540);
    scv->init();

    pc = new PlayListController(ss);

    pcvl = new PlaylistControllerViewList(pc, 150, 600);
    pcvl->setPos(650, 0);
    pcvl->initDragArea(scene());
    scene()->addItem(pcvl);
    pcvl->init();

    pcvc = new PlaylistControllerViewCover(pc, 150, 150);
    pcvc->setPos(0, 450);
    scene()->addItem(pcvc);
    pcvc->init();

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlayer()));
    timer->start(1000 / 60);
}


void Player::updatePlayer()
{
    scene()->update(0, 0, 800, 600);
    scv->updateView();
}
