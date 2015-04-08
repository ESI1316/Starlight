#include "model/dest.hpp"
#include "model/level.hpp"
#include "model/starlightexception.hpp"

Dest::Dest(const Point & position, const int edge)
    : Element(), Rectangle(edge, edge, position), light{false}
{}

const Point & Dest::getPosition() const
{
    return this->upLeftCorner;
}

int Dest::getEdge() const
{
    return this->height;
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
    return this->light == dest.light
            && Rectangle::operator ==(dest)
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
