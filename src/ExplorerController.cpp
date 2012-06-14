#include "ExplorerController.hpp"


ExplorerController::ExplorerController(SoundSystem* soundSystem, ExplorerView* view, ExplorerTreeView* treeView, QObject* parent)
    : QObject(parent)
{
    this->soundSystem = soundSystem;
    this->view = view;
    this->treeView = treeView;
}

void ExplorerController::init()
{
    initMusicLibrary();
}

void ExplorerController::initMusicLibrary()
{
    //addFolderToLibrary("../SoMu-Player/media/Bad (Michael Jackson)");

    addItemToLibrary("../SoMu-Player/media/Bad (Michael Jackson)/1 Bad - Michael Jackson (Bad).mp3");
    addItemToLibrary("../SoMu-Player/media/Bad (Michael Jackson)/2 The Way You Make Me Feel - Michael Jackson (Bad).mp3");

}

void ExplorerController::addFolderToLibrary(QString folderPath)
{
    QFileSystemModel* fsm = new QFileSystemModel();
    fsm->setRootPath(folderPath);
    /*
    for (QModelIndex i = QModelIndex() 0; i < fsm->rowCount(); i++)
    {
        qDebug() << "found file: " << fsm->fileName(i);
    }
    */
}

void ExplorerController::addItemToLibrary(QString path)
{
    Album* album = new Album(path);
    AlbumTrack* track = new AlbumTrack(album, path);
    track->setSound(this->soundSystem->createNewSound(track->getPath().toStdString()));
    this->view->addItem(track);
    this->treeView->addItem(track);
}
