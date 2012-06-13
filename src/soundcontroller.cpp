#include "SoundController.hpp"


SoundController::SoundController(SoundSystem* ss, QObject* parent) : QObject(parent)
{
    this->soundSystem = ss;
}


void SoundController::initPlaylistController(PlaylistController* plc)
{
    this->playlist = plc;
    connect(this, SIGNAL(playNext()), this->playlist, SLOT(startNextSound()));
}


void SoundController::play()
{
    qDebug() << "SoundController::play()";
    soundSystem->resumeCurrentSound();
}


void SoundController::pause()
{
    qDebug() << "SoundController::pause()";
    soundSystem->pauseCurrentSound();
}


void SoundController::next()
{
    qDebug() << "SoundController::next()";
    emit playNext();
}


void SoundController::prev()
{
    qDebug() << "SoundController::prev()";
}


void SoundController::setProgressOfCurSong(float progress)
{
    soundSystem->setSoundPositionInPerc(progress);
}
