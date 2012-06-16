#include "ExplorerController.hpp"


ExplorerController::ExplorerController(PlaylistController* playlistController, SoundSystem* soundSystem, ExplorerView* view, ExplorerTreeView* treeView, QObject* parent)
    : QObject(parent)
{
    this->playlistController = playlistController;
    this->soundSystem = soundSystem;
    this->view = view;
    this->treeView = treeView;

    this->musicFilters << "*.mp3" << "*.wav" << "*.wma" << "*.ogg" << "*.wmv" << "*.flac";

    connect(this->view, SIGNAL(playItem(int)),
            this, SLOT(playItem(int)), Qt::DirectConnection);
}

void ExplorerController::init()
{
    initMusicLibrary();
}

void ExplorerController::initMusicLibrary()
{
    addFolderToLibrary("../SoMu-Player/media/Bad (Michael Jackson)/");
}

void ExplorerController::addFolderToLibrary(QString folderPath)
{
    QDir dir = QDir(folderPath);
    dir.setFilter(QDir::NoDotAndDotDot | QDir::Files);

    QStringList files = dir.entryList(this->musicFilters);
    for (int i = 0; i < files.size(); i++)
    {
        addItemToLibrary(folderPath + files.at(i));
    }
}

void ExplorerController::addItemToLibrary(QString path)
{
    qDebug() << "ExplorerController::addItemToLibrary(QString path)";
    qDebug() << path;

    Album* album = new Album(path);
    AlbumTrack* track = new AlbumTrack(album, path);

    ////////////////////////////////////////////////////////////////////////////
    // Diese Zeile kostet extrem viel Performance beim Start
    //track->setSound(this->soundSystem->createNewSound(track->getPath().toStdString()));
    ////////////////////////////////////////////////////////////////////////////

    this->library.append(track);
    track->setLibraryIndex(library.indexOf(track));

    this->view->addItem(track);
    this->treeView->addItem(track);
}

void ExplorerController::playItem(int index)
{
    this->playlistController->addToPlaylistAndPlay(this->library.at(index));
}
