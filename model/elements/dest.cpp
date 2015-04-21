#include "model/elements/dest.hpp"

#include "model/elements/level.hpp"
#include "model/exception/starlightexception.hpp"
#include "model/elements/ray.hpp"
#include "model/geometry/point.hpp"

Dest::Dest(const Point & position, const int edge)
    : Element(), Rectangle(edge, edge, position), light{false} {}

void Dest::setLightedUp(const bool light)
{
    this->light = light;
}

void Dest::reactToRay(Ray)
{
    this->setLightedUp(true);
}

Point * Dest::includeRay(const Ray & ray) const
{
    Point * intersec{nullptr};
    std::vector<Point> p{this->getIntersectionPoints(ray)};

    if (!p.empty())
    {
        intersec =
            ray.getStart().distanceFrom(p[0]) > ray.getStart().distanceFrom(p[1]) ?
                new Point{p[0]} : new Point{p[1]};

        if (! ray.isInTrajectory(*intersec))
            delete intersec, intersec = nullptr;
    }

    return intersec;
}

bool Dest::operator==(const Dest & dest) const
{
    return this->light == dest.light
            && Rectangle::operator ==(dest);
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
