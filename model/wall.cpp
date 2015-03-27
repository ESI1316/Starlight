#include "wall.hpp"
#include "level.hpp"
#include "starlightexception.hpp"

Wall::Wall(const Point & start, const Point & end)
    : Element(), start{start}, end{end}
{
    if (start == end)
        throw StarlightException("Les points ne peuvent être confondus");
}

const Point & Wall::getStart() const
{
    return this->start;
}

const Point & Wall::getEnd() const
{
    return this->end;
}

void Wall::reactToRay(Ray & ray) {}

    bool Wall::includeRay(const Ray &) const
{
    throw StarlightException("Not implemented yet");
}

Wall & Wall::operator=(const Wall & wall)
{
    this->start = wall.start;
    this->end = wall.end;
    this->setLevel(wall.getLevel());
    return *this;
}


std::ostream & operator<<(std::ostream & out, const Wall & wall)
{
    out << "Wall --- "
        << "Start : "  << wall.getStart()
        << ", End : " << wall.getEnd();

    return out;
}
