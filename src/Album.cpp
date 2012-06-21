#include "Album.hpp"


Album::Album(QString path)
{
    this->albumPath = path;
    this->cover = new AlbumCover();
}

QString Album::getName()
{
    return this->name;
}

AlbumTrack* Album::addTrack(QString trackPath)
{
    AlbumTrack* track = new AlbumTrack(this, trackPath);
    this->tracklist.append(track);

    return track;
}

void Album::searchBestAlbumCover(QStringList fileList)
{
    if (fileList.length() == 0)
    {
        return;
    }
    if (fileList.length() == 1)
    {
        cover = new AlbumCover(albumPath + fileList.at(0));
    }

    QRegExp checkName("(?:.*cover.*|.*front.*)");
    checkName.setCaseSensitivity(Qt::CaseInsensitive);

    for (int i = 0; i < fileList.size(); i++)
    {
        QString fileName = fileList.at(i);

        if (fileName.indexOf(checkName) != -1)
        {
            qDebug() << "Found a pretty good Image for this Album";
            cover = new AlbumCover(albumPath + fileList.at(i));
            return;
        }
    }

    //we found nothing. Just take the first pic and get out of here
    cover = new AlbumCover(albumPath + fileList.at(0));
}

void Album::setLibraryIndex(unsigned int index)
{
    this->libraryIndex = index;
}

AlbumCover* Album::getCover()
{
    return this->cover;
}

QList<AlbumTrack*> Album::getTracklist()
{
    return this->tracklist;
}

unsigned int Album::getLibraryIndex()
{
    return this->libraryIndex;
}

void Album::parseName()
{
    this->name = tracklist.at(0)->getAlbumName();
    if (this->name == "")
        this->name = "Unknown Album";
}
