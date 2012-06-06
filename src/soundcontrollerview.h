#ifndef SOUNDCONTROLLERVIEW_H
#define SOUNDCONTROLLERVIEW_H

#include "src/basicitem.h"
#include "src/soundcontroller.h"


class SoundControllerView : public BasicItem
{
    Q_OBJECT


public:
    explicit SoundControllerView(SoundController* sc, SoundSystem* ss, float w, float h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void init();
    void updateView();


private:
    SoundController* soundController;
    SoundSystem* soundSystem;
    QSlider* progressSlider;
    QGraphicsTextItem* progressText;
    bool sliderMoveActivated;


signals:

    
public slots:
    void enableSliderMoveMode();
    void disableSliderMoveMode();

};

#endif // SOUNDCONTROLLERVIEW_H
