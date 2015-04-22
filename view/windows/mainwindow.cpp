#include "view/windows/mainwindow.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>

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
    this->menu->addAction(tr("Main menu"), this, SLOT(displayMainMenu()), QKeySequence(tr("CTRL+M")));
    this->menu->addAction(tr("Close level"));
    this->menu->addAction(tr("Quit"), this, SLOT(close()), QKeySequence(tr("CTRL+Q")));

    this->bar->addMenu(this->menu);
    this->bar->addAction("?");

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
