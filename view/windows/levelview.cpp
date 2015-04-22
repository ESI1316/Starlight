#include "view/windows/levelview.hpp"

#include <QMessageBox>
#include <QPushButton>
#include <QMainWindow>
#include <QtMultimedia/QSound>

#include "model/elements/levelFactory.hpp"
#include "model/elements/level.hpp"
#include "view/viewutilities.hpp"
#include "view/dynamicElements/mirrorview.hpp"
#include "view/dynamicElements/sourceview.hpp"

LevelView::LevelView(QWidget *parent)
    : QGraphicsView {parent}, scene{new QGraphicsScene}, level{nullptr}
{
    this->setRenderHint(QPainter::Antialiasing);
    this->setScene(this->scene);
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
}

void LevelView::loadLevelFromFile()
{
    if (this->level != nullptr)
    {
        delete this->level, this->level = nullptr;
        this->mirrors.clear();
        this->rays.clear();
    }

    this->scene->clear();
    this->level = levelFactory::getLevelFromFile(this->displayedLevelFilePath);
    this->level->addView(this);

    this->setFixedSize(this->level->getWidth() + 20, this->level->getHeight() + 20);

    this->scene->addItem(new SourceView(&this->level->getSource()));

    for (auto & lens : this->level->getLenses())
        this->scene->addItem(viewUtilities::getEllipse(lens, Qt::blue, 2));

    for (auto & crystal : this->level->getCrystals())
        this->scene->addItem(viewUtilities::getEllipse(crystal, Qt::green, 2));

    for (auto & nuke : this->level->getNukes())
    {
        this->scene->addItem(viewUtilities::getEllipse(nuke, Qt::red, 2));
    }

    for (auto & wall : this->level->getWalls())
        this->scene->addItem(viewUtilities::getLine(wall.getStart(), wall.getEnd(),
                                                    Qt::black, 4));

    for (auto & mirror : this->level->getMirrors())
    {
        MirrorView * mir = new MirrorView(&mirror);
        this->scene->addItem(mir);
        this->mirrors.push_back(mir);
    }

    this->scene->addItem(viewUtilities::getRect(this->level->getDestination(),
                                                QColor{255, 154, 222}, 4));
    emit displayingStarted();
}

void LevelView::updateDisplay()
{
    if (!this->isHidden() && this->level != nullptr)
    {
        for (auto & ray : this->rays)
            delete ray;

        this->rays.clear();

        for (auto & ray : this->level->getRays())
        {
            QGraphicsLineItem * rayView = viewUtilities::getLine
                    (ray.getStart(), ray.getEnd(), viewUtilities::waveLengthToColor(ray), 2);
            this->scene->addItem(rayView);
            this->rays.push_back(rayView);
        }

        if (this->level->getDestination().isLightedUp()
                || this->level->thereIsAnExplodedNuke())
        {
            QSound::play(this->level->thereIsAnExplodedNuke()
                           ? "./ressources/sounds/bomb.wav"
                           : "./ressources/sounds/win.wav");

            this->displayEndOfGame();
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
