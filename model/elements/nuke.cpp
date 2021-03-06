#include "model/elements/nuke.hpp"

#include <cmath>

#include "model/exception/starlightexception.hpp"
#include "model/geometry/utilities.hpp"
#include "model/elements/ray.hpp"
#include "model/geometry/point.hpp"

Nuke::Nuke(const Point & position, const double radius)
    : Element(), Ellipse{2. * radius,2. * radius, position}, light{false}
{
    if (utilities::lessOrEquals(radius, 0.))
        throw StarlightException{"Le rayon de la bombe doit être "
                                 "strict. positif"};
}

void Nuke::setLightedUp(const bool light)
{
    this->light = light;
}

void Nuke::reactToRay(Ray)
{
    this->setLightedUp(true);
}

Point * Nuke::includeRay(const Ray & ray) const
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

bool Nuke::operator==(const Nuke & nuke) const
{
    return this->center == nuke.center
            && utilities::equals(this->getRadius(), nuke.getRadius())
            && this->light == nuke.light;
}

bool Nuke::operator!=(const Nuke & nuke) const
{
    return !(*this == nuke);
}

std::ostream & operator<<(std::ostream & out, const Nuke & nuke)
{
    out << "Nuke --- Position : " << nuke.getLocation()
        << " , Radius : " << nuke.getRadius()
        << " On : " << nuke.isLightedUp();

    return out;
}
