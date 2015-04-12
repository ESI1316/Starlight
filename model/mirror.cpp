#include "model/mirror.hpp"

#include <cmath>

#include "model/starlightexception.hpp"
#include "model/level.hpp"
#include "geometry/utilities.hpp"

Mirror::Mirror(const Point & pivot, int xpad, int length, double alpha, Point pointMin,
               Point pointMax, double alphaMin, double alphaMax)
    : Element(),
      Line(utilities::tan(utilities::inZeroTwoPi(alpha)),
           pivot.getY() - (utilities::tan(alpha) * pivot.getX()),
           utilities::isHalfPiPlusNPi(alpha) ? pivot.getX() : 0),
      pivot {pivot}, length(length), xpad(xpad), xMin {pointMin.getX()},
      xMax {pointMax.getX()}, yMin {pointMin.getY()}, yMax {pointMax.getY()},
      alpha {alpha}, alphaMin {alphaMin}, alphaMax {alphaMax}
{
    if(this->xpad < 0)
        throw StarlightException("Le décalage du pivot doit être positif");

    if (this->length <= 0)
        throw StarlightException("La longueur doit être strict. positive");

    if(this->alphaMax < this->alphaMin)
        throw StarlightException("L'angle max est inferieur au min");

    if(!this->checkPivotRange(this->pivot))
        throw StarlightException("Le miroir est trop haut ou trop bas");

    if(!this->checkAngleRange(this->alpha))
        throw StarlightException("L'angle est en dehors des limites");
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
    return this->checkPivotRange(pivot) ? this->pivot = pivot, true : false;
}

bool Mirror::setAngle(double alpha)
{
    return this->checkAngleRange(alpha) ? this->alpha = alpha, true : false;
}

bool Mirror::checkAngleRange(double alpha) const
{
    return (utilities::equals(this->alphaMin, 0.) && utilities::equals(this->alphaMax, 0.))
            || ((utilities::greaterOrEquals(alpha, this->alphaMin))
             && (utilities::lessOrEquals(alpha, this->alphaMax)));
}

bool Mirror::checkPivotRange(const Point & point) const
{
    return (utilities::equals(this->xMin, .0) && utilities::equals(this->xMax, 0.)
            && utilities::equals(this->yMin, 0.) && utilities::equals(this->yMax, 0.))

           || (utilities::equals(this->xMin, 0.) && utilities::equals(this->xMax, 0.)
            && (utilities::greaterOrEquals(point.getY(), this->yMin))
            && (utilities::lessOrEquals(point.getY(), this->yMax)))

           || (utilities::equals(this->yMin, 0.) && utilities::equals(this->yMax, 0.)
            &&(utilities::greaterOrEquals(point.getX(), this->xMin))
            &&(utilities::lessOrEquals(point.getX(), this->xMax)))

           || ((utilities::greaterOrEquals(point.getX(), this->xMin))
            && (utilities::lessOrEquals(point.getX(), this->xMax))
            && (utilities::greaterOrEquals(point.getY(), this->yMin))
            && (utilities::lessOrEquals(point.getY(), this->yMax)));
}

void Mirror::reactToRay(Ray ray)
{
    Point point = ray.getEnd();
    double mirror = utilities::absoluteAngle(this->getAngle());
    double source = utilities::absoluteAngle(std::atan(ray.getSlope()));
    double alpha = (utilities::PI - mirror - source);

    if (utilities::equals(alpha, 0.))
        alpha = 0.;

    Ray newRay(point, (source + alpha + alpha), ray.getWaveLength());

    if(this->getLevel() != nullptr)
        this->getLevel()->computeRay(newRay);
}

Point * Mirror::includeRay(const Ray &) const
{
    throw StarlightException("Not implemented yet");
}

bool Mirror::operator==(const Mirror & mirror) const
{
    return this->pivot == mirror.pivot
            && this->length == mirror.length
            && this->xpad == mirror.xpad
            && utilities::equals(this->xMin, mirror.xMin)
            && utilities::equals(this->xMax, mirror.xMax)
            && utilities::equals(this->yMin, mirror.yMin)
            && utilities::equals(this->yMax, mirror.yMax)
            && utilities::equals(this->alpha, mirror.alpha)
            && utilities::equals(this->alphaMin, mirror.alphaMin)
            && utilities::equals(this->alphaMax, mirror.alphaMax);
}

bool Mirror::operator!=(const Mirror & mirror) const
{
    return !(*this == mirror);
}

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
        << "," << mirror.getMaxPivot().getY() << ")]"
        << (Line) mirror;

    return out;
}
