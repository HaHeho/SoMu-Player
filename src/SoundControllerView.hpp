#ifndef SOUND_CONTROLLER_VIEW_HPP
#define SOUND_CONTROLLER_VIEW_HPP

#include "BasicItem.hpp"
#include "Button.hpp"
#include "SoundController.hpp"


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

#endif // SOUND_CONTROLLER_VIEW_HPP
