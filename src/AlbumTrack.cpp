//#include "AlbumTrack.hpp"
#include "Album.hpp"


AlbumTrack::AlbumTrack(Album* album, QString trackPath)
{
    this->path = trackPath;
    this->number = 0;
    this->artist = "Unknown Artist";
    this->album = album;
    this->genre = "Unknown Genre";

    this->album->addTrack(this);
}

void AlbumTrack::setSound(FMOD::Sound* sound)
{
    this->sound = sound;
    this->title = parseTitle(sound);
    calculateDuration();
}

void AlbumTrack::setLibraryIndex(unsigned int index)
{
    this->libraryIndex = index;
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

unsigned int AlbumTrack::getLibraryIndex()
{
    return this->libraryIndex;
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

Album* AlbumTrack::getAlbum()
{
    return this->album;
}

QString AlbumTrack::getAlbumName()
{
    return this->album->getName();
}

unsigned int AlbumTrack::getDuration()
{
    return this->duration;
}

QString AlbumTrack::getDurationAsString()
{
    QString string = QString::number((this->duration / 60000) % 60) + ":";

    int sec = (this->duration / 1000) % 60;
    if (sec < 10)
        string += '0';

    return string + QString::number(sec);
}
