#include "mirror.h"
#include <iostream>

Mirror::Mirror(const Point & p, int len, int x, double a)
    : Mirror {p, len, x, a, {0, 0}, {0, 0}, 0, 0}
{

}

Mirror::Mirror(const Point & p, int len, int x, double a, Point pm,
               Point pM, double am, double aM)
    : pivot {p}, length(len), xpad(x), xMin {pm.getX()}, xMax {pM.getX()},
yMin {pm.getY()}, yMax {pM.getY()}, alpha {a}, alphaMin {am},
alphaMax {aM}
{
    // TODO : valider length, xpad, (alphaMin et alphaMax),
    //                (alpha et [alphaMin, alphaMax]), (xMin et xMax),
    //                (x et [xMin, xMax]), (yMin et yMax),
    //                (y et [yMin, yMax])
}

const Point & Mirror::getPivot() const
{
    return this->pivot;
}

int Mirror::getLength() const
{
    return this->length;
}

int Mirror::getXPad() const
{
    return this->xpad;
}

double Mirror::getAngle() const
{
    return this->alpha;
}

double Mirror::getMinAngle() const
{
    return this->alphaMin;
}

double Mirror::getMaxAngle() const
{
    return this->alphaMax;
}

Point Mirror::getMinPivot() const
{
    return Point {xMin, yMin};
}

Point Mirror::getMaxPivot() const
{
    return Point {xMax, yMax};
}

bool Mirror::setPivot(const Point & p)
{
    bool r {checkPivotRange(p)};
    if (r) this->pivot = p;
    return r;
}

bool Mirror::setAngle(double a)
{
    bool r {checkAngleRange(a)};
    if (r) this->alpha = a;
    return r;
}

bool Mirror::checkAngleRange(double a) const
{
    return (this->alphaMin == 0 && this->alphaMax == 0) ||
           (a >= this->alphaMin && a <= this->alphaMax);
}

bool Mirror::checkPivotRange(const Point & p) const
{
    if (this->xMin == 0 && this->xMax == 0 && this->yMin == 0 && this->yMax == 0)
    {
        return true;
    }
    else if (this->xMin == 0 && this->xMax == 0)
    {
        return p.getY() >= this->yMin && p.getY() <= this->yMax;
    }
    else if (this->yMin == 0 && this->yMax == 0)
    {
        return p.getX() >= this->xMin && p.getX() <= this->xMax;
    }
    else
    {
        return p.getX() >= this->xMin && p.getX() <= this->xMax
               && p.getY() >= this->yMin && p.getY() <= this->yMax;
    }
}

std::ostream & operator<<(std::ostream & out, const Mirror & m)
{
    out << "Mirror --- Pivot : " << m.pivot << " , Length : " << m.length
        << " , x-pad : " << m.xpad << ", Angle : " << m.alpha <<
        " , Angle range : [" << m.alphaMin << "," << m.alphaMax << "]" <<
        "Pivot range : [(" << m.xMin << "," << m.yMin << "),(" << m.xMax <<
        "," << m.yMax << ")]";
    return out;
}
