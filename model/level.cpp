#include "level.h"

#include <string>

using namespace std;

Level::Level(int w, int h) : width {w}, height {h},
walls { {{0, 0}, {0, h}}, {{0, h}, {w, h}},
    {{w, h}, {w, 0}}, {{w, 0}, {0, 0}}
}
{
    // TODO : valider width et height
}

const Source & Level::getSource() const
{
    return this->s;
}

void Level::setSource(const Source & value)
{
    this->s = value;
}

const Dest & Level::getDestination() const
{
    return this->d;
}

void Level::setDestination(const Dest & value)
{
    this->d = value;
}

const vector<Wall> & Level::getWalls() const
{
    return this->walls;
}

const vector<Mirror> & Level::getMirrors() const
{
    return this->mirrors;
}

const vector<Crystal> & Level::getCrystals() const
{
    return this->crystals;
}

const vector<Lens> & Level::getLenses() const
{
    return this->lenses;
}

const vector<Ray> & Level::getRays() const
{
    return this->rays;
}

void Level::setRays(const vector<Ray> & value)
{
    this->rays = value;
}

void Level::computeRays()
{
    throw string {"todo !"};
}
