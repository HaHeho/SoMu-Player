#include "AlbumCover.hpp"


AlbumCover::AlbumCover()
{
    parseImage("");
}

AlbumCover::AlbumCover(QString path)
{
    parseImage(path);
}

QString AlbumCover::getImagePath()
{
    return this->imagePath;
}

void AlbumCover::parseImage(QString path)
{
    if (path == "" || !(path.endsWith(".jpg") || path.endsWith(".jpeg") || path.endsWith(".png") || path.endsWith(".bmp")))
    {
        path = ":/albums/no-cover";
    }
    imagePath = path;
}


