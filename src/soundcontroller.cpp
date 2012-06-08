#include "SoundController.hpp"


SoundController::SoundController(SoundSystem* ss, QObject *parent) : QObject(parent)
{
    this->soundSystem = ss;
}


void SoundController::initPlayListController(PlayListController* plc)
{
    this->playList = plc;
}


void SoundController::play()
{
    qDebug() << "play";
    soundSystem->resumeCurrentSound();
}


void SoundController::pause()
{
    qDebug() << "pause";
    soundSystem->pauseCurrentSound();
}


void SoundController::next()
{
    qDebug() << "next";
}


void SoundController::prev()
{
    qDebug() << "prev";
}


void SoundController::setProgressOfCurSong(float progress)
{
    soundSystem->setSoundPositionInPerc(progress);
}
