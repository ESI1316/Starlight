#include "view/mainwindow.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>

#include <iostream>

#include "view/levelview.hpp"
#include "view/mainmenu.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent}, mainMenu{new MainMenu}, levelView{new LevelView}
{
    this->setWindowTitle(tr("Starlight"));
    QObject::connect(this->mainMenu, SIGNAL(newLevelFileSelected(const QString)),
                     this->levelView, SLOT(setLevelFilePath(const QString)));
    QObject::connect(this->levelView, SIGNAL(displayingStarted()), this, SLOT(displayLevel()));
    QObject::connect(this->levelView, SIGNAL(displayingStopped()), this, SLOT(displayMainMenu()));
/*
    this->setCentralWidget(this->mainMenu);
    std::cout << "----setCentral main ;----------------" << std::endl;
    std::cout << "c w " << this->centralWidget() << std::endl;
    std::cout << "menu " << this->mainMenu << std::endl;
    std::cout << "menu parent " << this->mainMenu->parent() << std::endl;
    this->setCentralWidget(this->levelView);
    std::cout << "-----setCentral levelView ;--------------" << std::endl;
    std::cout << "c w " << this->centralWidget() << std::endl;
    std::cout << "levelView " << this->levelView << std::endl;
    std::cout << "levelView parent" << this->levelView->parent() << std::endl;
    std::cout << "menu" << this->mainMenu << std::endl;
    std::cout << "menu parent " << this->mainMenu->parent() << std::endl;*/

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
}

void MainWindow::displayLevel()
{
    this->mainMenu->setParent(0);
    this->mainMenu->hide();
    this->setCentralWidget(this->levelView);
    this->levelView->show();
}
