#include "view/levelview.hpp"

#include "model/elements/levelFactory.hpp"

#include <QMenu>

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

void LevelView::switchRaysDisplay() {}

void LevelView::loadLevelFromFile()
{
    delete this->level;
    this->level = levelFactory::getLevelFromFile(this->displayedLevelFilePath);

    this->setFixedSize(this->level->getWidth(), this->level->getHeight());
    //loading level then

    emit displayingStarted();
}


