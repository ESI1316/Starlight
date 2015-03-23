#include "crystal.h"


Crystal::Crystal(const Point & p, int r, int m) : center {p}, rad {r},
mod {m}
{
    // TODO : valider rad (et mod ?)
}

const Point & Crystal::getCenter() const
{
    return this->center;
}

int Crystal::getModifier() const
{
    return this->mod;
}

int Crystal::getRadius() const
{
    return this->rad;
}

std::ostream & operator<<(std::ostream & out, const Crystal & c)
{
    out << "Crystal --- Center : " << c.getCenter()
        << " , Radius : " << c.getRadius()
        << " , Modifier : " << c.getModifier();
    return out;
}
