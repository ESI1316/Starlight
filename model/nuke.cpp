#include <cmath>
#include "model/nuke.hpp"
#include "model/level.hpp"
#include "model/starlightexception.hpp"

Nuke::Nuke(const Point & position, const double radius)
    : Element(), Ellipse{std::pow(radius, 2), std::pow(radius, 2), position}
{
    if (radius <= 0.)
        throw StarlightException("Le rayon de la bombe doit être "
                                 "strict. positif");
}

const Point &Nuke::getLocation() const
{
    return this->center;
}

int Nuke::getRadius() const
{
    return (int) std::sqrt(this->xRadius);
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
    return this->center == nuke.center
            && utilities::equals(this->getRadius(), nuke.getRadius())
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
