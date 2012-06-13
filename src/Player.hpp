#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <stdio.h>
#include <QtGui>
#include <QDebug>
#include <QObject>

#include "SoundSystem.hpp"
#include "SoundController.hpp"
#include "SoundControllerView.hpp"
#include "PlaylistController.hpp"
#include "PlaylistControllerViewList.hpp"
#include "PlaylistControllerViewCover.hpp"
#include "ExplorerView.hpp"
#include "ExplorerTreeView.hpp"
#include "ExplorerController.hpp"


class Player : public QGraphicsView
{
    Q_OBJECT

public:
    Player(QGraphicsScene* qScene);

private:
    QGraphicsScene*              scene;
    SoundSystem*                 ss;
    SoundController*             sc;
    SoundControllerView*         scv;
    PlaylistController*          pc;
    PlaylistControllerViewList*  pcvl;
    PlaylistControllerViewCover* pcvc;
    ExplorerView*                ev;
    ExplorerTreeView*            etv;
    ExplorerController*          ec;

signals:


public slots:
    void updatePlayer();

};

#endif // PLAYER_HPP
