#include "model/elements/crystal.hpp"
#include <cmath>

#include "model/elements/ray.hpp"
#include "model/geometry/point.hpp"
#include "model/exception/starlightexception.hpp"
#include "model/elements/level.hpp"

Crystal::Crystal(const Point & center, const double radius, const int amplifier)
    : Element(), Ellipse{2. * radius,2. * radius, center}, amplifier{amplifier}
{
    if(utilities::lessOrEquals(radius, 0.))
        throw StarlightException{"Le rayon doit être strictement positif"};
}

double Crystal::getRadius() const
{
    return this->getHeight() / 2.;
}

void Crystal::reactToRay(Ray ray)
{
    if(this->getLevel() != nullptr)
        this->getLevel()->computeRay(Ray{ray.getEnd(),
                                         ray.getAlpha(),
                                         ray.getWaveLength() + this->amplifier});
}

Point * Crystal::includeRay(const Ray & ray) const
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

bool Crystal::operator==(const Crystal & crystal) const
{
    return this->amplifier == crystal.amplifier
            && Ellipse::operator ==(crystal);
}

bool Crystal::operator!=(const Crystal & crystal) const
{
    return !(*this == crystal);
}

std::ostream & operator<<(std::ostream & out, const Crystal & crystal)
{
    out << "Crystal --- Center : " << crystal.getCenter()
        << " , Radius : " << crystal.getRadius()
        << " , Modifier : " << crystal.getAmplifier();

    return out;
}
