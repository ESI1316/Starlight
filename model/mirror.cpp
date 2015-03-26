#include <iostream>
#include "mirror.hpp"
#include "level.hpp"

Mirror::Mirror(const Point & point, int length, int xpad, double alpha)
    : Mirror {point, length, xpad, alpha, Point{0, 0}, Point{0, 0}, 0, 0}
{

}

Mirror::Mirror(const Point & p, int length, int xpad, double alpha, Point pm,
               Point pM, double alphaMin, double alphaMax)
    : Element(), pivot {p}, length(length), xpad(xpad), xMin {pm.getX()},
      xMax {pM.getX()}, yMin {pm.getY()}, yMax {pM.getY()}, alpha {alpha},
      alphaMin {alphaMin}, alphaMax {alphaMax}
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

bool Mirror::setPivot(const Point & pivot)
{
    bool match{this->checkPivotRange(pivot)};

    if (match)
        this->pivot = pivot;

    return match;
}

bool Mirror::setAngle(double alpha)
{
    bool match{this->checkAngleRange(alpha)};

    if (match)
        this->alpha = alpha;

    return match;
}

/**
 * @brief Mirror::checkAngleRange A NETTOYER TOUTE CES CRAPS ALGO
 * @param a
 * @return
 */
bool Mirror::checkAngleRange(double a) const
{
    return (this->alphaMin == 0 && this->alphaMax == 0) ||
            (a >= this->alphaMin && a <= this->alphaMax);
}

/**
 * @brief Mirror::checkPivotRange A NETTOYER TOUTE CES CRAPS ALGO
 * @param point
 * @return
 */
bool Mirror::checkPivotRange(const Point & point) const
{
    if (this->xMin == 0 && this->xMax == 0 && this->yMin == 0 && this->yMax == 0)
    {
        return true;
    }
    else if (this->xMin == 0 && this->xMax == 0)
    {
        return point.getY() >= this->yMin && point.getY() <= this->yMax;
    }
    else if (this->yMin == 0 && this->yMax == 0)
    {
        return point.getX() >= this->xMin && point.getX() <= this->xMax;
    }
    else
    {
        return point.getX() >= this->xMin && point.getX() <= this->xMax
                && point.getY() >= this->yMin && point.getY() <= this->yMax;
    }
}

Mirror & Mirror::operator =(const Mirror & mirror)
{
    this->pivot = mirror.pivot;
    this->length = mirror.length;
    this->xpad = mirror.xpad;
    this->xMin = mirror.xMin;
    this->xMax = mirror.xMax;
    this->yMin = mirror.yMin;
    this->yMax = mirror.yMax;
    this->alpha = mirror.alpha;
    this->alphaMin = mirror.alphaMin;
    this->alphaMax = mirror.alphaMax;

    return *this;
}

void Mirror::reactToRay(Ray &)
{

}
bool Mirror::includePoint(Point &)
{

}

/**
 * @brief operator << A CLEAN A COUP DE GETTERS POUR EVITER LE FRIEND.
 * @param out
 * @param mirror
 * @return
 */
std::ostream & operator<<(std::ostream & out, const Mirror & mirror)
{
    out << "Mirror --- Pivot : " << mirror.getPivot()
        << " , Length : " << mirror.getLength()
        << " , x-pad : " << mirror.getXPad()
        << ", Angle : " << mirror.getAngle()
        << " , Angle range : [" << mirror.getMinAngle()
        << "," << mirror.getMaxAngle() << "]"
        << "Pivot range : [(" << mirror.getMinPivot().getX()
        << "," << mirror.getMinPivot().getY()
        << "),(" << mirror.getMaxPivot().getX()
        << "," << mirror.getMaxPivot().getY() << ")]";

    return out;
}
