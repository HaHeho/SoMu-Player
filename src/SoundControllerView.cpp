#include "SoundControllerView.hpp"


SoundControllerView::SoundControllerView(SoundController* sc, SoundSystem* ss, float w, float h) : BasicItem(w, h)
{
    soundController = sc;
    soundSystem = ss;
    sliderMoveActivated = false;
}


void SoundControllerView::init()
{
    Button *playBtn = new Button(32, 32);
    playBtn->setParentItem(this);
    playBtn->init();
    playBtn->setPos(100, height/2-26);
    playBtn->setNormalImage(":/images/play");
    playBtn->setRolloverImage(":/images/play-on");
    connect(playBtn, SIGNAL(clicked()),
            soundController, SLOT(play()), Qt::DirectConnection);

    Button *pauseBtn = new Button(32, 32);
    pauseBtn->setParentItem(this);
    pauseBtn->init();
    pauseBtn->setPos(200, height/2-26);
    pauseBtn->setNormalImage(":/images/pause");
    pauseBtn->setRolloverImage(":/images/pause-on");
    connect(pauseBtn, SIGNAL(clicked()),
            soundController, SLOT(pause()), Qt::DirectConnection);

    progressSlider = new QSlider(Qt::Horizontal);
    scene()->addWidget(progressSlider);
    progressSlider->setGeometry(this->x(), this->y()+40, this->width, 20);
    progressSlider->setMaximum(1000);
    connect(progressSlider, SIGNAL(sliderPressed()),
            this, SLOT(enableSliderMoveMode()), Qt::DirectConnection);
    connect(progressSlider, SIGNAL(sliderReleased()),
            this, SLOT(disableSliderMoveMode()), Qt::DirectConnection);

    progressText = new QGraphicsTextItem(this);
    progressText->setTextWidth(100);
    progressText->setPos(getWidth() - 100, 8);

    connect(this, SIGNAL(currentTrackEnded()),
            soundController, SLOT(next()), Qt::DirectConnection);
}


void SoundControllerView::updateView()
{
    if (sliderMoveActivated)
        return;

    float perc = soundSystem->getCurPositionInPerc();
    progressSlider->setValue(perc * progressSlider->maximum());


    int pos = soundSystem->getCurPositionInMs();
    int length = soundSystem->getLengthInMs();

    QTime displayPos(0, (pos / 60000) % 60, (pos / 1000) % 60);
    QTime displayLength(0, (length / 60000) % 60, (length / 1000) % 60);

    progressText->setPlainText(displayPos.toString("m:ss") + "/" + displayLength.toString("m:ss"));
    QTextCursor cursor = progressText->textCursor();
    QTextBlockFormat bfmt = cursor.blockFormat();
    bfmt.setAlignment(Qt::AlignRight);
    cursor.setBlockFormat(bfmt);
    progressText->setTextCursor(cursor);

    checkTrackEnded();
}

void SoundControllerView::checkTrackEnded()
{
    if (this->soundSystem->getCurPositionInPerc() >= 1.0)
    {
        emit currentTrackEnded();
    }
}

void SoundControllerView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawRect(boundingRect());
}


void SoundControllerView::enableSliderMoveMode()
{
    sliderMoveActivated = true;
}


void SoundControllerView::disableSliderMoveMode()
{
    int value = progressSlider->value();
    float progress = (value > 0) ? ((float)value/(float)progressSlider->maximum()) : 0;
    soundController->setProgressOfCurSong(progress);

    sliderMoveActivated = false;
}
