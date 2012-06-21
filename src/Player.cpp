#include "Player.hpp"


Player::Player(QWidget *parent) : QMainWindow(parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout();
    QWidget* main = new QWidget(this);
    main->setLayout(mainLayout);
    this->setCentralWidget(main);

    QGroupBox* left = new QGroupBox();
    mainLayout->addWidget(left);
    QVBoxLayout* leftLayout = new QVBoxLayout();
    left->setLayout(leftLayout);
    left->setMaximumWidth(220);

    QGroupBox* center = new QGroupBox();
    mainLayout->addWidget(center);
    QVBoxLayout* centerLayout = new QVBoxLayout();
    center->setLayout(centerLayout);

    QGroupBox* right = new QGroupBox();
    mainLayout->addWidget(right);
    QVBoxLayout* rightLayout = new QVBoxLayout();
    right->setLayout(rightLayout);


    ss = new SoundSystem();

    ev = new ExplorerView(this);
    ev->init();
    centerLayout->addWidget(ev);

    etv = new ExplorerTreeView(this);
    etv->init();
    leftLayout->addWidget(etv);

    pcvl = new PlaylistControllerViewList(150, 540);
    pcvl->init();
    rightLayout->addWidget(pcvl->container);

    pcvc = new PlaylistControllerViewCover(150, 150);
    pcvc->init();
    leftLayout->addWidget(pcvc);

    pc = new PlaylistController(pcvl, ss);
    pc->init();

    sc = new SoundController(ss);
    sc->initPlaylistController(pc);

    scv = new SoundControllerView(sc, ss, 10, 60);
    scv->init();
    centerLayout->addWidget(scv->container);

    ec = new ExplorerController(pc, ss, ev, etv);
    ec->init();


    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlayer()), Qt::DirectConnection);
    timer->start(1000 / 60);

    connect(pc, SIGNAL(setPlaylistCover(QString)), pcvc, SLOT(setImage(QString)), Qt::DirectConnection);

    QMenu *menu;
    menu = menuBar()->addMenu( tr("&Datei") );
    menu->addAction("Neues Album", this, "");
    connect(menu, SIGNAL(triggered(QAction*)), ec, SLOT(askAddAlbum(QAction*)));
}


void Player::updatePlayer()
{
    scv->updateView();
}
