#include "nuke.h"

Nuke::Nuke(const Point & p, int r) : pos {p}, rad {r}
{
    // TODO : valider rad
}

const Point &Nuke::getLocation() const
{
    return this->pos;
}

int Nuke::getRadius() const
{
    return this->rad;
}

bool Nuke::isLightedUp() const
{
    return this->light;
}

void Nuke::setLightedUp(bool q)
{
    this->light = q;
}

std::ostream & operator<<(std::ostream & out, const Nuke & s)
{
    out << "Nuke --- Position : " << s.pos << " , Radius : " << s.rad <<
        " On : " << s.light;
    return out;
}
