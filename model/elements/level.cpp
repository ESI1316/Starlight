#include "model/elements/level.hpp"

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
        throw StarlightException{"Hauteur doit être strict. positive"};
    if(utilities::lessOrEquals(height, 0))
        throw StarlightException{"Largeur doit être strict. positive"};
}

void Level::setDestination(const Dest & dest)
{
    this->dest = dest;
}

void Level::addWall(const Wall & wall)
{
    this->walls.push_back(wall);
}

void Level::setSource(const Source & source)
{
    this->source = source;
    this->source.setLevel(this);
}

void Level::addMirror(Mirror mirror)
{
    mirror.setLevel(this);
    this->mirrors.push_back(mirror);
}

void Level::addCrystal(Crystal crystal)
{
    crystal.setLevel(this);
    this->crystals.push_back(crystal);
}

void Level::addLens(Lens lens)
{
    lens.setLevel(this);
    this->lenses.push_back(lens);
}

void Level::setRays(const std::vector<Ray> & rays)
{
    this->rays = rays;
}

void Level::addNuke(const Nuke & nuke)
{
    this->nukes.push_back(nuke);
}

void Level::computeRays()
{
    if (this->source.isOn())
    {
        this->rays.clear();
        this->computeRay(Ray{this->source.getPosition(), this->source.getAngle(),
                            this->source.getWaveLength()});
        this->notifyViews();
    }
}

void Level::addView(LevelView * newView)
{
    this->views.push_back(newView);
}

void Level::notifyViews()
{
    for (auto view : this->views)
        view->updateDisplay();
}

bool Level::thereIsAnExplodedNuke() const
{
    bool nukeExp{false};

    for (auto it = this->nukes.begin(); (it != this->nukes.end()) && !nukeExp; ++it)
        nukeExp = it->isLightedUp();

    return nukeExp;
}

void Level::computeRay(Ray ray)
{
    std::map<Point *, Element *> candidates{this->getEltsInTrajectory(ray)};
    auto it = candidates.begin();
    Point * nextInters{it->first};
    Element * nextElt{it->second};

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

    delete nextInters, nextInters = nullptr;
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
