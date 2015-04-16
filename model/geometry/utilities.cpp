#include "model/geometry/utilities.hpp"

#include <cmath>

#include "model/geometry/point.hpp"

bool utilities::secondDegreeEquationSolver(double a, double b, double c,
                                           double * rad1, double * rad2)
{
    double delta = std::pow(b, 2.) - (4. * a * c);

    if (utilities::equals(delta, 0.))
            delta = 0.;

    bool thereIsRadix = (delta >= 0.);

    if (thereIsRadix)
    {
        *rad1 = (-b - std::sqrt(delta))/(2. * a);
        *rad2 = (-b + std::sqrt(delta))/(2. * a);
    }

    return thereIsRadix;
}

double utilities::absoluteAngle(const double alpha)
{
    double angle = fmod(alpha, 2. * utilities::PI);

        if (angle < 0.)
            angle += (2. * utilities::PI);

        if (angle > utilities::PI)
            angle = (2 * utilities::PI) - angle;

    return utilities::equals(angle, 0) ? 0. : angle;
}

double utilities::inZeroTwoPi(const double alpha)
{
   return std::fmod((std::fmod(alpha, (2 * utilities::PI)) + (2 * utilities::PI)),
                    (utilities::PI * 2));
}

double utilities::angleAsDegree(const double alpha)
{
    return ((alpha * 180.) / utilities::PI);
}

double utilities::angleAsDegree0to360(const double alpha)
{
    return utilities::angleAsDegree(utilities::inZeroTwoPi(alpha));
}

bool utilities::equals(const double nb1, const double nb2, const double epsilon)
{
    return (std::isinf(nb1) && std::isinf(nb2)) || (std::fabs(nb1 - nb2) < epsilon);
}

bool utilities::greaterOrEquals(const double nb1, const double nb2, const double epsilon)
{
    return (nb1 > nb2) || utilities::equals(nb1, nb2, epsilon);
}

bool utilities::lessOrEquals(const double nb1, const double nb2, const double epsilon)
{
    return (nb1 < nb2) || utilities::equals(nb1, nb2, epsilon);
}

double utilities::slopeFromPoints(const Point & p1, const Point & p2)
{
    return ((p2.getY() - p1.getY()) / (p2.getX() - p1.getX()));
}

bool utilities::isHalfPiPlusNPi(const double alpha)
{
    return utilities::equals(std::fmod(std::fabs(alpha), utilities::PI),
                             utilities::PI_2);
}

double utilities::tan(const double alpha)
{
    return utilities::isHalfPiPlusNPi(alpha) ? 1./0. : -std::tan(alpha);
}
