#ifndef SOUND_CONTROLLER_HPP
#define SOUND_CONTROLLER_HPP

#include <QObject>
#include <QDebug>
#include "SoundSystem.hpp"
#include "PlaylistController.hpp"


class SoundController : public QObject
{
    Q_OBJECT

public:
    explicit SoundController(SoundSystem* ss, QObject *parent = 0);
    void initPlayListController(PlayListController* plc);
    void setProgressOfCurSong(float progress);


private:
    SoundSystem *soundSystem;
    PlayListController* playList;


signals:

public slots:
    void play();
    void pause();
    void next();
    void prev();
};

#endif // SOUND_CONTROLLER_HPP
