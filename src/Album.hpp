#ifndef ALBUM_HPP
#define ALBUM_HPP


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

    QString getPath();
    QString getTitle();
    FMOD::Sound* getSound();
    QPixmap* getCoverImage();
    unsigned int getDuration();

private:
    QString      path;
    Album*       album;
    QString      title;
    FMOD::Sound* sound;
    unsigned int duration;
    void parseTitle();
    void calculateDuration();
};

class Album
{
public:
    Album(QString path);
    void setCover(QString coverPath);
    AlbumTrack* addTrack(QString trackPath);
    QPixmap* getCoverImage();

private:
    QString            name;
    AlbumCover         cover;
    QList<AlbumTrack*> trackList;
};


#endif // ALBUM_HPP
