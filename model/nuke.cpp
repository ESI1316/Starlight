#include "nuke.hpp"
#include "level.hpp"
#include "starlightexception.hpp"

Nuke::Nuke(const Point & position, const int radian)
    : Element(), position{position}, radian{radian}
{
    if (radian <= 0)
        throw StarlightException("Le rayon de la bombe doit être strict. positif");
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

void Nuke::reactToRay(Ray & ray)
{
    this->setLightedUp(true);
}

bool Nuke::includeRay(const Ray & ray) const
{
    throw StarlightException("Not implemented yet");
}

std::ostream & operator<<(std::ostream & out, const Nuke & nuke)
{
    out << "Nuke --- Position : " << nuke.getLocation()
        << " , Radius : " << nuke.getRadius()
        << " On : " << nuke.isLightedUp();

    return out;
}
