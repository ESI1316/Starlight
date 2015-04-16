#include "model/point.hpp"

#include <cmath>

#include "geometry/utilities.hpp"

Point::Point(const double x, const double y)
    : x {x}, y {y}, radius{std::hypot(x, y)}, azimut{std::atan2(-y, x)} {}

Point::Point(const Point & point)
    : x{point.x}, y{point.y}, radius{point.radius}, azimut{point.azimut} {}

double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

double Point::getRadius() const
{
    return this->radius;
}

double Point::getAzimut() const
{
    return this->azimut;
}

double Point::getAzimutAsDegrees() const
{
    return utilities::angleAsDegree0to360(this->getAzimut());
}

bool Point::isCenter() const
{
    return utilities::equals(this->radius, 0.);
}

void Point::setX(const double x)
{
    this->setCartesianLocation(x, this->y);
}

void Point::setY(const double y)
{
    this->setCartesianLocation(this->x, y);
}

void Point::setCartesianLocation(const double x, const double y)
{
    *this = Point{x, y};
}

void Point::setPolarLocation(const double radius, const double azimut)
{
    this->radius = radius;
    this->azimut = azimut;
    this->x = this->radius * std::cos(this->azimut);
    this->y = this->radius * std::sin(-this->azimut);
}

void Point::setOrigin(const Point & origin)
{
    this->setCartesianLocation(this->getX() - origin.getX(),
                               this->getY() - origin.getY());
}

void Point::extend(const double radius)
{
    this->setPolarLocation(this->radius + radius, this->azimut);
}

double Point::distanceFrom(const Point & point) const
{
    return std::hypot((point.x - this->x),(point.y - this->y));
}

void Point::rotate(const double alpha)
{
    this->setPolarLocation(this->radius, this->azimut + alpha);
}

Point & Point::rotateAround(const Point & pivot, const double alpha)
{
    this->setCartesianLocation(this->getX() - pivot.getX(), this->getY() - pivot.getY());
    this->rotate(alpha);
    this->setCartesianLocation(this->getX() + pivot.getX(), this->getY() + pivot.getY());

    return *this;
}

Point & Point::operator =(const Point & point)
{
    this->x = point.x;
    this->y = point.y;
    this->radius = point.radius;
    this->azimut = point.azimut;

    return *this;
}

bool Point::operator==(const Point & point) const
{
    return utilities::equals(this->x, point.x)
            && utilities::equals(this->y, point.y);
}

bool Point::operator !=(const Point & point) const
{
    return !(*this == point);
}

std::ostream & operator<<(std::ostream & out, const Point & point)
{
    out << "[cartésien (x, y) = ("
        << point.getX() << " , " << point.getY() << ")]"
        << "[polaire (r, a) = ("
        << point.getRadius() << " , " << point.getAzimut() << ")]";

    return out;
}
