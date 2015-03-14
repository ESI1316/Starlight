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

void Point::setX(int a)
{
    this->x = a;
}

void Point::setY(int a)
{
    this->y = a;
}

void Point::setLocation(int a, int b)
{
    this->x = a;
    this->y = b;
}

std::ostream & operator<<(std::ostream & out, const Point & p)
{
    out << "( " << p.x << " , " << p.y << " )";
    return out;
}
