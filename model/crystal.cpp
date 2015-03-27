#include "crystal.hpp"
#include "starlightexception.hpp"
#include "level.hpp"


Crystal::Crystal(const Point & center, const int radius, const int amplifier)
    : Element(),
      center {center},
      radius{radius},
      amplifier {amplifier}
{
    if(radius <= 0)
        throw StarlightException("Le rayon doit être strictement positif");
}

const Point & Crystal::getCenter() const
{
    return this->center;
}

int Crystal::getAmplifier() const
{
    return this->amplifier;
}

int Crystal::getRadius() const
{
    return this->radius;
}

void Crystal::reactToRay(Ray & ray)
{
    throw StarlightException("Not implemented yet");
}

bool Crystal::includePoint(Point & point)
{
    throw StarlightException("Not implemented yet");
}

Crystal & Crystal::operator =(const Crystal & crystal)
{
    this->center = crystal.center;
    this->radius = crystal.radius;
    this->amplifier = crystal.amplifier;
    this->setLevel(crystal.getLevel());

    return *this;
}

std::ostream & operator<<(std::ostream & out, const Crystal & crystal)
{
    out << "Crystal --- Center : " << crystal.getCenter()
        << " , Radius : " << crystal.getRadius()
        << " , Modifier : " << crystal.getAmplifier();
    return out;
}
