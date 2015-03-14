#include "ray.h"

// réservation des attributs statiques
const int Ray::WL_MIN;
const int Ray::WL_MAX;
const int Ray::WL_DFT;

Ray::Ray(const Point & p1, const Point & p2) : Ray {p1, p2, Ray::WL_DFT}
{ }

Ray::Ray(const Point & p1, const Point & p2, int wl) : start {p1},
    end {p2}, wavelength {wl}
{
    // TODO : valider wavelength, (start et end ?)
}

const Point & Ray::getStart() const
{
    return this->start;
}

const Point & Ray::getEnd() const
{
    return this->end;
}

int Ray::getWavelength() const
{
    return this->wavelength;
}

void Ray::setStart(const Point & p)
{
    this->start = p;
}

void Ray::setEnd(const Point & p)
{
    this->end = p;
}

bool Ray::setWavelength(int wl)
{
    bool r = wl >= Ray::WL_MIN && wl <= Ray::WL_MAX;
    if (r) this->wavelength = wl;
    return r;
}

std::ostream & operator<<(std::ostream & out, const Ray & p)
{
    out << p.start << " ---------- " << p.end << " (" << p.wavelength <<
           " nm)";
    return out;
}
