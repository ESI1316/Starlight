#include <cmath>
#include "polarcoordinate.hpp"

/**
 * @brief PolarCoordinate::PolarCoordinate
 */
PolarCoordinate::PolarCoordinate()
    : PolarCoordinate(0, 0.)
{}

/**
 * @brief PolarCoordinate::PolarCoordinate
 * @param radius
 * @param beta
 */
PolarCoordinate::PolarCoordinate(int radius, double beta)
    : radius{radius}, beta{beta}
{}

PolarCoordinate::PolarCoordinate(PolarCoordinate & polarCoordinate)
    : PolarCoordinate(polarCoordinate.radius, polarCoordinate.beta)
{

}
/**
 * @brief PolarCoordinate::PolarCoordinate
 */
PolarCoordinate::PolarCoordinate(Point &) : radius{/*todo*/}, beta{/*todo*/}
{
}

/**
 * @brief PolarCoordinate::~PolarCoordinate
 */
PolarCoordinate::~PolarCoordinate()
{}

/**
 * /// TODO : Precision double -> int pour pixels
 * CAST CAST CAST
 * @brief PolarCoordinate::toCartesian
 * @return
 */
Point PolarCoordinate::toCartesian()
{
    return Point(
                this->radius * std::cos(this->beta),
                this->radius * std::sin(this->beta)
                );
}

/**
 * @brief PolarCoordinate::getRadius
 * @return
 */
int PolarCoordinate::getRadius() const
{
    return this->radius;
}
/**
 * @brief PolarCoordinate::getBeta
 * @return
 */
double PolarCoordinate::getBeta() const
{
    return this->beta;
}

/**
 * @brief PolarCoordinate::rotate
 * @return
 */
PolarCoordinate & PolarCoordinate::rotate(double alpha)
{
    this->beta += alpha;
    return *this;
}

std::ostream & operator<<(std::ostream & out, PolarCoordinate & polarCoordinate)
{
    out << "(radius, beta) = " <<
           "(" << polarCoordinate.radius << ", " << polarCoordinate.beta << ")";

    return out;
}
