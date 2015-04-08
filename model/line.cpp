#include "model/line.hpp"

Line::Line(double slope, double indepTerm, double xValue = 0)
    : slope{slope}, indepTerm{indepTerm}, xValue{xValue} {}

Point * Line::getIntersectionPoint(const Line & line) const
{
    double x, y;
    Point * intersec = 0;

    if (this->slope != line.getSlope())
    {
        x = this->isVertical() ? this->xValue
                               : (this->indepTerm - line.getIndepTerm()) /
                                 (line.getSlope() - this->slope);
        y = this->slope * x + this->getIndepTerm();

        intersec = new Point{x, y};
    }

    return intersec;
}

bool Line::includes(const Point & point) const
{
    return this->isVertical() ?
                point.getX() == this->xValue
              : point.getY() == ((this->slope * point.getX()) + this->indepTerm);
}

double Line::getSlope() const
{
    return this->slope;
}

double Line::getIndepTerm() const
{
    return this->indepTerm;
}

bool Line::isVertical() const
{
    return std::isinf(this->slope);
}
