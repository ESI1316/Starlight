#include <cmath>
#include "model/starlightexception.hpp"
#include "model/mirror.hpp"
#include "model/level.hpp"
#include "utilities.hpp"

Mirror::Mirror(const Point & point, int xpad, int length, double alpha)
    : Mirror {point, length, xpad, alpha, Point{0., 0.}, Point{0., 0.}, 0., 0.} {}

Mirror::Mirror(const Point & pivot, int xpad, int length, double alpha, Point pointMin,
               Point pointMax, double alphaMin, double alphaMax)
    : Element(), pivot {pivot}, length(length), xpad(xpad), xMin {pointMin.getX()},
      xMax {pointMax.getX()}, yMin {pointMin.getY()}, yMax {pointMax.getY()}, alpha {alpha},
      alphaMin {alphaMin}, alphaMax {alphaMax}
{
    if (length <= 0)
        throw StarlightException("La longueur doit être strict. positive");

    if(xpad < 0)
        throw StarlightException("Le décalage du pivot doit être positif");

    if(pivot.getX() < pointMin.getX() || pivot.getX() > pointMax.getX())
        throw StarlightException("Le miroir est trop haut ou trop bas");

    if(pivot.getY() < pointMin.getY() || pivot.getY() > pointMax.getY())
        throw StarlightException("Le miroir est trop à gauche ou trop à droite");

    if(alphaMax < alphaMin)
        throw StarlightException("L'angle est en dehors des limites");

    if(alpha > alphaMax || alpha < alphaMin)
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

bool Mirror::checkAngleRange(double a) const
{
    return (this->alphaMin == 0 && this->alphaMax == 0) ||
            (a >= this->alphaMin && a <= this->alphaMax);
}

bool Mirror::checkPivotRange(const Point & point) const
{
    return true;
}

void Mirror::reactToRay(Ray & ray)
{
    /*
    Point point = ray.getEnd();
    double alpha = std::abs(std::fmod(
                                -utilities::PI
                                + this->getAngle()
                                - std::atan(ray.getSlope())
                                ,utilities::PI));

    Ray newRay(point, std::tan(alpha), ray.getWaveLength());
    newRay.setIndTerm(point.getY() - (newRay.getSlope() * point.getX()));

    this->getLevel()->computeRay(newRay);
    */
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
            && utilities::equals(this->alphaMax, mirror.alphaMax)
            && Element::operator ==(mirror);
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
        << "," << mirror.getMaxPivot().getY() << ")]";

    return out;
}
