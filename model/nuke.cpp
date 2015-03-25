#include "nuke.hpp"
#include "level.hpp"
#include "starlightexception.hpp"

Nuke::Nuke(const Point & position, const int radian)
    : position{position}
{
    if (radian <= 0)
        throw new StarlightException("Le rayon de la bombe doit être strict. positif");

    this->radian = radian;
    // TODO : valider rad :: Simon : OK ?
}

const Point &Nuke::getLocation() const
{
    return this->position;
}

int Nuke::getRadius() const
{
    return this->radian;
}

bool Nuke::isLightedUp() const
{
    return this->light;
}

void Nuke::setLightedUp(const bool light)
{
    this->light = light;
}

Nuke & Nuke::operator=(const Nuke & nuke)
{
    this->position = nuke.position;
    this->radian = nuke.radian;
    this->light = nuke.light;
    this->level = nuke.level;

    return *this;
}

std::ostream & operator<<(std::ostream & out, const Nuke & nuke)
{
    out << "Nuke --- Position : " << nuke.getLocation()
        << " , Radius : " << nuke.getRadius()
        << " On : " << nuke.isLightedUp();

    return out;
}
