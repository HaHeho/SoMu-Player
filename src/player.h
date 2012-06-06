#ifndef PLAYER_H
#define PLAYER_H

#include <QtGui>
#include "src/soundcontroller.h"
#include "src/soundcontrollerview.h"
#include "src/playlistcontroller.h"
#include "src/playlistcontrollerview.h"
#include "src/soundsystem.h"


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

#endif // PLAYER_H
