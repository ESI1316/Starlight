#include "levelview.h"

#include "model/elements/levelFactory.hpp"

LevelView::LevelView(QWidget *parent) : QFrame(parent) {}

LevelView::~LevelView()
{
    if (this->level != nullptr)
        delete level;
}

void LevelView::loadLevel() const {}

void LevelView::setLevel(const QString levelFile) const {}

void LevelView::switchRaysDisplay() {}



