#include "crystal.hpp"
#include "starlightexception.hpp"
#include "level.hpp"


Crystal::Crystal(const Point & center, const int radius, const int amplifier)
    : center {center}, amplifier {amplifier}
{
    if(radius <= 0)
        throw new StarlightException("Le rayon doit être strictement positif.");

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

Crystal & Crystal::operator =(const Crystal & crystal)
{
    this->center = crystal.center;
    this->radius = crystal.radius;
    this->amplifier = crystal.amplifier;
    this->level = crystal.level;

    return *this;
}

std::ostream & operator<<(std::ostream & out, const Crystal & c)
{
    out << "Crystal --- Center : " << c.getCenter()
        << " , Radius : " << c.getRadius()
        << " , Modifier : " << c.getAmplifier();
    return out;
}
