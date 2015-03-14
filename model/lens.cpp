#include "lens.h"

Lens::Lens(const Point & p, int w, int h, int wlmin, int wlmax) : pos {p},
width {w}, height {h}, wlmin {wlmin}, wlmax {wlmax}
{
    // TODO : valider width, height, wlmin et wlmax
}

const Point & Lens::getPosition() const
{
    return this->pos;
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

std::ostream & operator<<(std::ostream & out, const Lens & l)
{
    out << "Lens -- Position : " << l.pos << " , width : " << l.width
        << " , height : " << l.height << " , Freq. Min. : " << l.wlmin <<
        " , Freq. Max. : " << l.wlmax;
    return out;
}
