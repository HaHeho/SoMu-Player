//#include "AlbumTrack.hpp"
#include "Album.hpp"


AlbumTrack::AlbumTrack(Album* album, QString trackPath)
{
    this->album = album;
    this->path = trackPath;

    //get Name of the Song
    QRegExp rx("\\..*");
    char name[100];
    sound->getName(name, 100);
    QString strName = QString(name);
    strName.remove(rx);

    //calculate Duration
    sound->getLength(&this->duration, FMOD_TIMEUNIT_MS);
}

void AlbumTrack::setSound(FMOD::Sound* sound)
{
    this->sound = sound;
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
