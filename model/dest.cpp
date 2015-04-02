#include "model/dest.hpp"
#include "model/starlightexception.hpp"
#include "model/level.hpp"

Dest::Dest(const Point & position, const int edge)
    : Element(), position{position}, edge{edge}, light{false}
{
    if(edge <= 0) throw StarlightException("Cotés de la destinations "
                                           "doivent être strictement "
                                           "positifs.");
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
    this->setLightedUp(true);
}

Point * Dest::includeRay(const Ray & ray) const
{
    throw StarlightException("Not implemented yet");
}

bool Dest::operator==(const Dest & dest) const
{
    return this->position == dest.position
            && this->edge == dest.edge
            && this->light == dest.light
            && Element::operator==(dest);
}

bool Dest::operator!=(const Dest & dest) const
{
    return !(*this == dest);
}

std::ostream & operator<<(std::ostream & out, const Dest & dest)
{
    out << "Dest --- " << std::endl
        << "Position : " << dest.getPosition()
        << " , Edge : " << dest.getEdge()
        << " , lighted up : " << dest.isLightedUp();

    return out;
}
