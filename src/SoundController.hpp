#ifndef SOUND_CONTROLLER_HPP
#define SOUND_CONTROLLER_HPP


#include "SoundSystem.hpp"
#include "PlaylistController.hpp"


class SoundController : public QObject
{
    Q_OBJECT

public:
    explicit SoundController(SoundSystem* ss, QObject *parent = 0);
    void initPlaylistController(PlaylistController* plc);
    void setProgressOfCurSong(float progress);


private:
    SoundSystem *soundSystem;
    PlaylistController* playlist;


signals:
    void playNext();


public slots:
    void play();
    void pause();
    void next();
    void prev();
};

#endif // SOUND_CONTROLLER_HPP
