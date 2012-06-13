#include "Player.hpp"


Player::Player(QGraphicsScene* pScene) : QGraphicsView(pScene)
{
    ss = new SoundSystem();

    pc = new PlaylistController(ss);

    sc = new SoundController(ss);
    sc->initPlaylistController(pc);

    scv = new SoundControllerView(sc, ss, 500, 60);
    scene()->addItem(scv);
    scv->setPos(150, 540);
    scv->init();

    pcvl = new PlaylistControllerViewList(pc, 150, 600);
    pcvl->setPos(650, 0);
    pcvl->initDragArea(scene());
    scene()->addItem(pcvl);
    pcvl->init();

    pcvc = new PlaylistControllerViewCover(150, 150);
    pcvc->setPos(0, 450);
    scene()->addItem(pcvc);
    pcvc->init();

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlayer()));
    timer->start(1000 / 60);

    connect(pc, SIGNAL(setPlaylistCover(QPixmap*)), pcvc, SLOT(setImage(QPixmap*)));
}


void Player::updatePlayer()
{
    scene()->update(0, 0, 800, 600);
    scv->updateView();
}
