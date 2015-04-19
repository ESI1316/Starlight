#include "view/levelview.hpp"

#include "model/elements/levelFactory.hpp"
#include "view/viewutilities.hpp"

#include <QMessageBox>
#include <QPainter>
#include <QPushButton>
#include <QMainWindow>

#include <iostream>

LevelView::LevelView(QWidget *parent) : QFrame{parent}, level{nullptr}
{
    this->setStyleSheet("background-color:white;");
}

LevelView::~LevelView()
{
    if (this->level != nullptr)
        delete this->level;
}

void LevelView::setLevelFilePath(const QString levelFile)
{
    this->displayedLevelFilePath = levelFile.toStdString();
    this->loadLevelFromFile();
    this->displayEndOfGame();
}

void LevelView::loadLevelFromFile()
{
    if (this->level != nullptr)
        delete this->level;

    this->level = levelFactory::getLevelFromFile(this->displayedLevelFilePath);
    this->setFixedSize(this->level->getWidth(), this->level->getHeight());

    emit displayingStarted();
}

void LevelView::paintEvent(QPaintEvent*)
{
    if (this->level != nullptr)
    {
        QPainter painter(this);

        painter.setRenderHints(QPainter::Antialiasing, true);
    }
}

void LevelView::displayEndOfGame()
{
    QMessageBox msgBox(this);
    QPushButton *quitB = msgBox.addButton(tr("Retour au menu principal"), QMessageBox::YesRole);

    msgBox.addButton(tr("Recommencer"), QMessageBox::NoRole);
    msgBox.setText(tr("<strong>Fin de partie :<strong>"));
    msgBox.setInformativeText(this->level->getDestination().isLightedUp() ?
                                  tr("<br>Bravo</br> !\nVous avez gagné") :
                                  tr("<br>Perdu</br> !\nUne bombe a explosée"));
    msgBox.setWindowFlags(msgBox.windowFlags() ^ Qt::WindowCloseButtonHint);
    msgBox.exec();

    if(((QPushButton*) msgBox.clickedButton()) == quitB)
        emit displayingStopped();
    else
        this->loadLevelFromFile();
}
