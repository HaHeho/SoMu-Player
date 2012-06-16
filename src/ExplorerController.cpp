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

    connect(this->treeView, SIGNAL(showAlbum(int)),
            this, SLOT(showAlbum(int)), Qt::DirectConnection);
}

void ExplorerController::init()
{
    initMusicLibrary();
}

void ExplorerController::initMusicLibrary()
{
    addFolderToLibrary("../SoMu-Player/media/Bad (Michael Jackson)/");
    addFolderToLibrary("../SoMu-Player/media/Herzeleid (Rammstein)/");
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

    Album* album = checkIfAlbumExists(path);
    AlbumTrack* track = new AlbumTrack(album, path);

    ////////////////////////////////////////////////////////////////////////////
    // Diese Zeile kostet extrem viel Performance beim Start
    // da schon gesamter Track in den Arbeitsspeicher geladen wird
    //track->setSound(this->soundSystem->createNewSound(track->getPath().toStdString()));
    ////////////////////////////////////////////////////////////////////////////

    this->trackLibrary.append(track);
    track->setLibraryIndex(this->trackLibrary.indexOf(track));

    //this->view->addItem(track);
    this->treeView->addItem(track);
}

Album* ExplorerController::checkIfAlbumExists(QString path)
{
    Album dummy = Album(path);
    for (int i = 0; i < this->albumLibrary.size(); i++)
    {
        if (this->albumLibrary.at(i)->getName() == dummy.getName())
            return this->albumLibrary.at(i);
    }

    Album* album = new Album(path);
    this->albumLibrary.append(album);
    album->setLibraryIndex(this->albumLibrary.indexOf(album));
    return album;
}

void ExplorerController::showAlbum(int index)
{
    if (index < 0)
        this->view->clear();
    else
        this->view->showAlbum(this->albumLibrary.at(index));
}

void ExplorerController::playItem(int index)
{
    this->playlistController->addToPlaylistAndPlay(this->trackLibrary.at(index));
}
