#include "model/geometry/ellipse.hpp"

#include "model/geometry/line.hpp"
#include "model/starlightexception.hpp"

Ellipse::Ellipse(double xRadius, double yRadius, const Point & center)
    : center{center}, xRadius{std::pow(xRadius, 2)}, yRadius{std::pow(yRadius, 2)}
{
    if (xRadius < 0. || utilities::equals(xRadius, 0.))
        throw StarlightException("xRadius négatif");
    if (yRadius < 0. || utilities::equals(yRadius, 0.))
        throw StarlightException("xRadius négatif");
}

std::vector<Point> Ellipse::getIntersectionPoints(const Line & line) const
{
    double x1, y1, x2, y2;
    std::vector<Point> intersecs;
    bool thereIsIntersec;

    if (line.isVertical())
    {
        thereIsIntersec = this->getYOfIntersPoints(line.getXValue(), &y1, &y2);
        x1 = x2 = line.getXValue();
    }
    else
    {
        thereIsIntersec = this->getXOfIntersPoints
                (line.getSlope(), line.getIndepTerm(), &x1, &x2);
        y1 = line.findY(x1); y2 = line.findY(x2);
    }

    if (thereIsIntersec)
    {
        intersecs.push_back(Point{x1, y1});
        intersecs.push_back(Point{x2, y2});
    }

    return intersecs;
}

bool Ellipse::getYOfIntersPoints(const double xValue, double * y1, double * y2) const
{
    double xSquareParam, xParam, indepTerm;

    xSquareParam = 1 / this->yRadius;

    xParam = (2 * -this->center.getY()) / this->yRadius;

    indepTerm = (std::pow(xValue - this->center.getX(), 2) / this->xRadius)
            + (std::pow(this->center.getY(), 2)/this->getYRadius()) - 1;

    return utilities::secondDegreeEquationSolver
            (xSquareParam, xParam, indepTerm, y1,  y2);
}

bool Ellipse::getXOfIntersPoints(const double slope, const double lineIT, double * x1,
                                 double *x2) const
{
    double xSquareParam, xParam, indepTerm;

    xSquareParam = (std::pow(slope, 2)/this->getYRadius()) + 1/this->xRadius;

    xParam = ((-2 * this->getCenter().getX())/this->xRadius)
            + (((2 * slope) * (lineIT - this->center.getY()))/this->yRadius);

    indepTerm = (std::pow(this->center.getX(), 2) / this->xRadius)
            + (std::pow(lineIT - this->center.getY(), 2)
               /this->yRadius) - 1;

    return utilities::secondDegreeEquationSolver
            (xSquareParam, xParam, indepTerm, x1, x2);
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
            && utilities::equals(this->yRadius, ellipse.yRadius)
            && this->center == ellipse.center;
}

bool Ellipse::operator !=(const Ellipse & ellipse) const
{
    return !(*this == ellipse);
}
