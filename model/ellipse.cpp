#include "ellipse.hpp"

Ellipse::Ellipse(double xRadius, double yRadius, const Point & center)
    : xRadius{xRadius}, yRadius{yRadius}, center{center} {}

std::vector<Point> getIntersections(const Line & line) const
{
    double x1, y1, x2, y2;
    std::vector<Point> intersecs;
    bool thereIsintersec = thereIsintersec = line.isVertical() ?
                utilities::secondDegreeEquationSolver()
              : utilities::secondDegreeEquationSolver();

    if (thereIsIntersec)
    {
        intersecs.push_back(Point{x1, y1});
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
