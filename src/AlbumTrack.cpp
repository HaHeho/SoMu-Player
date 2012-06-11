//#include "AlbumTrack.hpp"
#include "Album.hpp"


AlbumTrack::AlbumTrack(Album* album, QString trackPath)
{
    this->album = album;
    this->path = trackPath;
}

void AlbumTrack::setSound(FMOD::Sound* sound)
{
    this->sound = sound;

    parseTitle();
    calculateDuration();
}

void AlbumTrack::parseTitle()
{
    QRegExp rx("\\..*");
    char name[100];
    this->sound->getName(name, 100);
    QString strName = QString(name);
    strName.remove(rx);
    this->title = strName;
}

void AlbumTrack::calculateDuration()
{
    this->sound->getLength(&this->duration, FMOD_TIMEUNIT_MS);
}

QString AlbumTrack::getPath()
{
    return this->path;
}

FMOD::Sound* AlbumTrack::getSound()
{
    return this->sound;
}

QPixmap* AlbumTrack::getCoverImage()
{
    return this->album->getCoverImage();
}

QString AlbumTrack::getTitle()
{
    return this->title;
}

unsigned int AlbumTrack::getDuration()
{
    return this->duration;
}
