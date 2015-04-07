#include "model/starlightexception.hpp"
#include "model/source.hpp"
#include "model/ray.hpp"
#include "model/utilities.hpp"

Source::Source(const Point & position, const int edge, const double alpha, const int waveLength)
    : position{position}, edge{edge}, alpha{alpha}, waveLength {waveLength}
{
    //if (edge <= 0)
    //    throw StarlightException("La longueur du coté doit être strict. positif");
    // TODO : valider wavelength
}

const Point & Source::getPosition() const
{
    return this->position;
}

double Source::getAngle() const
{
    return this->alpha;
}

int Source::getEdge() const
{
    return this->edge;
}

int Source::getWaveLength() const
{
    return this->waveLength;
}

bool Source::isOn() const
{
    return this->on;
}

void Source::setOn(const bool on)
{
    this->on = on;
}

bool Source::operator==(const Source & source) const
{
    return this->on == source.on
            && this->position == source.position
            && this->edge == source.edge
            && utilities::equals(this->alpha, source.alpha)
            && this->waveLength == source.waveLength;
}

bool Source::operator!=(const Source & source) const
{
    return !(*this == source);
}

Source & Source::operator =(const Source & source)
{
    this->on = source.on;
    this->position = source.position;
    this->edge = source.edge;
    this->alpha = source.alpha;
    this->waveLength = source.waveLength;

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
