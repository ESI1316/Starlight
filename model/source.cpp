#include "source.h"
#include "ray.h"

Source::Source(const Point & p, int e, double a, int wl) : pos {p},
alpha {a}, edge {e}, wavelength {wl}
{
    // TODO : valider edge et wavelength
}

const Point & Source::getPosition() const
{
    return this->pos;
}

int Source::getAngle() const
{
    return this->alpha;
}

int Source::getEdge() const
{
    return this->edge;
}

int Source::getWavelength() const
{
    return this->wavelength;
}

bool Source::isOn() const
{
    return this->on;
}

void Source::setOn(bool q)
{
    this->on = q;
}

std::ostream & operator<<(std::ostream & out, const Source & s)
{
    out << "Source --- Position : " << s.pos << " , Angle : " << s.alpha
        << "Frequency : " << s.wavelength << " , Edge : " << s.edge <<
        " , on : " <<
        s.on;
    return out;
}
