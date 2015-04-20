#include "view/windows/levelview.hpp"

#include <QMessageBox>
#include <QPainter>
#include <QPushButton>
#include <QMainWindow>

#include <iostream>

#include "model/elements/levelFactory.hpp"
#include "view/viewutilities.hpp"
#include "model/elements/level.hpp"
#include "view/dynamicElements/sourceView.hpp"

LevelView::LevelView(QWidget *parent)
    : QFrame{parent}, level{nullptr}, source{nullptr}
{
    this->setStyleSheet("background-color:white;");
}

LevelView::~LevelView()
{
    if (this->level != nullptr)
    {
        delete this->level;
        delete this->source;
    }
}

void LevelView::setLevelFilePath(const QString levelFile)
{
    this->displayedLevelFilePath = levelFile.toStdString();
    this->loadLevelFromFile();
}

void LevelView::loadLevelFromFile()
{
    if (this->level != nullptr)
    {
        delete this->level;
        delete this->source;
    }

    this->level = levelFactory::getLevelFromFile(this->displayedLevelFilePath);
    this->level->addView(this);
    this->source = new SourceView{&this->level->getSource(), this};
    this->source->show();

    this->setFixedSize(this->level->getWidth(), this->level->getHeight());

    emit displayingStarted();
}

void LevelView::updateDisplay()
{
    this->update();

    if (this->level->getDestination().isLightedUp() || this->level->thereIsAnExplodedNuke())
        this->displayEndOfGame();
}

void LevelView::paintEvent(QPaintEvent*)
{
    if (this->level != nullptr)
    {
        QPainter painter(this);

        painter.setRenderHints(QPainter::Antialiasing, true);

        viewUtilities::drawRectangle(this->level->getDestination(), painter,
                                     QColor(255, 105, 180), 2,
                                     this->level->getDestination().isLightedUp());

        for (auto & lens : this->level->getLenses())
            viewUtilities::drawEllipse(lens, painter, Qt::blue, 2);

        for (auto & crystal : this->level->getCrystals())
            viewUtilities::drawEllipse(crystal, painter, Qt::green, 2);

        for (auto & nuke : this->level->getNukes())
            viewUtilities::drawEllipse(nuke, painter, Qt::red, 2);

        for (auto & wall : this->level->getWalls())
            viewUtilities::drawLine(wall.getStart(), wall.getEnd(), painter, Qt::black, 4);

        if (this->level->getSource().isOn())
        {
            for (auto & ray : this->level->getRays())
                viewUtilities::drawLine(ray.getStart(), ray.getEnd(), painter, Qt::black, 1);
        }
    }
}

void LevelView::displayEndOfGame()
{
    QMessageBox msgBox(this);
    QPushButton *quitB = msgBox.addButton(tr("Retour au menu principal"),
                                          QMessageBox::YesRole);

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
