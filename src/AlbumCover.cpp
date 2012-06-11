#include "AlbumCover.hpp"


AlbumCover::AlbumCover()
{
}

AlbumCover::AlbumCover(QString path)
{
    if (path == "")
    {
        path = "res/no cover.jpg";
    }

    this->image = QPixmap(path);
}

QPixmap* AlbumCover::getImage()
{
    return &image;
}
