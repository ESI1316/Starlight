#include <cmath>
#include "model/polarPoint.hpp"
#include "model/utilities.hpp"

const PolarPoint PolarPoint::CARTESIAN_PLAN_ORIGIN;

PolarPoint::PolarPoint(const double radius, const double azimut)
    : radius{radius}, azimut{azimut} {}

PolarPoint::PolarPoint(const Point &point)
    : PolarPoint()
{
    double x = point.getX();
    double y = point.getY();

    *this = PolarPoint{std::hypot(x, y), std::atan2(y, x)};
}

PolarPoint::PolarPoint(const PolarPoint & polarPoint)
    : PolarPoint{polarPoint.radius, polarPoint.azimut} {}

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
    return utilities::angleAsDegree0to360(this->getAzimut());
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
    point = pointModifie.toCartesian();
    point.setX(point.getX() + pivot.getX());
    point.setY(point.getY() + pivot.getY());

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

bool PolarPoint::operator!=(const PolarPoint & polarPoint) const
{
    return !(*this == polarPoint);
}

std::ostream & operator<<(std::ostream & out, const PolarPoint & polarPoint)
{
    out << "(radius, azimut) = "
        << "(" << polarPoint.getRadius()
        << ", "
        << polarPoint.getAzimut()
        << ")";

    return out;
}
