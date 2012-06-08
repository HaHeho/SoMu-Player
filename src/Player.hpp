#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <stdio.h>
#include <QtGui>
#include "SoundController.hpp"
#include "SoundControllerView.hpp"
#include "PlayListController.hpp"
#include "PlaylistControllerView.hpp"
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
    PlayListController* pc;
    PlaylistControllerView* pcv;

signals:


public slots:
    void updatePlayer();

};

#endif // PLAYER_HPP
