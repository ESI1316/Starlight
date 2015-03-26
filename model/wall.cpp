#include "wall.hpp"
#include "level.hpp"
#include "starlightexception.hpp"

Wall::Wall(const Point & start, const Point & end)
    : Element()
{
    if (start == end)
        throw new StarlightException("Les points ne peuvent être confondus");

    this->start = start;
    this->end = end;
}

const Point & Wall::getStart() const
{
    return this->start;
}

const Point & Wall::getEnd() const
{
    return this->end;
}

void Wall::reactToRay(Ray & ray)
{
    throw new StarlightException("Not implemented yet");
}

bool Wall::includePoint(Point & point)
{
    throw new StarlightException("Not implemented yet");
}

Wall & Wall::operator=(const Wall & wall)
{
    this->start = wall.start;
    this->end = wall.end;

    return *this;
}


std::ostream & operator<<(std::ostream & out, const Wall & wall)
{
    out << "Wall --- "
        << "Start : "  << wall.getStart()
        << ", End : " << wall.getEnd();

    return out;
}
