#include "view/windows/mainwindow.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include <QtMultimedia/QSound>

#include <iostream>

#include "view/windows/levelview.hpp"
#include "view/windows/mainmenu.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent}, mainMenu{new MainMenu}, levelView{new LevelView},
    bar{new QMenuBar}, menu{new QMenu("Menu")}
{
    this->setWindowTitle(tr("Starlight"));
    this->setMenuBar();
    this->connectAll();

    this->setCentralWidget(new QWidget);
    this->displayMainMenu();
}

MainWindow::~MainWindow() {}

void MainWindow::setMenuBar()
{
    this->menu->addAction(tr("&Recommencer"), this->levelView, SLOT(loadLevelFromFile()), QKeySequence("CTRL+R"));
    this->menu->addAction(tr("Retour au &menu"), this, SLOT(displayMainMenu()), QKeySequence("CTRL+M"));
    this->menu->addAction(tr("&Quitter le jeu"), this, SLOT(close()), QKeySequence("CTRL+Q"));

    this->bar->addMenu(this->menu);
    this->bar->addAction("?", this->mainMenu, SLOT(displayRules()));

    this->setMenuWidget(this->bar);
}

void MainWindow::connectAll()
{
    QObject::connect(this->mainMenu, SIGNAL(newLevelFileSelected(const QString)),
                     this->levelView, SLOT(setLevelFilePath(const QString)));
    QObject::connect(this->levelView, SIGNAL(displayingStarted()), this, SLOT(displayLevel()));
    QObject::connect(this->levelView, SIGNAL(displayingStopped()), this, SLOT(displayMainMenu()));
}

void MainWindow::displayMainMenu()
{
    this->menuBar()->hide();
    this->levelView->setParent(0);
    this->levelView->hide();
    this->setCentralWidget(this->mainMenu);
    this->mainMenu->show();
    this->adjustSize();
}

void MainWindow::displayLevel()
{
    this->menuBar()->show();
    this->mainMenu->setParent(0);
    this->mainMenu->hide();
    this->setCentralWidget(this->levelView);
    this->levelView->show();
}
