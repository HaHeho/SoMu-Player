#include "Album.hpp"


Album::Album(QString path)
{
    this->name = parseName(path);
    this->cover = new AlbumCover(path);
    this->libraryIndex = 0;
}

void Album::addTrack(AlbumTrack* track)
{
    this->tracklist.append(track);
}

QString Album::getName()
{
    return this->name;
}

void Album::setLibraryIndex(unsigned int index)
{
    this->libraryIndex = index;
}

QPixmap* Album::getCoverImage()
{
    return this->cover->getImage();
}

QList<AlbumTrack*> Album::getTracklist()
{
    return this->tracklist;
}

unsigned int Album::getLibraryIndex()
{
    return this->libraryIndex;
}

QString Album::parseName(QString path)
{
    if (path == "")
        return "Unknown Album";
    else
        // hier muss noch geparst werden
        return "Parsed Album Name";
}
