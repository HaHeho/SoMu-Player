#ifndef ALBUM_COVER_HPP
#define ALBUM_COVER_HPP

#include <QDebug>
#include <QPixmap>


class AlbumCover
{
public:
    AlbumCover();
    AlbumCover(QString path);
    QString getImagePath();


private:
    void parseImage(QString path);
    QString imagePath;

};

#endif // ALBUM_COVER_HPP
