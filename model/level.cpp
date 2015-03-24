#ifdef _WINT32
#include <windows.h>
#else
#include <X11/Xlib.h>
#endif

#include <string>
#include "level.h"
#include "crystal.h"
#include "dest.h"
#include "lens.h"
#include "mirror.h"
#include "ray.h"
#include "source.h"
#include "wall.h"
#include "point.h"
#include "nuke.h"
#include "starlightexception.hpp"

using namespace std;

Level::Level(int width, int height)
    : width {width}, height {height},
      walls { {{0, 0}, {0, height}}, {{0, height}, {width, height}},
{{width, height}, {width, 0}}, {{width, 0}, {0, 0}} }

{
    // TODO : valider width et height
}

const Source & Level::getSource() const
{
    return this->source;
}

void Level::setSource(const Source & source)
{
    this->source = source;
}

const Dest & Level::getDestination() const
{
    return this->dest;
}

void Level::setDestination(const Dest & dest)
{
    this->dest = dest;
}

const vector<Wall> & Level::getWalls() const
{
    return this->walls;
}

void Level::addWall(const Wall & wall)
{
    this->walls.push_back(wall);
}

const vector<Mirror> & Level::getMirrors() const
{
    return this->mirrors;
}

void Level::addMirror(const Mirror & mirror)
{
    this->mirrors.push_back(mirror);
}

const vector<Crystal> & Level::getCrystals() const
{
    return this->crystals;
}

void Level::addCrystal(const Crystal & crystal)
{
    this->crystals.push_back(crystal);
}

const vector<Lens> & Level::getLenses() const
{
    return this->lenses;
}

void Level::addLens(const Lens & lens)
{
    this->lenses.push_back(lens);
}

const vector<Ray> & Level::getRays() const
{
    return this->rays;
}

void Level::setRays(const vector<Ray> & rays)
{
    this->rays = rays;
}

const std::vector<Nuke> & Level::getNukes() const
{
    return this->nukes;
}

void Level::addNuke(const Nuke & nuke)
{
    this->nukes.push_back(nuke);
}

void Level::computeRays()
{
    Ray ray(this->source.getPosition(),
            this->source.getPosition(),
            this->source.getWavelength()
            );

    this->computeRay(ray);
    throw string {"todo !"};
}

void Level::computeRay(Ray &)
{

}
