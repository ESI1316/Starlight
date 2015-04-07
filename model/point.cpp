#include <cmath>
#include <iostream>
#include "utilities.hpp"
#include "model/point.hpp"

Point::Point(const double x, const double y)
    : x {x}, radius{std::hypot(x, y)},
      y {y}, azimut{std::atan2(y, x)} {}

Point::Point(const Point & point)
    :Point{point.x, point.y} {}

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
    this->setLocation(x, this->y);
}

void Point::setY(const double y)
{
    this->setLocation(this->x, y);
}

void Point::setLocation(const double x, const double y)
{
    *this = Point{x, y};
}

double Point::distanceFrom(const Point & point) const
{
    return std::hypot((point.x - this->x),(point.y - this->y));
}

void Point::rotate(const double alpha)
{
    this->azimut += alpha;
    this->x = this->radius * std::cos(this->azimut);
    this->y = this->radius * std::sin(this->azimut);
}

Point & Point::rotateAround(const Point & pivot, const double alpha)
{
    this->setLocation(this->getX() - pivot.getX(), this->getY() - pivot.getY());
    this->rotate(alpha);
    this->setLocation(this->getX() + pivot.getX(), this->getY() + pivot.getY());

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
    out << "c(x, y) = c( "
        << point.getX() << " , " << point.getY() << " )"
        << "p(r, a) = p( "
        << point.getRadius() << " , " << point.getAzimut() << " )";

    return out;
}
