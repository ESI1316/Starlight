#include "model/ray.hpp"
#include "model/level.hpp"
#include "model/starlightexception.hpp"

// réservation des attributs statiques
const int Ray::WL_MIN;
const int Ray::WL_MAX;
const int Ray::WL_DFT;

Ray::Ray(const PolarPoint start, double slope, int waveLength)
    :Ray{start.toCartesian(), slope, waveLength} {}

Ray::Ray(const Point start, double slope, int waveLength)
    :start{start}, end{start}, waveLength{waveLength}, vertical{slope == 90.},
      slope{slope}, indTerm{0.}
{
    if (waveLength < Ray::WL_MIN || waveLength > Ray::WL_MAX)
        throw StarlightException("Longueur d'onde doit être comprise entre");

    if(!vertical)
        this->indTerm = (start.getY() - (this->slope * start.getX()));
}

const Point & Ray::getStart() const
{
    return this->start;
}

const Point & Ray::getEnd() const
{
    return this->end;
}

int Ray::getWaveLength() const
{
    return this->waveLength;
}

void Ray::setStart(const Point & start)
{
    this->start = start;
}

void Ray::setEnd(const Point & end)
{
    this->end = end;
}

bool Ray::setWaveLength(const int waveLength)
{
    bool match = ((waveLength >= Ray::WL_MIN)
                  && (waveLength <= Ray::WL_MAX));

    if (match)
        this->waveLength = waveLength;

    return match;
}

bool Ray::isVertical() const
{
    return this->isVertical();
}

double Ray::getSlope() const
{
    return this->slope;
}

void Ray::setIndTerm(const double indTerm)
{
    this->indTerm = indTerm;
}

double Ray::getIndTerm() const
{
    return this->indTerm;
}

bool Ray::operator==(const Ray & ray) const
{
    return this->start == ray.start
            && this->end == ray.end
            && this->waveLength == ray.waveLength
            && utilities::equals(this->slope, ray.slope)
            && utilities::equals(this->indTerm, ray.indTerm);
}

bool Ray::operator!=(const Ray & ray) const
{
    return !(*this == ray);
}

std::ostream & operator<<(std::ostream & out, const Ray & ray)
{
    out << ray.getStart() << " ---------- " << ray.getEnd()
        << " (" << ray.getWaveLength() << " nm)";

    return out;
}
