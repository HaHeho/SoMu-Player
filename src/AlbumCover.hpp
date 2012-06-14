#ifndef ALBUM_COVER_HPP
#define ALBUM_COVER_HPP


#include <QDebug>
#include <QPixmap>


class AlbumCover
{
public:
    AlbumCover(QString path);
    QPixmap* getImage();

private:
    QPixmap* image;
    QPixmap* parseImage(QString path);
};

#endif // ALBUM_COVER_HPP
