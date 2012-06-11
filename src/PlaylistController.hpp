#ifndef PLAYLIST_CONTROLLER_HPP
#define PLAYLIST_CONTROLLER_HPP

#include <QObject>
#include "SoundSystem.hpp"
#include "PlaylistItem.hpp"


class PlayListController : public QObject
{
    Q_OBJECT

public:
    explicit PlayListController(SoundSystem *ss, QObject *parent = 0);
    PlayListItem* addToPlaylist(AlbumTrack* track);
    int getPlayListLength();
    PlayListItem* getItemAt(int i);
    void removeItemAt(int i);


private:
    SoundSystem* soundSystem;
    QList<PlayListItem*> playList;


signals:

public slots:
    void startSound(PlayListItem*);
};

#endif // PLAYLIST_CONTROLLER_HPP
