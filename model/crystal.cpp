#include <cmath>
#include "model/crystal.hpp"
#include "model/starlightexception.hpp"
#include "model/level.hpp"


Crystal::Crystal(const Point & center, const double radius, const int amplifier)
    : Element(), center {center}, radius{radius}, amplifier {amplifier}
{
    if(radius <= 0)
        throw StarlightException("Le rayon doit être strictement positif");
}

const Point & Crystal::getCenter() const
{
    return this->center;
}

int Crystal::getAmplifier() const
{
    return this->amplifier;
}

int Crystal::getRadius() const
{
    return this->radius;
}

void Crystal::reactToRay(Ray & ray)
{
    ray.setWaveLength(ray.getWaveLength() + this->amplifier);
    this->getLevel()->computeRay(ray);
}

Point * Crystal::includeRay(const Ray & ray) const
{
    Point * intersec1, * intersec2, * ret = 0;
    bool thereIsIntersec = geometryUtilities::intersecPointsLineCircle
            (ray.getSlope(), ray.getIndTerm(), this->center, this->radius,
             intersec1, intersec2);

    if (thereIsIntersec)
        ret = ray.getStart().distanceFrom(*intersec1) > ray.getStart().distanceFrom(*intersec2) ?
                    intersec1 : intersec2;

    return ret;
}

bool Crystal::operator==(const Crystal & crystal) const
{
    return this->center == crystal.center
            && std::abs(this->radius - crystal.radius) <= 0.1
            && this->amplifier == crystal.amplifier
            && Element::operator==(crystal);
}

std::ostream & operator<<(std::ostream & out, const Crystal & crystal)
{
    out << "Crystal --- Center : " << crystal.getCenter()
        << " , Radius : " << std::to_string(crystal.getRadius())
        << " , Modifier : " << std::to_string(crystal.getAmplifier());
    return out;
}
