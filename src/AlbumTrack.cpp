//#include "AlbumTrack.hpp"
#include "Album.hpp"


AlbumTrack::AlbumTrack(Album* album, QString trackPath)
{
    this->path = trackPath;
    this->number = 1;
    this->artist = "Unknown Artist";
    this->album = album;
    this->genre = "Unknown Genre";
}

void AlbumTrack::setSound(FMOD::Sound* sound)
{
    this->sound = sound;
    this->title = parseTitle(sound);
    calculateDuration();
}

QString AlbumTrack::parseTitle(FMOD::Sound* sound)
{
    QRegExp rx("\\..*");
    char name[100];
    sound->getName(name, 100);
    QString strName = QString(name);
    strName.remove(rx);
    return strName;
}

void AlbumTrack::calculateDuration()
{
    this->sound->getLength(&this->duration, FMOD_TIMEUNIT_MS);
}

QString AlbumTrack::getPath()
{
    return this->path;
}

unsigned int AlbumTrack::getNumber()
{
    return this->number;
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

QString AlbumTrack::getArtist()
{
    return this->artist;
}

QString AlbumTrack::getGenre()
{
    return this->genre;
}

Album *AlbumTrack::getAlbum()
{
    return this->album;
}

unsigned int AlbumTrack::getDuration()
{
    return this->duration;
}
