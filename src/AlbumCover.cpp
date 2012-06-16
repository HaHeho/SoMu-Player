#include "AlbumCover.hpp"


AlbumCover::AlbumCover(QString path)
{
    this->image = parseImage(path);
}

QPixmap* AlbumCover::getImage()
{
    return this->image;
}

QPixmap* AlbumCover::parseImage(QString path)
{
    if (path == "" || !path.endsWith(".jpg") || !path.endsWith(".png"))
    {
        path = ":/albums/no-cover";
    }

    return new QPixmap(path);
}
