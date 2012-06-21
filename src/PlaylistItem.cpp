#include "PlaylistItem.hpp"


PlaylistItem::PlaylistItem(AlbumTrack* track, int index) : BasicItem(0, 0)
{
    this->playlistIndex = index;

    this->setMinimumSize(200, 18);
    this->setMaximumSize(200, 18);

    this->status = this->FUTURE;
    this->colorNow = QColor(100, 230, 20);
    this->colorPast = QColor(230, 230, 230);
    this->color = QColor(230, 100, 20);
    this->track = track;

    //create Textfield for duration
    unsigned int duration = this->track->getDuration();
    QTime displayTime(0, (duration / 60000) % 60, (duration / 1000) % 60);
    this->durationText = new QLabel(this);
    this->durationText->setText(displayTime.toString("m:ss"));
    this->durationText->setAlignment(Qt::AlignRight);
    this->durationText->setMinimumWidth(200);

    //create Textfield for title
    this->titleText = new QLabel(this);
    this->titleText->setText(this->track->getTitle());

    actBackgroundColor();
}


void PlaylistItem::actBackgroundColor()
{
    if (this->status == this->NOW)
    {
        this->titleText->setStyleSheet("background-color: rgb( 36, 36, 36 )" );
        this->durationText->setStyleSheet("background-color: rgb( 36, 36, 36 )" );

        QPalette palette;
        QBrush brush(QColor(100, 255, 100, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        titleText->setPalette(palette);
        durationText->setPalette(palette);
    }
    else if (playlistIndex % 2 == 0)
    {
        this->titleText->setStyleSheet("background-color: rgb( 55, 55, 55 )" );
        this->durationText->setStyleSheet("background-color: rgb( 55, 55, 55 )" );

        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        titleText->setPalette(palette);
        durationText->setPalette(palette);
    }
    else
    {
        this->titleText->setStyleSheet("background-color: rgb( 49, 49, 49 )" );
        this->durationText->setStyleSheet("background-color: rgb( 49, 49, 49 )" );

        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        titleText->setPalette(palette);
        durationText->setPalette(palette);
    }
}


void PlaylistItem::init()
{
}


void PlaylistItem::mouseDoubleClickEvent(QMouseEvent* event)
{
    Q_UNUSED (event);
    emit doubleClicked(this);
}

void PlaylistItem::emitDoubleClicked()
{
    emit doubleClicked(this);
}

FMOD::Sound* PlaylistItem::getSound()
{
    return this->track->getSound();
}

AlbumTrack* PlaylistItem::getTrack()
{
    return this->track;
}

void PlaylistItem::setStatus(Status newStatus)
{
    this->status = newStatus;
    actBackgroundColor();
}
