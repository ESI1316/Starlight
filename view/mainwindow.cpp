#include "view/mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent}, mainMenu{new MainMenu{this}},
    levelView{new LevelView{this}}
{
    this->setWindowTitle("Starlight");
    //ui->setupUi(this);
    QObject::connect(this->mainMenu, SIGNAL(newLevelFileSelected(const QString)),
                     this->levelView, SLOT(setLevelFilePath(const QString)));
    QObject::connect(this->levelView, SIGNAL(displayingStarted()), this, SLOT(displayLevel()));
    QObject::connect(this->levelView, SIGNAL(displayingStopped()), this, SLOT(displayMainMenu()));
    this->setCentralWidget(this->mainMenu);
}

MainWindow::~MainWindow() {}

void MainWindow::displayMainMenu()
{
    this->setCentralWidget(this->mainMenu);
}

void MainWindow::displayLevel()
{
    this->setCentralWidget(this->levelView);
}
