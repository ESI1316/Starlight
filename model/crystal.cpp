#include "model/crystal.hpp"

#include <cmath>

#include "model/ray.hpp"
#include "model/point.hpp"
#include "model/starlightexception.hpp"
#include "model/level.hpp"

Crystal::Crystal() : Element(), Ellipse{4, 4, Point{0, 0}}, amplifier{100} {}

Crystal::Crystal(const Point & center, const double radius, const int amplifier)
    : Element(), Ellipse(std::pow(radius, 2), std::pow(radius, 2), center),
      amplifier{amplifier}
{
    if(radius <= 0)
        throw StarlightException("Le rayon doit être strictement positif");
}

int Crystal::getAmplifier() const
{
    return this->amplifier;
}

int Crystal::getRadius() const
{
    return (int) std::sqrt(this->xRadius);
}

void Crystal::reactToRay(Ray & ray)
{
    ray.setWaveLength(ray.getWaveLength() + this->amplifier);

    if(this->getLevel() != nullptr)
        this->getLevel()->computeRay(ray);
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
    }

    return intersec;
}

bool Crystal::operator==(const Crystal & crystal) const
{
    return this->center == crystal.center
            && utilities::equals(this->getRadius(), crystal.getRadius())
            && this->amplifier == crystal.amplifier
            && Element::operator==(crystal);
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
