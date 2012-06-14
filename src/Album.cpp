#include "Album.hpp"


Album::Album(QString path)
{
    this->name = parseName(path);
    this->cover = new AlbumCover(path);
}

QString Album::getName()
{
    return this->name;
}

AlbumTrack* Album::addTrack(QString trackPath)
{
    AlbumTrack* track = new AlbumTrack(this, trackPath);
    this->tracklist.append(track);

    return track;
}

QPixmap* Album::getCoverImage()
{
    return this->cover->getImage();
}

QString Album::parseName(QString path)
{
    if (path == "")
        return "Unknown Album";
    else
        // hier muss noch geparst werden
        return "Parsed Album Name";
}
