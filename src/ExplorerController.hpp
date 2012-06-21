#ifndef EXPLORER_CONTROLLER_HPP
#define EXPLORER_CONTROLLER_HPP


#include <QObject>
#include <QFileSystemModel>

#include "SoundSystem.hpp"
#include "AlbumTrack.hpp"
#include "ExplorerView.hpp"
#include "ExplorerTreeView.hpp"


class ExplorerController : public QObject
{

    Q_OBJECT

public:
    ExplorerController(PlaylistController* playlistController, SoundSystem* soundSystem, ExplorerView* view, ExplorerTreeView* treeView, QObject* parent = 0);
    void init();

private:
    PlaylistController* playlistController;

    QStringList        musicFilters;
    QStringList        imageFilters;
    SoundSystem*       soundSystem;
    ExplorerView*      view;
    ExplorerTreeView*  treeView;
    QList<AlbumTrack*> trackLibrary;
    QList<Album*>      albumLibrary;

    void initMusicLibrary();
    void addFolderToLibrary(QString folderPath);
    void addItemToLibrary(QString path, Album* album);
    Album* checkIfAlbumExists(QString path);

signals:

public slots:
    void showAlbum(int index);
    void playItem(int index);
    void askAddAlbum(QAction* action);

};

#endif // EXPLORER_CONTROLLER_HPP
