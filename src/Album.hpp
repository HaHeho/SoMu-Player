#ifndef ALBUM_HPP
#define ALBUM_HPP


#include <QDebug>
#include "fmod.hpp"
#include "AlbumCover.hpp"


//forward-Deklaration
class Album;


class AlbumTrack
{
public:
    AlbumTrack(Album* album, QString trackPath);
    void setSound(FMOD::Sound* sound);
    void setLibraryIndex(unsigned int index);

    QString      getPath();
    unsigned int getNumber();
    QString      getTitle();
    QString      getArtist();
    QString      getGenre();
    Album*       getAlbum();
    QString      getAlbumName();
    FMOD::Sound* getSound();
    unsigned int getDuration();
    QString      getDurationAsString();
    unsigned int getLibraryIndex();

private:
    QString      path;
    unsigned int number;
    QString      title;
    QString      artist;
    QString      genre;
    Album*       album;
    QString      albumName;
    FMOD::Sound* sound;
    unsigned int duration;
    unsigned int libraryIndex;

    QString parseTitle(FMOD::Sound* sound);
    void calculateDuration();
};

class Album
{
public:
    Album(QString path);
    AlbumTrack* addTrack(QString trackPath);

    void setLibraryIndex(unsigned int index);

    QString            getName();
    AlbumCover*        getCover();
    QImage*            getCoverImage();
    QList<AlbumTrack*> getTracklist();
    unsigned int       getLibraryIndex();
    void               searchBestAlbumCover(QStringList fileList);
    void               parseName();

private:
    QString            albumPath;
    QString            name;
    AlbumCover*        cover;
    QList<AlbumTrack*> tracklist;
    unsigned int       libraryIndex;
};


#endif // ALBUM_HPP
