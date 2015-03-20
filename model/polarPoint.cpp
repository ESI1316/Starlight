#include <cmath>
#include "polarPoint.h"

/**
 * @brief PolarPoint::PolarPoint
 */
PolarPoint::PolarPoint()
    : PolarPoint(0, 0.)
{}

/**
 * @brief PolarPoint::PolarPoint
 * @param radius
 * @param beta
 */
PolarPoint::PolarPoint(int radius, double beta)
    : radius{radius}, beta{beta}
{}

PolarPoint::PolarPoint(PolarPoint & polarCoordinate)
    : PolarPoint(polarCoordinate.radius, polarCoordinate.beta)
{

}
/**
 * @brief PolarPoint::PolarPoint
 */
PolarPoint::PolarPoint(Point & point)
    : PolarPoint()
{
    double newBeta{0.};
    int x = point.getX();
    int y = point.getY();

    if (x > 0)
        if(y >= 0)
            newBeta = std::atan(y / (float) x);
        else
            newBeta = std::atan(y / (float) x) + (M_2_PI);
    else if (x < 0)
        newBeta = std::atan(y / (float) x) + M_PI;
    else
        if(y > 0)
            newBeta = M_PI_2;
        else
            newBeta = (3 * M_PI) / 2.;

    this->radius = std::sqrt(std::exp2(x) + std::exp2(x));
    this->beta = newBeta;
}

/**
 * @brief PolarPoint::~PolarPoint
 */
PolarPoint::~PolarPoint()
{}

/**
 * /// TODO : Precision double -> int pour pixels
 * CAST CAST CAST
 * @brief PolarPoint::toCartesian
 * @return
 */
Point PolarPoint::toCartesian()
{
    return Point(
                this->radius * std::cos(this->beta),
                this->radius * std::sin(this->beta)
                );
}

/**
 * @brief PolarPoint::getRadius
 * @return
 */
int PolarPoint::getRadius() const
{
    return this->radius;
}
/**
 * @brief PolarPoint::getBeta
 * @return
 */
double PolarPoint::getBeta() const
{
    return this->beta;
}

/**
 * @brief PolarPoint::rotate
 * @return
 */
PolarPoint & PolarPoint::rotate(double alpha)
{
    this->beta += alpha;
    return *this;
}

std::ostream & operator<<(std::ostream & out, PolarPoint & polarCoordinate)
{
    out << "(radius, beta) = " <<
           "(" << polarCoordinate.radius << ", " << polarCoordinate.beta << ")";

    return out;
}
