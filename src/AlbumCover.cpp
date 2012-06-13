#include "AlbumCover.hpp"


AlbumCover::AlbumCover(QString path)
{
    if (path == "")
    {
        path = ":/albums/no-cover";
    }

    this->image = new QPixmap(path);
}

QPixmap* AlbumCover::getImage()
{
    return this->image;
}
