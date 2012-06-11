/*
#ifndef ALBUM_TRACK_HPP
#define ALBUM_TRACK_HPP


#include <QPixmap>
#include "fmod.hpp"
#include "Album.hpp"


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

#endif // ALBUM_TRACK_HPP
*/
