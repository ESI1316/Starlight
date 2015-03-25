#include "dest.h"
#include "level.h"

Dest::Dest(const Point & position, const int edge)
    : position{position}, edge{edge}, light{false}
{
    // TODO : valider edge
}

const Point & Dest::getPosition() const
{
    return this->position;
}

int Dest::getEdge() const
{
    return this->edge;
}

bool Dest::isLightedUp() const
{
    return this->light;
}

void Dest::setLightedUp(const bool light)
{
    this->light = light;
}

std::ostream & operator<<(std::ostream & out, const Dest & dest)
{
    out << "Dest --- Position : " << dest.getPosition()
        << " , Edge : " << dest.getEdge()
        << " , lighted up : " << dest.isLightedUp();
    return out;
}
