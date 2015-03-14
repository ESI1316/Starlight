#include "wall.h"

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

std::ostream & operator<<(std::ostream & out, const Wall & w)
{
    out << "Wall --- Start : "  << w.start << ", End : " << w.end;
    return out;
}
