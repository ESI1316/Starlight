#ifdef _WINT32
#include <windows.h>
#else
#include <X11/Xlib.h>
#endif

#include <string>
#include "model/level.hpp"
#include "model/crystal.hpp"
#include "model/dest.hpp"
#include "model/lens.hpp"
#include "model/mirror.hpp"
#include "model/ray.hpp"
#include "model/source.hpp"
#include "model/wall.hpp"
#include "model/point.hpp"
#include "model/nuke.hpp"
#include "model/starlightexception.hpp"

using namespace std;

Level::Level(const double width, const double height)
    : width{width},height {height},
      walls { Wall{Point{0., 0.}, Point{0., height}},
              Wall{Point{0., height}, Point{width, height}},
              Wall{Point{width, height}, Point{width, 0.}},
              Wall{Point{width, 0.}, Point{0., 0.}} }
{
    if(width <= 0)
        throw StarlightException("Hauteur doit être strict. positive");
    if(height <= 0)
        throw StarlightException("Largeur doit être strict. positive");
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

void Level::addMirror(Mirror mirror)
{
    mirror.setLevel(this);
    this->mirrors.push_back(mirror);
}

const vector<Crystal> & Level::getCrystals() const
{
    return this->crystals;
}

void Level::addCrystal(Crystal crystal)
{
    crystal.setLevel(this);
    this->crystals.push_back(crystal);
}

const vector<Lens> & Level::getLenses() const
{
    return this->lenses;
}

void Level::addLens(Lens lens)
{
    lens.setLevel(this);
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
            this->source.getAngle(),
            this->source.getWaveLength());

    this->computeRay(ray);
}

void Level::computeRay(const Ray &)
{
    throw StarlightException("Largeur doit être strict. positive");
}
