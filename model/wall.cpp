#include "model/wall.hpp"
#include "model/level.hpp"
#include "model/starlightexception.hpp"

Wall::Wall(const Point & start, const Point & end)
    : Element(),
      Line((end.getY() - start.getY()) / (end.getX() - start.getX()),
           (start.getY() - (this->slope * start.getX())),
           (utilities::equals(start.getX(), end.getX())) ? start.getX() : 0.),
      start{start}, end{end}
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

Point * Wall::includeRay(const Ray & ray) const
{
    Point * intersection = Line::getIntersectionPoint(ray);

    if(intersection != 0)
    {
        double minX = this->start.getX() < this->end.getX()
                ? this->start.getX() : this->end.getX();
        double minY = this->start.getY() < this->end.getY()
                ? this->start.getY() : this->end.getY();
        double maxX = this->start.getX() > this->end.getX()
                ? this->start.getX() : this->end.getX();
        double maxY = this->start.getX() > this->end.getX()
                ? this->start.getX() : this->end.getY();

        if(intersection->getX() < minX || intersection->getX > maxX
                || intersection->getY() < minY || intersection->getY() > maxY)
        {
            delete intersection;
            intersection = nullptr;
        }
    }

    return intersection;
}


bool Wall::operator==(const Wall & wall) const
{
    return this->start == wall.start
            && this->end == wall.end
            && Element::operator==(wall);
}

bool Wall::operator!=(const Wall & wall) const
{
    return !(*this == wall);
}

std::ostream & operator<<(std::ostream & out, const Wall & wall)
{
    out << "Wall --- " << std::endl
        << "Start : "  << wall.getStart()
        << ", End : " << wall.getEnd();

    return out;
}
