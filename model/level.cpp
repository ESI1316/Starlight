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

Level::Level(int w, int h) : width {w}, height {h},
    walls { {{0, 0}, {0, h}}, {{0, h}, {w, h}},
{{w, h}, {w, 0}}, {{w, 0}, {0, 0}} }

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

void Level::addWall(const Wall & newWall)
{
    this->walls.push_back(newWall);
}

const vector<Mirror> & Level::getMirrors() const
{
    return this->mirrors;
}

void Level::addMirror(const Mirror & newMirror)
{
    this->mirrors.push_back(newMirror);
}

const vector<Crystal> & Level::getCrystals() const
{
    return this->crystals;
}

void Level::addCrystal(const Crystal & newCrystal)
{
    this->crystals.push_back(newCrystal);
}

const vector<Lens> & Level::getLenses() const
{
    return this->lenses;
}

void Level::addLens(const Lens & newLens)
{
    this->lenses.push_back(newLens);
}

const vector<Ray> & Level::getRays() const
{
    return this->rays;
}

void Level::setRays(const vector<Ray> & value)
{
    this->rays = value;
}

const std::vector<Nuke> & Level::getNukes() const
{
    return this->nukes;
}

void Level::addNuke(const Nuke & newNuke)
{
    this->nukes.push_back(newNuke);
}

void Level::computeRays()
{
    Ray ray(this->s.getPosition(),
                    this->s.getPosition(),
                    this->s.getWavelength());
    this->computeRay(ray);
    throw string {"todo !"};
}

void Level::computeRay(Ray &)
{

}
