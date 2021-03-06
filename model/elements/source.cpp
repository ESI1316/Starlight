#include "model/elements/source.hpp"

#include "model/exception/starlightexception.hpp"
#include "model/elements/level.hpp"
#include "model/elements/ray.hpp"
#include "model/geometry/point.hpp"
#include "model/geometry/utilities.hpp"

Source::Source(const Point & position, const int edge, const double alpha,
               const int waveLength)
    : Element(), Rectangle(edge, edge, position),on{false}, alpha{alpha},
      waveLength{waveLength}
{
    if (waveLength < Ray::WL_MIN || waveLength > Ray::WL_MAX)
        this->waveLength = Ray::WL_DFT;
}

void Source::setOn(const bool on)
{
    this->on = on;

    if (this->getLevel() != nullptr || this->getLevel() != 0)
    {
        if(this->isOn())
            this->getLevel()->computeRays();
        else
        {
           this->getLevel()->getRays().clear();
           this->getLevel()->notifyViews();
        }
    }
}

void Source::reactToRay(Ray) {}

Point * Source::includeRay(const Ray &) const {return nullptr;}

bool Source::operator==(const Source & source) const
{
    return this->on == source.on
            && this->waveLength == source.waveLength
            && utilities::equals(this->alpha, source.alpha)
            && Rectangle::operator ==(source);
}

bool Source::operator!=(const Source & source) const
{
    return !(*this == source);
}

Source & Source::operator =(const Source & source)
{
    this->on = source.on;
    this->alpha = source.alpha;
    this->waveLength = source.waveLength;
    Rectangle::operator =(source);

    return *this;
}

std::ostream & operator<<(std::ostream & out, const Source & source)
{
    out << "Source --- Position : " << source.getPosition()
        << " , Angle : " << source.getAngle()
        << "Frequency : " << source.getWaveLength()
        << " , Edge : " << source.getEdge()
        << " , on : " << source.isOn();

    return out;
}
