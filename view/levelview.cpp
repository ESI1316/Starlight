#include "view/levelview.hpp"

#include "model/elements/levelFactory.hpp"

#include <QMessageBox>

LevelView::LevelView(QWidget *parent) : QFrame{parent} {}

LevelView::~LevelView()
{
    if (this->level != nullptr)
        delete level;
}

void LevelView::setLevelFilePath(const QString levelFile)
{
    this->displayedLevelFilePath = levelFile.toStdString();
    this->loadLevelFromFile();
}

void LevelView::loadLevelFromFile()
{
    delete this->level;
    this->level = levelFactory::getLevelFromFile(this->displayedLevelFilePath);

    this->setFixedSize(this->level->getWidth(), this->level->getHeight());
    this->setStyleSheet("background-color:white;"
                        "border-style: outset;"
                        "border-width: 2px;"
                        "border-color: black");

    emit displayingStarted();
}

void LevelView::displayEndOfGame()
{
    /* bugs :
     * - ne réaffiche pas le menu principal quand on séléctionne
     *   "Retour au menu principal"
     * - la msgBox resize la fenetre et ça fait chier
     */

    QMessageBox msgBox;
    QPushButton *quitB = msgBox.addButton("Retour au menu principal", QMessageBox::YesRole);

    msgBox.addButton("Recommencer", QMessageBox::NoRole);
    msgBox.setText("Fin de partie");
    msgBox.setInformativeText(this->level->getDestination().isLightedUp() ?
                                  "Bravo !\nVous avez gagné" :
                                  "Perdu !\nUne bombe a explosée");
    msgBox.setWindowFlags(msgBox.windowFlags() ^ Qt::WindowCloseButtonHint);
    msgBox.exec();

    if(((QPushButton*) msgBox.clickedButton()) == quitB)
        emit displayingStopped();
    else
        this->loadLevelFromFile();
}

void LevelView::switchRaysDisplay() {}
