#ifndef SOUNDCONTROLLER_H
#define SOUNDCONTROLLER_H

#include <QObject>
#include "src/soundsystem.h"
#include "src/playlistcontroller.h"


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

#endif // SOUNDCONTROLLER_H
