#include "crystal.hpp"
#include "starlightexception.hpp"
#include "level.hpp"


Crystal::Crystal(const Point & center, const int radius, const int amplifier)
    : Element(),
      center {center},
      radius{radius},
      amplifier {amplifier}
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

bool Crystal::includeRay(const Ray & ray) const
{
    throw StarlightException("Not implemented yet");
}

std::ostream & operator<<(std::ostream & out, const Crystal & crystal)
{
    out << "Crystal --- Center : " << crystal.getCenter()
        << " , Radius : " << crystal.getRadius()
        << " , Modifier : " << crystal.getAmplifier();
    return out;
}
