#include "model/elements/wall.hpp"

#include "model/elements/level.hpp"
#include "model/exception/starlightexception.hpp"
#include "model/elements/ray.hpp"

Wall::Wall(const Point & start, const Point & end)
    : Element(), Line{start, end}, start{start}, end{end}
{
    if (start == end)
        throw StarlightException{"Les points ne peuvent être confondus"};
}

void Wall::reactToRay(Ray) {}

Point * Wall::includeRay(const Ray & ray) const
{
    Point * intersection{this->getIntersectionPoint(ray)};

    if(intersection != nullptr)
    {
        double minX = std::min(this->start.getX(), this->end.getX());
        double minY = std::min(this->start.getY(), this->end.getY());
        double maxX = std::max(this->start.getX(), this->end.getX());
        double maxY = std::max(this->start.getY(), this->end.getY());

        if(intersection->getX() < minX || intersection->getX() > maxX
                || intersection->getY() < minY || intersection->getY() > maxY
                || !ray.isInTrajectory(*intersection))
        {
            delete intersection, intersection = nullptr;
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
