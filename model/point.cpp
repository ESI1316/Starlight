#include <cmath>
#include "point.hpp"

Point::Point(const int a, const int b) : x {a}, y {b}
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

int Point::distanceFrom(const Point &point)
{
    return std::hypot((point.x - this->x),(point.y - this->y));
}

Point & Point::operator=(const Point & point)
{
    this->x = point.x;
    this->y = point.y;

    return *this;
}

bool Point::operator==(const Point & point) const
{
    return ((this->x == point.x) && (this->y == point.y));
}

std::ostream & operator<<(std::ostream & out, const Point & p)
{
    out << "( " << p.x << " , " << p.y << " )";
    return out;
}
