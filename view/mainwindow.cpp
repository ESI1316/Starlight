#include "view/mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent}, ui{new Ui::MainWindow}, mainMenu{new MainMenu{this}},
    levelView{new LevelView{this}}
{
    ui->setupUi(this);
    QObject::connect(this->mainMenu, SIGNAL(newLevelFileSelected(const QString)),
                     this->levelView, SLOT(setLevelFilePath(const QString)));
    QObject::connect(this->levelView, SIGNAL(displayingStarted()), this, SLOT(displayLevel()));
    this->setCentralWidget(this->mainMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayMainMenu()
{
    this->setCentralWidget(this->mainMenu);
}

void MainWindow::displayLevel()
{
    this->setCentralWidget(this->levelView);
}
