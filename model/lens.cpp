#include "lens.h"
#include "level.h"

Lens::Lens(const Point & p, int width, int height, int wlmin, int wlmax)
    : position {p}, width {width}, height {height}, wlmin {wlmin}, wlmax {wlmax}
{
    // TODO : valider width, height, wlmin et wlmax
}

const Point & Lens::getPosition() const
{
    return this->position;
}

int Lens::getWidth() const
{
    return this->width;
}

int Lens::getHeight() const
{
    return this->height;
}

int Lens::getMinWavelength() const
{
    return this->wlmin;
}

int Lens::getMaxWavelength() const
{
    return this->wlmax;
}

std::ostream & operator<<(std::ostream & out, const Lens & lens)
{
    out << "Lens -- Position : " <<lens.getPosition()
        << " , width : " <<lens.getWidth()
        << " , height : " <<lens.getHeight()
        << " , Freq. Min. : " <<lens.getMinWavelength()
        << " , Freq. Max. : " <<lens.getMaxWavelength();
    return out;
}
