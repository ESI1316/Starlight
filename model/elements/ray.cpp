#include "model/elements/ray.hpp"

#include "model/exception/starlightexception.hpp"
#include "model/elements/level.hpp"

Ray::Ray(const Point start, double alpha, int waveLength)
    : Line(utilities::tan(alpha),
           start.getY() - (utilities::tan(alpha) * start.getX()),
           utilities::isHalfPiPlusNPi(alpha) ? start.getX() : 0.),
      start{start}, end{start}, waveLength{waveLength},
      alpha{utilities::inZeroTwoPi(alpha)}
{
    if (waveLength < Ray::WL_MIN || waveLength > Ray::WL_MAX)
        throw StarlightException{"Longueur d'onde doit être comprise entre"};
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
        this->waveLength = Ray::WL_MIN;
    else if (waveLength > Ray::WL_MAX)
        this->waveLength = Ray::WL_MAX;
    else
        this->waveLength = waveLength;
}

bool Ray::isInTrajectory(const Point & point) const
{
    Point p(point);
    p.setOrigin(this->start);

    return ((point != this->start)
            && utilities::equals(this->getAlpha(),
                                 utilities::inZeroTwoPi(p.getAzimut())));
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
    out << ray.getStart() << " -R-A-Y- " << ray.getEnd()
        << " (" << ray.getWaveLength() << " nm) | Angle : " << ray.getAlpha() << std::endl
        << (Line) ray;

    return out;
}
