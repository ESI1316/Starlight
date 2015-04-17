#include "view/mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), mainMenu{new QFrame{this}}, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(this->levelView, SIGNAL(displayingStopped()), this, SLOT(displayMainMenu()));

    this->mainMenu = new QFrame(this);
    this->mainMenu->setFixedSize(300, 900);

    this->mainMenu->show();
    this->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayMainMenu()
{
    this->mainMenu->show();
}
