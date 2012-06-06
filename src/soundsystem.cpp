#include <QtGui>
#include "src/soundsystem.h"
#include "common/wincompat.h"


SoundSystem::SoundSystem()
{
    init();
}


void SoundSystem::init()
{
    unsigned int      version;

    /*
        Create a System object and initialize.
    */
    result = FMOD::System_Create(&system);
    checkError(result);
    result = system->setOutput(FMOD_OUTPUTTYPE_ALSA);
    checkError(result);
    result = system->init(32, FMOD_INIT_NORMAL, 0);
    checkError(result);
    result = system->getVersion(&version);
    checkError(result);

    if (version < FMOD_VERSION)
    {
        qDebug("Error! You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
        getch();
        exit(0);
    }
}


void SoundSystem::checkError(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        qDebug("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }
}


FMOD::Sound* SoundSystem::createNewSound(std::string path)
{
    FMOD::Sound* newSound;
    result = system->createSound(path.c_str(), FMOD_SOFTWARE, 0, &newSound);
    checkError(result);
    result = newSound->setMode(FMOD_LOOP_OFF);
    checkError(result);
    return newSound;
}


void SoundSystem::playSound(FMOD::Sound* sound)
{
    curSound = sound;
    result = system->playSound(FMOD_CHANNEL_FREE, sound, 0, &channel);
    checkError(result);
}


void SoundSystem::pauseCurrentSound()
{
    channel->setPaused(true);
}


void SoundSystem::resumeCurrentSound()
{
    channel->setPaused(false);
}


unsigned int SoundSystem::getCurPositionInMs()
{
    unsigned int ms = 0;
    result = channel->getPosition(&ms, FMOD_TIMEUNIT_MS);
    if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
    {
        checkError(result);
    }
    return ms;
}


unsigned int SoundSystem::getLengthInMs()
{
    unsigned int length = 0;
    FMOD::Sound *currentsound = 0;
    channel->getCurrentSound(&currentsound);
    if (currentsound)
    {
        result = currentsound->getLength(&length, FMOD_TIMEUNIT_MS);
        if ((result != FMOD_OK) && (result != FMOD_ERR_INVALID_HANDLE) && (result != FMOD_ERR_CHANNEL_STOLEN))
        {
            checkError(result);
        }
    }
    return length;
}


float SoundSystem::getCurPositionInPerc()
{
    unsigned int cur = getCurPositionInMs();
    unsigned int length = getLengthInMs();

    if (cur == 0 || length == 0)
        return 0;

    return (float)cur/(float)length;
}


void SoundSystem::setSoundPositionInPerc(float perc)
{
    unsigned int length = getLengthInMs();
    float newPos = length * perc;
    if (perc == 1)
        newPos--;
    result = channel->setPosition(newPos, FMOD_TIMEUNIT_MS);
}


//i think that kills everything. Not tested
void SoundSystem::stopCurrentSound()
{
    channel->stop();
}

