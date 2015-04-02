#include <cmath>
#include <iostream>
#include "model/polarPoint.hpp"
#include "model/geometryUtilities.hpp"

const PolarPoint PolarPoint::CARTESIAN_PLAN_ORIGIN;

/**
 * @brief PolarPoint::PolarPoint Créé un point polaire selon les arguments passés
 * en paramètre.
 * "Il est commode d'autoriser des valeurs négatives de $ r$, étant entendu que
 * les coodonnées polaires $ (r,\theta)$ et $ (-r, \pi+\theta)$ représentent
 * alors le même point. Les formules ci-dessus sont encore applicables. "
 * @param radius Le rayon séparant le centre du point voulu. Doit être positif.
 * @param azimut La longueur du segment de cercle depuis l'axe horizontal.
 *
 */
PolarPoint::PolarPoint(const double radius, const double azimut)
    : radius{radius}, azimut{azimut}
{
}

/**
 * @brief PolarPoint::PolarPoint Copie d'un point polaire.
 * @param polarPoint Un autre point polaire.
 */
PolarPoint::PolarPoint(const PolarPoint & polarPoint)
    : PolarPoint{polarPoint.radius, polarPoint.azimut}
{
}

PolarPoint::PolarPoint(const Point &point)
    : PolarPoint()
{
    double x = point.getX();
    double y = point.getY();

    *this = PolarPoint{std::hypot(x, y), std::atan2(x, y)};
}

PolarPoint::~PolarPoint() {}

bool PolarPoint::isCenter() const
{
    return (std::round(this->radius) == 0.);
}

Point PolarPoint::toCartesian() const
{
    return Point(
                this->radius * std::cos(this->azimut),
                this->radius * std::sin(this->azimut)
                );
}

double PolarPoint::getRadius() const
{
    return this->radius;
}

double PolarPoint::getAzimut() const
{
    return this->azimut;
}

double PolarPoint::getAzimutAsDegrees() const
{
    return geometryUtilities::angleAsDegree0to360(this->getAzimut());
}

PolarPoint & PolarPoint::rotateAround(const PolarPoint & polarPoint, double alpha)
{
    return this->rotateAround(polarPoint.toCartesian(), alpha);
}

PolarPoint & PolarPoint::rotateAround(const Point & pivot, const double alpha)
{
    Point point = this->toCartesian();

    point.setX(point.getX() - pivot.getX());
    point.setY(point.getY() - pivot.getY());

    PolarPoint pointModifie(point);
    pointModifie.rotate(alpha);

    return *this = pointModifie;
}

void PolarPoint::rotate(const double alpha)
{
    this->azimut += alpha;
}

PolarPoint & PolarPoint::operator=(const PolarPoint & polarPoint)
{
    this->radius = polarPoint.radius;
    this->azimut = polarPoint.azimut;

    return *this;
}

PolarPoint & PolarPoint::operator=(const Point & point)
{
    *this = PolarPoint{point};

    return *this;
}

bool PolarPoint::operator==(const PolarPoint & polarPoint) const
{
    return (std::abs(this->radius - polarPoint.radius) <= 0.1)
            && (std::abs(this->azimut - polarPoint.azimut) <= 0.1);

}

std::ostream & operator<<(std::ostream & out, const PolarPoint & polarPoint)
{
    out << "(radius, azimut) = ";
    out << "(";
    out << polarPoint.getRadius();
    out << ", ";
    out << polarPoint.getAzimut();
    out << ")";

    return out;
}
