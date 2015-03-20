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

int Point::distanceFrom(Point & p)
{
    // PDF page 9, dernières lignes. Simon.
}

std::ostream & operator<<(std::ostream & out, const Point & p)
{
    out << "( " << p.x << " , " << p.y << " )";
    return out;
}
