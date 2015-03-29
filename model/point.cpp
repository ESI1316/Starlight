#include <cmath>
#include "point.hpp"

// 19:30 < niva1> abs(a-b) < 10^e-5
Point::Point(const int x, const int y)
    : x {x}, y {y}
{}

int Point::getX() const
{
    return this->x;
}

int Point::getY() const
{
    return this->y;
}

void Point::setX(const int x)
{
    this->x = x;
}

void Point::setY(const int y)
{
    this->y = y;
}

void Point::setLocation(const int x, const int y)
{
    this->x = x;
    this->y = y;
}

int Point::distanceFrom(const Point & point)
{
    return std::hypot((point.x - this->x),(point.y - this->y));
}

bool Point::operator==(const Point & point) const
{
    return this->x == point.x
            && this->y == point.y;
}

std::ostream & operator<<(std::ostream & out, const Point & point)
{
    out << "( " << point.getX() << " , " << point.getY() << " )";
    return out;
}
