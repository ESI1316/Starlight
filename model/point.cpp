#include <cmath>
#include <iostream>
#include "model/point.hpp"

Point::Point(const double x, const double y)
    : x {x}, y {y} {}

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

void Point::setX(const double x)
{
    this->x = x;
}

void Point::setY(const double y)
{
    this->y = y;
}

void Point::setLocation(const double x, const double y)
{
    this->x = x;
    this->y = y;
}

double Point::distanceFrom(const Point & point) const
{
    return std::hypot((point.x - this->x),(point.y - this->y));
}

Point & Point::operator =(const Point & point)
{
    this->x = point.x;
    this->y = point.y;

    return *this;
}

bool Point::operator==(const Point & point) const
{
    return std::round(this->x - point.x) < 0.1
            && std::round(this->y - point.y) < 0.1;
}

bool Point::operator !=(const Point & point) const
{
    return !(*this == point);
}

std::ostream & operator<<(std::ostream & out, const Point & point)
{
    out << "( " << point.getX() << " , " << point.getY() << " )";

    return out;
}
