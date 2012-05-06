#ifndef MENU_HPP
#define MENU_HPP

#include <QMenu>
#include <QAction>
#include <QMessageBox>

//#include "MainWindow.hpp"


class Menu : public QMenu
{
	Q_OBJECT

	public:
		//Menu(MainWindow* mainWindow);
		Menu();

	private slots:

	private:
		//MainWindow* mainWindow;

		QMenu* fileMenu;
		QMenu* aboutMenu;

		QAction* addFilesAction;
		QAction* aboutAction;
		QAction* aboutQtAction;
		QAction* exitAction;

		void setup();
		void about();
};

#endif
