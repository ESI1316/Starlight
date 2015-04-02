#include <cmath>
#include "model/geometryUtilities.hpp"

bool geometryUtilities::intersecPointsLineCircle(const double slope,
                                                 const int indepTerm, const Point & circleCenter,
                                                 const int radius, Point * intersec1, Point * intersec2)
{
    double x1, x2;
    bool thereIsIntersec = geometryUtilities::secondDegreeEquationSolver
            (1 + std::pow(slope, 2),
             (-2 * circleCenter.getX()) + (2 * slope * (indepTerm - circleCenter.getY())),
             std::pow((indepTerm - circleCenter.getY()), 2) + std::pow(circleCenter.getX(), 2)
             - std::pow(radius, 2),
             &x1, &x2);

    if (thereIsIntersec)
    {
        *intersec1 = *new Point{x1, (slope * x1) + indepTerm};
        *intersec2 = *new Point{x2, (slope * x2) + indepTerm};
    }

    return thereIsIntersec;
}

bool geometryUtilities::secondDegreeEquationSolver(double a, double b, double c,
                                                   double * rad1, double * rad2)
{
    int delta = std::pow(b, 2) - (4 * a * c);
    bool thereIsRadix = delta >= 0;

    if (thereIsRadix)
    {
        *rad1 = (-b - std::sqrt(delta))/(2. * a);
        *rad2 = (-b + std::sqrt(delta))/(2. * a);
    }

    return thereIsRadix;
}

double geometryUtilities::angleAsDegree(double alpha)
{
    return ((alpha * 180.) / M_PI);
}

double geometryUtilities::angleAsDegree0to360(double alpha)
{
    double degree = geometryUtilities::angleAsDegree(alpha);

    if(degree < 0)
        degree += 360;
    else if (degree >= 360)
        degree -= 360;

    return degree;
}
