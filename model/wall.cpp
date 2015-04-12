#include "model/wall.hpp"

#include "model/level.hpp"
#include "model/starlightexception.hpp"
#include "model/ray.hpp"

Wall::Wall(const Point & start, const Point & end)
    : Element(), Line(start, end), start{start}, end{end}
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

void Wall::reactToRay(Ray ray) {}

Point * Wall::includeRay(const Ray & ray) const
{
    Point * intersection = Line::getIntersectionPoint(ray);

    if(intersection != 0)
    {
        double minX = std::min(this->start.getX(), this->end.getX());
        double minY = std::min(this->start.getY(), this->end.getY());
        double maxX = std::max(this->start.getX(), this->end.getX());
        double maxY = std::max(this->start.getY(), this->end.getY());

        if(intersection->getX() < minX || intersection->getX() > maxX
                || intersection->getY() < minY || intersection->getY() > maxY
                || !ray.isInTrajectory(*intersection))
        {
            delete intersection;
            intersection = 0;
        }
    }

    return intersection;
}


bool Wall::operator==(const Wall & wall) const
{
    return this->start == wall.start
            && this->end == wall.end;
}

bool Wall::operator!=(const Wall & wall) const
{
    return !(*this == wall);
}

std::ostream & operator<<(std::ostream & out, const Wall & wall)
{
    out << "Wall --- " << std::endl
        << "Start : "  << wall.getStart() << std::endl
        << "End : " << wall.getEnd() << std::endl;

    return out;
}
