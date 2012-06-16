#ifndef PLAYLIST_CONTROLLER_HPP
#define PLAYLIST_CONTROLLER_HPP

#include <QObject>

#include "SoundSystem.hpp"
#include "PlaylistItem.hpp"
#include "PlaylistControllerViewList.hpp"


class PlaylistController : public QObject
{
    Q_OBJECT

public:
    PlaylistController(PlaylistControllerViewList* viewList, SoundSystem* ss, QObject* parent = 0);
    void init();
    int getPlaylistLength();
    PlaylistItem* getItemAt(int i);
    void removeItemAt(int i);
    void addToPlaylist(AlbumTrack* track);
    void addToPlaylistAndPlay(AlbumTrack* track);


private:
    PlaylistControllerViewList* viewList;
    SoundSystem*                soundSystem;
    QList<PlaylistItem*>        playlist;
    int                         currentIndex;
    bool                        isInit;

    void initStartPlaylist();
    void updateItemColors();


signals:
    void setPlaylistCover(QPixmap* cover);


public slots:
    void getDraggedObject(QString path);
    void startSound(PlaylistItem* sender);
    void startNextSound();
};

#endif // PLAYLIST_CONTROLLER_HPP
