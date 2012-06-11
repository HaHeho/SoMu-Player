#ifndef ALBUM_COVER_HPP
#define ALBUM_COVER_HPP


#include <QPixmap>


class AlbumCover
{
public:
    AlbumCover();
    AlbumCover(QString path);
    QPixmap* getImage();

private:
    QPixmap image;
};

#endif // ALBUM_COVER_HPP
