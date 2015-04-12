#include "model/ray.hpp"

#include "model/starlightexception.hpp"
#include "model/level.hpp"

Ray::Ray(const Point start, double alpha, int waveLength)
    : Line(utilities::tan(alpha),
           start.getY() - (utilities::tan(alpha) * start.getX()),
           utilities::isHalfPiPlusNPi(alpha) ? start.getX() : 0),
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

void Ray::setWaveLength(const int waveLength)
{
    if (waveLength < Ray::WL_MIN )
    {
        this->waveLength = Ray::WL_MIN;
    }
    else if (waveLength > Ray::WL_MAX)
    {
        this->waveLength = Ray::WL_MAX;
    }
    else
        this->waveLength = waveLength;
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
        << " (" << ray.getWaveLength() << " nm)" << std::endl
        << (Line) ray;

    return out;
}
