#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <phonon/audiooutput.h>
#include <phonon/seekslider.h>
#include <phonon/mediaobject.h>
#include <phonon/volumeslider.h>
#include <phonon/backendcapabilities.h>
#include <QList>

#include "Menu.hpp"

QT_BEGIN_NAMESPACE
class QAction;
class QTableWidget;
class QLCDNumber;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow();

	private slots:
		void stateChanged(Phonon::State newState, Phonon::State oldState);
		void tick(qint64 time);
		void sourceChanged(const Phonon::MediaSource &source);
		void metaStateChanged(Phonon::State newState, Phonon::State oldState);
		void aboutToFinish();
		void tableClicked(int row, int column);
		void addFiles();

	private:
		void setupActions();
		void setupUi();

		Menu* menu;

		Phonon::SeekSlider* seekSlider;
		Phonon::MediaObject* mediaObject;
		Phonon::MediaObject* metaInformationResolver;
		Phonon::AudioOutput* audioOutput;
		Phonon::VolumeSlider* volumeSlider;
		QList<Phonon::MediaSource> sources;

		QAction* playAction;
		QAction* pauseAction;
		QAction* stopAction;
		QAction* nextAction;
		QAction* previousAction;
		QLCDNumber* timeLcd;
		QTableWidget* musicTable;
};

#endif
