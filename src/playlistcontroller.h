#ifndef PLAYLISTCONTROLLER_H
#define PLAYLISTCONTROLLER_H

#include <QObject>
#include "src/soundsystem.h"
#include "src/playlistitem.h"


class PlayListController : public QObject
{
    Q_OBJECT

public:
    explicit PlayListController(SoundSystem *ss, QObject *parent = 0);
    PlayListItem* addToPlaylist(QString soundPath);
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

#endif // PLAYLISTCONTROLLER_H
