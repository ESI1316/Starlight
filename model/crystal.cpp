#include "model/crystal.hpp"
#include <iostream>
#include <cmath>

#include "model/ray.hpp"
#include "model/point.hpp"
#include "model/starlightexception.hpp"
#include "model/level.hpp"

Crystal::Crystal(const Point & center, const double radius, const int amplifier)
    : Element(), Ellipse(radius, radius, center), amplifier{amplifier}
{
    if(utilities::lessOrEquals(radius, 0.))
        throw StarlightException("Le rayon doit être strictement positif");
}

int Crystal::getAmplifier() const
{
    return this->amplifier;
}

double Crystal::getRadius() const
{
    return std::sqrt(this->xRadius);
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
    Point * intersec = 0;
    std::vector<Point> p = this->getIntersectionPoints(ray);

    if (!p.empty())
    {
        intersec =
            ray.getStart().distanceFrom(p[0]) > ray.getStart().distanceFrom(p[1]) ?
                new Point{p[0]} : new Point{p[1]};

        if (! ray.isInTrajectory(*intersec))
            delete intersec, intersec = 0;
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
