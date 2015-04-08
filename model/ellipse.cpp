#include "ellipse.hpp"

Ellipse::Ellipse(double xRadius, double yRadius, const Point & center)
    : xRadius{xRadius}, yRadius{yRadius}, center{center} {}

std::vector<Point> Ellipse::getIntersections(const Line & line) const
{
    double x1, y1, x2, y2;
    std::vector<Point> intersecs;
    bool thereIsIntersec;

    if (line.isVertical())
    {
         thereIsIntersec = utilities::secondDegreeEquationSolver
                    (1, 2 * -this->center.getY(),
                     (((std::pow(line.getXValue() - this->center.getX(), 2)
                     /std::pow(this->xRadius, 2)) - 1) * std::pow(this->yRadius, 2))
                     + std::pow(this->center.getY(), 2), &y1, &y2);
         x1 = x2 = line.getXValue();
    }
    else
    {/*
        thereIsintersec = utilities::secondDegreeEquationSolver
                (1 + std::pow(line.getSlope(), 2),
                    , &x1, &x2);

        y1 = x1 * line.getSlope() + line.getIndepTerm();
        y2 = x2 * line.getSlope() + line.getIndepTerm(); */
    }

    if (thereIsIntersec)
    {
        intersecs.push_back(Point{x1, y1});
        intersecs.push_back(Point{x2, y2});
    }

    return intersecs;
}

double Ellipse::getXRadius() const
{
    return this->xRadius;
}

double Ellipse::getYRadius() const
{
    return this->yRadius;
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
