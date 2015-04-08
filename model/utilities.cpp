#include <cmath>
#include "model/utilities.hpp"
#include "model/point.hpp"

bool utilities::intersecPointsLineCircle(const double slope,
                                         const int indepTerm, const Point & circleCenter,
                                         const int radius, Point * intersec1, Point * intersec2)
{
    double x1, x2;
    bool thereIsIntersec = utilities::secondDegreeEquationSolver
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

bool utilities::secondDegreeEquationSolver(double a, double b, double c,
                                           double * rad1, double * rad2)
{
    double delta = std::pow(b, 2.) - (4. * a * c);
    bool thereIsRadix = (delta >= 0);

    if (thereIsRadix)
    {
        *rad1 = (-b - std::sqrt(delta))/(2. * a);
        *rad2 = (-b + std::sqrt(delta))/(2. * a);
    }

    return thereIsRadix;
}

double utilities::angleAsDegree(const double alpha)
{
    return ((alpha * 180.) / utilities::PI);
}

double utilities::angleAsDegree0to360(const double alpha)
{
    return std::fmod(
                std::fmod(utilities::angleAsDegree(alpha), 360.) + 360.,
                360.);
}

bool utilities::equals(const double nb1, const double nb2, const double epsilon)
{
    return (std::abs(nb1 - nb2) < epsilon);
}

double utilities::slopeFromPoints(const Point & p1, const Point & p2)
{
    return ((p2.getY() - p1.getY()) / (p2.getX() - p1.getX()));
}

bool utilities::isHalfPiPlusNPi(const double alpha)
{
    return utilities::equals(std::fmod(alpha, utilities::PI), utilities::PI_2);
}
