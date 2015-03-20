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
PolarPoint::PolarPoint(Point &)
    : radius{}, beta{}
{
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
