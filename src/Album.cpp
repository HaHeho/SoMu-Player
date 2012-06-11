#include "Album.hpp"


Album::Album(QString path)
{
    // hier muss noch geparst werden
    this->name = "";

    setCover(path);
}

void Album::setCover(QString coverPath)
{
    //this->cover = AlbumCover(coverPath, 0);
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
