#include "view/windows/levelview.hpp"

#include <QMessageBox>
#include <QPushButton>
#include <QMainWindow>

#include <iostream>

#include "model/elements/levelFactory.hpp"
#include "view/viewutilities.hpp"
#include "model/elements/level.hpp"
#include "view/dynamicElements/sourceView.hpp"

LevelView::LevelView(QWidget *parent)
    : QGraphicsView {parent}, scene{new QGraphicsScene}, level{nullptr},
      source{nullptr}
{
    this->setRenderHint(QPainter::Antialiasing);
    this->setScene(this->scene);
}

LevelView::~LevelView()
{
    if (this->level != nullptr)
    {
        delete this->level;
        delete this->source;
        this->mirrors.clear();
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
        this->mirrors.clear();
    }

    this->level = levelFactory::getLevelFromFile(this->displayedLevelFilePath);
    this->level->addView(this);
    this->source = new SourceView{&this->level->getSource(), this};
    this->source->show();

    this->setFixedSize(this->level->getWidth() + 10, this->level->getHeight() + 10);

    for (auto & lens : this->level->getLenses())
        this->scene->addItem(viewUtilities::getEllipse(lens, Qt::blue, 2));

    for (auto & crystal : this->level->getCrystals())
        this->scene->addItem(viewUtilities::getEllipse(crystal, Qt::green, 2));

    for (auto & nuke : this->level->getNukes())
        this->scene->addItem(viewUtilities::getEllipse(nuke, Qt::red, 2));

    for (auto & wall : this->level->getWalls())
        this->scene->addItem(viewUtilities::getLine(wall.getStart(), wall.getEnd(),
                                                    Qt::black, 4));
    this->adjustSize();

    emit displayingStarted();
}

void LevelView::updateDisplay()
{
     if (!this->isHidden() && (this->level->getDestination().isLightedUp()
             || this->level->thereIsAnExplodedNuke()))
     {
            this->displayEndOfGame();
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
