#include "ExplorerController.hpp"


ExplorerController::ExplorerController(PlaylistController* playlistController, SoundSystem* soundSystem, ExplorerView* view, ExplorerTreeView* treeView, QObject* parent)
    : QObject(parent)
{
    this->playlistController = playlistController;
    this->soundSystem = soundSystem;
    this->view = view;
    this->treeView = treeView;

    this->musicFilters << "*.mp3" << "*.wav" << "*.wma" << "*.ogg" << "*.wmv" << "*.flac";
    this->imageFilters << "*.jpg" << "*.jpeg" << "*.png" << "*.bmp";

    connect(this->view, SIGNAL(playItem(int)),
            this, SLOT(playItem(int)), Qt::DirectConnection);

    connect(this->treeView, SIGNAL(showAlbum(int)),
            this, SLOT(showAlbum(int)), Qt::DirectConnection);
}

void ExplorerController::askAddAlbum(QAction* action)
{
    Q_UNUSED(action);
    QString fileName = QFileDialog::getExistingDirectory(new QWidget(), tr("Neues Album"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    fileName += "/";
    addFolderToLibrary(fileName);
}

void ExplorerController::init()
{
    initMusicLibrary();
}

void ExplorerController::initMusicLibrary()
{
    addFolderToLibrary("../SoMuPlayer/media/Bad (Michael Jackson)/");
    addFolderToLibrary("../SoMuPlayer/media/Herzeleid (Rammstein)/");
}

void ExplorerController::addFolderToLibrary(QString folderPath)
{
    QDir dir = QDir(folderPath);

    if (!dir.exists())
        qDebug() << "ERROR: The folder " << folderPath << " doesnt exists!";
    dir.setFilter(QDir::NoDotAndDotDot | QDir::Files);

    Album* album = checkIfAlbumExists(folderPath);

    QStringList files = dir.entryList(this->musicFilters);
    for (int i = 0; i < files.size(); i++)
    {
        addItemToLibrary(folderPath + files.at(i), album);
    }
    QStringList imageFiles = dir.entryList(this->imageFilters);
    album->searchBestAlbumCover(imageFiles);
    album->parseName();
}

void ExplorerController::addItemToLibrary(QString path, Album* album)
{
    qDebug() << "Add Item To Library: " << path;

    AlbumTrack* track = album->addTrack(path);//new AlbumTrack(album, path);

    this->trackLibrary.append(track);
    track->setLibraryIndex(this->trackLibrary.indexOf(track));

    this->view->addItem(track);
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
    this->view->showAlbum(this->albumLibrary.at(index));
}

void ExplorerController::playItem(int index)
{
    this->playlistController->addToPlaylistAndPlay(this->trackLibrary.at(index));
}
