#include "crystal.h"


Crystal::Crystal(const Point & center, int radius, int amplifier)
    : center {center}, radius {radius}, amplifier {amplifier}
{
    // TODO : valider radius (et amplifier ?)
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

std::ostream & operator<<(std::ostream & out, const Crystal & c)
{
    out << "Crystal --- Center : " << c.getCenter()
        << " , Radius : " << c.getRadius()
        << " , Modifier : " << c.getAmplifier();
    return out;
}
