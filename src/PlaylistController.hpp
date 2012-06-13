#ifndef PLAYLIST_CONTROLLER_HPP
#define PLAYLIST_CONTROLLER_HPP

#include <QObject>
#include "SoundSystem.hpp"
#include "PlaylistItem.hpp"
#include "PlaylistControllerViewCover.hpp"


class PlaylistController : public QObject
{
    Q_OBJECT

public:
    PlaylistController(SoundSystem* ss, QObject* parent = 0);
    PlaylistItem* addToPlaylist(AlbumTrack* track);
    int getPlayListLength();
    PlaylistItem* getItemAt(int i);
    void removeItemAt(int i);


private:
    SoundSystem*         soundSystem;
    QList<PlaylistItem*> playList;
    int                  currentIndex;

    void updateItemColors();


signals:
    void setPlaylistCover(QPixmap* cover);


public slots:
    void startSound(PlaylistItem* sender);
    void startNextSound();
};

#endif // PLAYLIST_CONTROLLER_HPP
