#include <cmath>
#include "polarPoint.h"

/**
 * @brief PolarPoint::PolarPoint Création d'un point confondu avec le centre du
 * cercle de rayon dont il est issue.
 */
PolarPoint::PolarPoint()
    : PolarPoint{0., 0.}
{
}

/**
 * @brief PolarPoint::PolarPoint Créé un point polaire selon les arguments passés
 * en paramètre.
 * "Il est commode d'autoriser des valeurs négatives de $ r$, étant entendu que
 * les coodonnées polaires $ (r,\theta)$ et $ (-r, \pi+\theta)$ représentent
 * alors le même point. Les formules ci-dessus sont encore applicables. "
 * @param radius Le rayon séparant le centre du point voulu. Doit être positif.
 * @param beta La longueur du segment de cercle depuis l'axe horizontal.
 * @throw Si le rayon demandé est négatif.
 *
 */
PolarPoint::PolarPoint(double radius, double beta)
    : radius{radius}, beta{beta}
{
    if(radius < 0.)
        throw new std::string("Le rayon ne peut pas être négatif");

    this->radius = radius;
    this->beta = beta;
}

/**
 * @brief PolarPoint::PolarPoint
 * @param polarCoordinate
 */
PolarPoint::PolarPoint(PolarPoint & polarCoordinate)
    : PolarPoint{polarCoordinate.radius, polarCoordinate.beta}
{
}
/**
 * @brief PolarPoint::PolarPoint
 */
PolarPoint::PolarPoint(Point & point)
    : PolarPoint()
{
    int x = point.getX();
    int y = point.getY();

    if (std::acos(y) * ((180 / M_PI) + 180) >= 180)
        this->beta = (int)(std::acos(x) * (180/M_PI) + 180) % 360;
    else
        this->beta = 360 - (std::acos(x) * (180/M_PI) + 180);

    this->radius = std::sqrt(std::exp2(x) + std::exp2(y));
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

/**
 * @brief operator <<
 * @param out
 * @param polarCoordinate
 * @return
 */
std::ostream & operator<<(std::ostream & out, const PolarPoint & polarCoordinate)
{
    out << "(radius, beta) = " <<
           "(" << polarCoordinate.getRadius() <<
           ", " << polarCoordinate.getBeta() << ")";

    return out;
}
