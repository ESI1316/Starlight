#include "ellipse.hpp"

Ellipse::Ellipse(double xRadius, double yRadius, const Point & center)
    : xRadius{xRadius}, yRadius{yRadius}, center{center} {}

double Ellipse::getXRadius() const
{
    return this->xRadius;
}

double Ellipse::getHeight() const
{
    return this->getXRadius() * 2.;
}

double Ellipse::getYRadius() const
{
    return this->yRadius;
}

double Ellipse::getWidth() const
{
    return this->getYRadius() * 2.;
}

Point Ellipse::getCenter() const
{
    return this->center;
}

bool Ellipse::operator ==(const Ellipse & ellipse) const
{
    return utilities::equals(this->xRadius, ellipse.xRadius)
            && utilities::equals(this->yRadius, ellipse.yRadius);
}
