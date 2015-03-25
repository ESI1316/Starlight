#include "wall.hpp"
#include "level.hpp"

Wall::Wall(const Point & p1, const Point & p2) : start {p1}, end {p2}
{
    // TODO : valider les points (différents ?)
}

const Point & Wall::getStart() const
{
    return this->start;
}

const Point & Wall::getEnd() const
{
    return this->end;
}

Wall & Wall::operator=(const Wall & wall)
{
    this->start = wall.start;
    this->end = wall.end;
    this->level = wall.level;

    return *this;
}

std::ostream & operator<<(std::ostream & out, const Wall & w)
{
    out << "Wall --- "
        << "Start : "  << w.getStart()
        << ", End : " << w.getEnd();

    return out;
}
