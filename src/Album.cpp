#include "Album.hpp"


Album::Album(QString path)
{
    // hier muss noch geparst werden
    this->name = "";

    this->cover = AlbumCover(path);
}

void Album::setCover(QString coverPath)
{
    this->cover = AlbumCover(coverPath);
}

AlbumTrack* Album::addTrack(QString trackPath)
{
    AlbumTrack* track = new AlbumTrack(this, trackPath);
    this->trackList.append(track);

    return track;
}

QPixmap* Album::getCoverImage()
{
    return this->cover.getImage();
}
