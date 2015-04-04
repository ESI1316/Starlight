#include <cmath>
#include "model/nuke.hpp"
#include "model/level.hpp"
#include "model/starlightexception.hpp"

Nuke::Nuke(const Point & position, const double radius)
    : Element(), position{position}, radius{radius}
{
    if (radius <= 0.)
        throw StarlightException("Le rayon de la bombe doit être "
                                 "strict. positif");
}

const Point &Nuke::getLocation() const
{
    return this->position;
}

int Nuke::getRadius() const
{
    return this->radius;
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

Point * Nuke::includeRay(const Ray & ray) const
{
    throw StarlightException("Not implemented yet");
}

bool Nuke::operator==(const Nuke & nuke) const
{
    return this->position == nuke.position
            && utilities::equals(this->radius, nuke.radius)
            && this->light == nuke.light
            && Element::operator ==(nuke);
}

bool Nuke::operator!=(const Nuke & nuke) const
{
    return !(*this == nuke);
}

std::ostream & operator<<(std::ostream & out, const Nuke & nuke)
{
    out << "Nuke --- Position : " << nuke.getLocation()
        << " , Radius : " << nuke.getRadius()
        << " On : " << nuke.isLightedUp();

    return out;
}
