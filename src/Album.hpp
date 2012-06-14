#ifndef ALBUM_HPP
#define ALBUM_HPP


#include <QDebug>
#include <QPixmap>
#include "fmod.hpp"
#include "AlbumCover.hpp"


//forward-Deklaration
class Album;


class AlbumTrack
{
public:
    AlbumTrack(Album* album, QString trackPath);
    void setSound(FMOD::Sound* sound);

    QString      getPath();
    unsigned int getNumber();
    QString      getTitle();
    QString      getArtist();
    QString      getGenre();
    Album*       getAlbum();
    FMOD::Sound* getSound();
    unsigned int getDuration();
    QPixmap*     getCoverImage();

private:
    QString      path;
    unsigned int number;
    QString      title;
    QString      artist;
    QString      genre;
    Album*       album;
    FMOD::Sound* sound;
    unsigned int duration;

    QString parseTitle(FMOD::Sound* sound);
    void calculateDuration();
};

class Album
{
public:
    Album(QString path);
    AlbumTrack* addTrack(QString trackPath);

    QString  getName();
    QPixmap* getCoverImage();

private:
    QString            name;
    AlbumCover*        cover;
    QList<AlbumTrack*> tracklist;

    QString parseName(QString path);
};


#endif // ALBUM_HPP
