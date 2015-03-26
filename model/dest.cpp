#include "dest.hpp"
#include "starlightexception.hpp"
#include "level.hpp"

Dest::Dest(const Point & position, const int edge)
    : Element(), position{position}, edge{this->valideEdge(edge)}, light{false}
{
}

const int & Dest::valideEdge(const int & edge) const
{
    if(edge <= 0)
        throw StarlightException
            ("Cotés de la destinations doivent être strictement positifs.");

    return edge;
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

void Dest::reactToRay(Ray & ray)
{
    throw StarlightException("Not implemented yet");
}

bool Dest::includePoint(Point & point)
{
    throw StarlightException("Not implemented yet");
}

std::ostream & operator<<(std::ostream & out, const Dest & dest)
{
    out << "Dest --- Position : " << dest.getPosition()
        << " , Edge : " << dest.getEdge()
        << " , lighted up : " << dest.isLightedUp();
    return out;
}
