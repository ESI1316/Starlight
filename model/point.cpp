#include <cmath>
#include "point.h"

Point::Point(int a, int b) : x {a}, y {b}
{}

int Point::getX() const
{
    return this->x;
}

int Point::getY() const
{
    return this->y;
}

void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

void Point::setLocation(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point::distanceFrom(Point & point)
{
    return std::hypot((point.x - this->x),(point.y - this->y));
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
