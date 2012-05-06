#include "Menu.hpp"

Menu::Menu()
{
    fileMenu = new QMenu();
    aboutMenu = new QMenu();

    addFilesAction = new QAction(tr("Add &Files"), this);
    addFilesAction->setShortcut(tr("Ctrl+F"));
    aboutAction = new QAction(tr("A&bout"), this);
    aboutAction->setShortcut(tr("Ctrl+B"));
    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setShortcut(tr("Ctrl+Q"));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);

    connect(addFilesAction, SIGNAL(triggered()), this, SLOT(addFiles()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    //connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    //connect(exitAction, SIGNAL(triggered()), this, SLOT(mainWindow->close()));

    setup();
}

void Menu::setup()
{
    fileMenu->addMenu(tr("&File"));
    fileMenu->addAction(addFilesAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    aboutMenu->addMenu(tr("&Help"));
    aboutMenu->addAction(aboutAction);
    aboutMenu->addAction(aboutQtAction);
}

void Menu::about()
{
    QMessageBox::information(this, tr("About Music Player"),
        tr("The Music Player example shows how to use Phonon - the multimedia"
           " framework that comes with Qt - to create a simple music player."));
}
