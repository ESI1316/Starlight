#include "view/windows/mainwindow.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>

#include <iostream>

#include "view/windows/levelview.hpp"
#include "view/windows/mainmenu.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent}, mainMenu{new MainMenu}, levelView{new LevelView}
{
    this->setWindowTitle(tr("Starlight"));
    QObject::connect(this->mainMenu, SIGNAL(newLevelFileSelected(const QString)),
                     this->levelView, SLOT(setLevelFilePath(const QString)));
    QObject::connect(this->levelView, SIGNAL(displayingStarted()), this, SLOT(displayLevel()));
    QObject::connect(this->levelView, SIGNAL(displayingStopped()), this, SLOT(displayMainMenu()));

    this->setCentralWidget(new QWidget);
    this->displayMainMenu();
}

MainWindow::~MainWindow() {}

void MainWindow::displayMainMenu()
{
    this->levelView->setParent(0);
    this->levelView->hide();
    this->setCentralWidget(this->mainMenu);
    this->mainMenu->show();
    this->adjustSize();
}

void MainWindow::displayLevel()
{
    this->mainMenu->setParent(0);
    this->mainMenu->hide();
    this->setCentralWidget(this->levelView);
    this->levelView->show();
}
