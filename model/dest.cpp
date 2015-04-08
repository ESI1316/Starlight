#include "model/dest.hpp"
#include "model/level.hpp"
#include "model/starlightexception.hpp"

Dest::Dest(const Point & position, const int edge)
    : Element(), Rectangle(edge, edge, position), position{position}, edge{edge}, light{false}
{}

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

void Dest::reactToRay(Ray &)
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
