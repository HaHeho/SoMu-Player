#ifndef ALBUM_HPP
#define ALBUM_HPP


#include "AlbumCover.hpp"


//forward-Deklaration
class AlbumTrack;

class Album
{
public:
    Album(QString path);
    void setCover(QString coverPath);
    AlbumTrack* addTrack(QString trackPath);
    QPixmap* getCoverImage();

private:
    QString name;
    AlbumCover cover;
    QList<AlbumTrack*> trackList;
};




#include <QPixmap>
#include "fmod.hpp"
//#include "Album.hpp"


class AlbumTrack
{
public:
    AlbumTrack(Album* album, QString trackPath);
    void setSound(FMOD::Sound* sound);

    QString getPath();
    QString getTitle();
    FMOD::Sound* getSound();
    QPixmap* getCoverImage();
    unsigned int getDuration();

private:
    QString path;
    Album* album;
    QString title;
    FMOD::Sound* sound;
    unsigned int duration;

};


#endif // ALBUM_HPP
