#include "model/wall.hpp"
#include "model/level.hpp"
#include "model/starlightexception.hpp"

Wall::Wall(const Point & start, const Point & end)
    : Element(),
      Line((end.getY() - start.getY()) / (end.getX() - start.getX()),
           (start.getY() - (this->slope * start.getX())),
           0),
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
    Point * p = nullptr;
    double startx = this->getStart().getX();
    double starty = this->getStart().getY();

    double slopeWall = (this->getStart().getX() - this->getEnd().getX())
            / (this->getStart().getY() - this->getEnd().getY());
    double ind = this->getStart().getY() - (slopeWall * this->getStart().getX());

    if(slopeWall != ray.getSlope() || ind == ray.getIndepTerm())
    {
        double x = (ind - ray.getIndepTerm()) / (ray.getSlope() - slopeWall);
        double y = slopeWall * x + ind;

        p = new Point{x, y};
    }

    return p;
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
