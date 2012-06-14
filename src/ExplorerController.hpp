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
    ExplorerController(SoundSystem* soundSystem, ExplorerView* view, ExplorerTreeView* treeView, QObject* parent = 0);
    void init();

private:
    SoundSystem*       soundSystem;
    QList<AlbumTrack*> library;
    ExplorerView*      view;
    ExplorerTreeView*  treeView;

    void initMusicLibrary();
    void addFolderToLibrary(QString folderPath);
    void addItemToLibrary(QString path);

signals:

public slots:

};

#endif // EXPLORER_CONTROLLER_HPP
