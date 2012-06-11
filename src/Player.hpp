#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <stdio.h>
#include <QtGui>
#include <QDebug>
#include <QObject>

#include "SoundController.hpp"
#include "SoundControllerView.hpp"
#include "PlaylistController.hpp"
#include "PlaylistControllerViewList.hpp"
#include "PlaylistControllerViewCover.hpp"
#include "SoundSystem.hpp"


class Player : public QGraphicsView
{
    Q_OBJECT

public:
    Player(QGraphicsScene *scene);

private:
    SoundSystem* ss;
    SoundController* sc;
    SoundControllerView* scv;
    PlaylistController* pc;
    PlaylistControllerViewList* pcvl;
    PlaylistControllerViewCover* pcvc;

signals:


public slots:
    void updatePlayer();

};

#endif // PLAYER_HPP
