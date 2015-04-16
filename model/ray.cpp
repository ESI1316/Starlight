#include "model/ray.hpp"

#include "model/starlightexception.hpp"
#include "model/level.hpp"

Ray::Ray(const Point start, double alpha, int waveLength)
    : Line(utilities::tan(alpha),
           start.getY() - (utilities::tan(alpha) * start.getX()),
           utilities::isHalfPiPlusNPi(alpha) ? start.getX() : 0),
      start{start}, end{start}, waveLength{waveLength},
      alpha{utilities::inZeroTwoPi(alpha)}
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

bool Ray::isInTrajectory(const Point & point) const
{
    bool inTrajectory;

    if (utilities::equals(this->alpha, 0))
        inTrajectory =(this->start.getX() < point.getX()
                       && utilities::equals(this->start.getY(), point.getY()));
    else if(utilities::equals(this->alpha, utilities::PI_2))
        inTrajectory =(this->start.getY() > point.getY()
                       && utilities::equals(this->start.getX(), point.getX()));
    else if(utilities::equals(this->alpha, utilities::PI))
        inTrajectory =(this->start.getX() > point.getX()
                       && utilities::equals(this->start.getY(), point.getY()));
    else if(utilities::equals(this->alpha, (3 * utilities::PI_2)))
        inTrajectory =(this->start.getY() < point.getY()
                       && utilities::equals(this->start.getX(), point.getX()));
    else if(this->alpha > 0 && this->alpha < utilities::PI_2)
        inTrajectory =(this->start.getY() > point.getY()
                       && this->start.getX() < point.getX());
    else if(this->alpha > utilities::PI_2 && this->alpha < utilities::PI)
        inTrajectory =(this->start.getY() > point.getY()
                       && this->start.getX() > point.getX());
    else if(this->alpha > utilities::PI && this->alpha < (3 * utilities::PI_2))
        inTrajectory =(this->start.getY() < point.getY()
                       && this->start.getX() > point.getX());
    else
        inTrajectory =(this->start.getY() < point.getY()
                       && this->start.getX() < point.getX());

    return inTrajectory;
}

double Ray::getAlpha() const
{
    return this->alpha;
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
