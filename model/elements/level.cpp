#include "model/elements/level.hpp"

#include <iostream>

#include "model/elements/element.hpp"
#include "model/geometry/point.hpp"

Level::Level(const double width, const double height)
    : width{width}, height{height},
      walls { Wall{Point{0., 0.}, Point{0., height}},
              Wall{Point{0., height}, Point{width, height}},
              Wall{Point{width, height}, Point{width, 0.}},
              Wall{Point{width, 0.}, Point{0., 0.}} }
{
    if(utilities::lessOrEquals(width, 0))
        throw StarlightException("Hauteur doit être strict. positive");
    if(utilities::lessOrEquals(height, 0))
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

const std::vector<Wall> & Level::getWalls() const
{
    return this->walls;
}

void Level::addWall(const Wall & wall)
{
    this->walls.push_back(wall);
}

const std::vector<Mirror> & Level::getMirrors() const
{
    return this->mirrors;
}

void Level::addMirror(Mirror mirror)
{
    mirror.setLevel(this);
    this->mirrors.push_back(mirror);
}

const std::vector<Crystal> & Level::getCrystals() const
{
    return this->crystals;
}

void Level::addCrystal(Crystal crystal)
{
    crystal.setLevel(this);
    this->crystals.push_back(crystal);
}

const std::vector<Lens> & Level::getLenses() const
{
    return this->lenses;
}

void Level::addLens(Lens lens)
{
    lens.setLevel(this);
    this->lenses.push_back(lens);
}

const std::vector<Ray> & Level::getRays() const
{
    return this->rays;
}

void Level::setRays(const std::vector<Ray> & rays)
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
    this->computeRay(Ray{this->source.getPosition(),
                        this->source.getAngle(),
                        this->source.getWaveLength()});
}

bool Level::thereIsAnExplodedNuke() const
{
    bool nukeExp = false;

    for (auto it = this->nukes.begin(); (it != this->nukes.end()) && !nukeExp; ++it)
        nukeExp = it->isLightedUp();

    return nukeExp;
}

void Level::computeRay(Ray ray)
{
    std::map<Point *, Element *> candidates = this->getEltsInTrajectory(ray);
    auto it = candidates.begin();
    Point * nextInters = it->first;
    Element * nextElt = it->second;

    for (++it; it != candidates.end(); ++it)
    {
        if (ray.getStart().distanceFrom(*nextInters) > ray.getStart().distanceFrom(*it->first))
            delete nextInters, nextInters = it->first, nextElt = it->second;
        else
            delete it->first;
    }

    ray.setEnd(*nextInters);
    this->rays.push_back(ray);
    nextElt->reactToRay(ray);

    delete nextInters;
}

std::map<Point *, Element *> Level::getEltsInTrajectory(const Ray & ray)
{
    std::map<Point *, Element *> candidates;
    Point * inters;

    for (auto & elt : this->walls)
        if((inters = elt.includeRay(ray)))
            candidates[inters] = &elt;

    for (auto & elt : this->mirrors)
        if((inters = elt.includeRay(ray)))
            candidates[inters] = &elt;

    for (auto & elt : this->crystals)
        if((inters = elt.includeRay(ray)))
            candidates[inters] = &elt;

    for (auto & elt : this->lenses)
        if((inters = elt.includeRay(ray)))
            candidates[inters] = &elt;

    for (auto & elt : this->nukes)
        if((inters = elt.includeRay(ray)))
            candidates[inters] = &elt;

    if ((inters = this->dest.includeRay(ray)))
            candidates[inters] = &this->dest;

    return candidates;
}
