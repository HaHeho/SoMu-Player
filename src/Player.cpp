#include "Player.hpp"


Player::Player(QGraphicsScene* qScene) : QGraphicsView(qScene)
{
    this->scene = qScene;
    scene->setParent(this);

    ss = new SoundSystem();

    pc = new PlaylistController(ss);

    sc = new SoundController(ss);
    sc->initPlaylistController(pc);

    scv = new SoundControllerView(sc, ss, 650, 60);
    scene->addItem(scv);
    scv->setPos(150, 540);
    scv->init();

    // Reihenfolge der Funktionsaufrufe IST WICHTIG !!!
    pcvl = new PlaylistControllerViewList(pc, 150, 540);
    pcvl->setPos(650, 0);
    pcvl->initDragArea(scene);
    scene->addItem(pcvl);
    pcvl->init();
    // keine Ahnung warum

    pcvc = new PlaylistControllerViewCover(150, 150);
    scene->addItem(pcvc);
    pcvc->setPos(0, 450);
    pcvc->init();

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlayer()));
    timer->start(1000 / 60);

    connect(pc, SIGNAL(setPlaylistCover(QPixmap*)), pcvc, SLOT(setImage(QPixmap*)));

    ev = new ExplorerView(500, 540);
    scene->addItem(ev);
    ev->setPos(150, 0);
    ev->init();

    etv = new ExplorerTreeView(this);
    etv->setGeometry(0, 0, 150, 450);
    etv->init();

    ec = new ExplorerController(ss, ev, etv);
    ec->init();
}


void Player::updatePlayer()
{
    scene->update(0, 0, 800, 600);
    scv->updateView();
}
