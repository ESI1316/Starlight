#include "model/point.hpp"
#include "model/ray.hpp"
#include "model/level.hpp"
#include "model/starlightexception.hpp"

Ray::Ray(const Point start, double alpha, int waveLength)
    :Line(std::tan(alpha), start.getY() - (this->slope * start.getX())),
      start{start}, end{start}, waveLength{waveLength}
{
    if (waveLength < Ray::WL_MIN || waveLength > Ray::WL_MAX)
        throw StarlightException("Longueur d'onde doit être comprise entre");
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

bool Ray::operator==(const Ray & ray) const
{
    return this->start == ray.start
            && this->end == ray.end
            && this->waveLength == ray.waveLength
            && Line::operator ==(ray);
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
