#include "crystal.hpp"
#include "starlightexception.hpp"
#include "level.hpp"


Crystal::Crystal(const Point & center, const int radius, const int amplifier)
    : Element(), center {center}, amplifier {amplifier}
{
    if(radius <= 0)
        throw new StarlightException("Le rayon doit être strictement positif");

    this->radius = radius;
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
    throw new StarlightException("Not implemented yet");
}

bool Crystal::includePoint(Point & point)
{
    throw new StarlightException("Not implemented yet");
}

Crystal & Crystal::operator =(const Crystal & crystal)
{
    this->center = crystal.center;
    this->radius = crystal.radius;
    this->amplifier = crystal.amplifier;

    return *this;
}

std::ostream & operator<<(std::ostream & out, const Crystal & crystal)
{
    out << "Crystal --- Center : " << crystal.getCenter()
        << " , Radius : " << crystal.getRadius()
        << " , Modifier : " << crystal.getAmplifier();
    return out;
}
