#include "model/wall.hpp"
#include "model/level.hpp"
#include "model/starlightexception.hpp"

Wall::Wall(const Point & start, const Point & end)
    : Element(), start{start}, end{end}
{
    if (start == end)
        throw StarlightException("Les points ne peuvent être confondus");

    // Tester que point >= (0, 0)
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


bool Wall::operator==(const Wall & wall) const
{
    return this->start == wall.start
            && this->end == wall.end
            && Element::operator ==(wall);
}

std::ostream & operator<<(std::ostream & out, const Wall & wall)
{
    out << "Wall --- " << std::endl
        << "Start : "  << wall.getStart()
        << ", End : " << wall.getEnd();

    return out;
}
