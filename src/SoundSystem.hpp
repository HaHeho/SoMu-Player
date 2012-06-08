#ifndef SOUND_SYSTEM_HPP
#define SOUND_SYSTEM_HPP


#include <QtGui>
#include <conio.h>

#include "wincompat.h"
#include "fmod_errors.h"
#include "fmod.hpp"


class SoundSystem
{
public:
    SoundSystem();
    FMOD::Sound* createNewSound(std::string path);
    void playSound(FMOD::Sound* sound);
    void pauseCurrentSound();
    void resumeCurrentSound();
    void stopCurrentSound();
    unsigned int getCurPositionInMs();
    unsigned int getLengthInMs();
    float getCurPositionInPerc();
    void setSoundPositionInPerc(float perc);


private:
    void init();
    void checkError(FMOD_RESULT result);
    FMOD::System     *system;
    FMOD::Sound      *curSound;
    FMOD::Channel    *channel;
    FMOD_RESULT       result;
};

#endif // SOUND_SYSTEM_HPP
