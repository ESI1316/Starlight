#include "dest.h"
#include "level.h"

Dest::Dest(const Point & p, int e)
    : pos {p}, edge {e}, light{false}
{
    // TODO : valider edge
}

const Point & Dest::getPosition() const
{
    return this->pos;
}

int Dest::getEdge() const
{
    return this->edge;
}

bool Dest::isLightedUp() const
{
    return this->light;
}

void Dest::setLightedUp(const bool q)
{
    this->light = q;
}

std::ostream & operator<<(std::ostream & out, const Dest & d)
{
    out << "Dest --- Position : " << d.getPosition()
        << " , Edge : " << d.getEdge()
        << " , lighted up : " << d.isLightedUp();
    return out;
}
