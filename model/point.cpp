#include <cmath>
#include "model/point.hpp"

// 19:30 < niva1> abs(a-b) < 10^e-5
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
}

bool Point::operator==(const Point & point) const
{
    return std::round(this->x) == std::round(point.x)
            && std::round(this->y) == std::round(point.y);
}

std::ostream & operator<<(std::ostream & out, const Point & point)
{
    out << "( ";
    out << point.getX();
    out << " , ";
    out << point.getY();
    out << " )";

    return out;
}
