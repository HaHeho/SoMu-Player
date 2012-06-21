#include "SoundControllerView.hpp"


SoundControllerView::SoundControllerView(SoundController* sc, SoundSystem* ss, float w, float h) : BasicItem(w, h)
{
    soundController = sc;
    soundSystem = ss;
    sliderMoveActivated = false;
}


void SoundControllerView::init()
{
    container = new QGroupBox();
    QVBoxLayout* layout = new QVBoxLayout();

    container->setLayout(layout);
    container->setAutoFillBackground(true);
    container->setStyleSheet( "background-color: rgb( 71, 71, 71 )" );

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QVBoxLayout* sliderLayout = new QVBoxLayout();
    layout->addLayout(buttonLayout);
    layout->addLayout(sliderLayout);
    layout->setAlignment(Qt::AlignBottom);
    buttonLayout->setAlignment(Qt::AlignCenter);
    sliderLayout->setAlignment(Qt::AlignCenter);


    Button* backBtn = new Button(32, 32);
    backBtn->init();
    backBtn->setNormalImage(":/images/rewind");
    backBtn->setRolloverImage(":/images/rewind-on");
    connect(backBtn, SIGNAL(clicked()), soundController, SLOT(prev()), Qt::DirectConnection);
    buttonLayout->addWidget(backBtn);

    Button* playBtn = new Button(32, 32);
    playBtn->init();
    playBtn->setNormalImage(":/images/play");
    playBtn->setRolloverImage(":/images/play-on");
    connect(playBtn, SIGNAL(clicked()), soundController, SLOT(play()), Qt::DirectConnection);
    buttonLayout->addWidget(playBtn);

    Button* pauseBtn = new Button(32, 32);
    pauseBtn->init();
    pauseBtn->setNormalImage(":/images/pause");
    pauseBtn->setRolloverImage(":/images/pause-on");
    connect(pauseBtn, SIGNAL(clicked()), soundController, SLOT(pause()), Qt::DirectConnection);
    buttonLayout->addWidget(pauseBtn);

    Button* nextBtn = new Button(32, 32);
    nextBtn->init();
    nextBtn->setNormalImage(":/images/forward");
    nextBtn->setRolloverImage(":/images/forward-on");
    connect(nextBtn, SIGNAL(clicked()), soundController, SLOT(next()), Qt::DirectConnection);
    buttonLayout->addWidget(nextBtn);

    progressSlider = new QSlider(Qt::Horizontal);
    progressSlider->setMaximum(1000);
    connect(progressSlider, SIGNAL(sliderPressed()), this, SLOT(enableSliderMoveMode()), Qt::DirectConnection);
    connect(progressSlider, SIGNAL(sliderReleased()), this, SLOT(disableSliderMoveMode()), Qt::DirectConnection);
    sliderLayout->addWidget(progressSlider);

    progressText = new QLabel();
    progressText->setAlignment(Qt::AlignCenter);
    QPalette palette;
    QBrush brush(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    progressText->setPalette(palette);
    sliderLayout->addWidget(progressText);

    connect(this, SIGNAL(currentTrackEnded()), soundController, SLOT(next()), Qt::DirectConnection);
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

    //progressText->setPlainText(displayPos.toString("m:ss") + "/" + displayLength.toString("m:ss"));
    progressText->setText(displayPos.toString("m:ss") + "/" + displayLength.toString("m:ss"));
    /*QTextCursor cursor = progressText->textCursor();
    QTextBlockFormat bfmt = cursor.blockFormat();
    bfmt.setAlignment(Qt::AlignRight);
    cursor.setBlockFormat(bfmt);
    progressText->setTextCursor(cursor);
*/
    checkTrackEnded();
}

void SoundControllerView::checkTrackEnded()
{
    if (this->soundSystem->getCurPositionInPerc() >= 1.0)
    {
        emit currentTrackEnded();
    }
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
