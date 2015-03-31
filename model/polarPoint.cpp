#include <cmath>
#include "model/polarPoint.hpp"

/**
 * @brief PolarPoint::PolarPoint Créé un point polaire selon les arguments passés
 * en paramètre.
 * "Il est commode d'autoriser des valeurs négatives de $ r$, étant entendu que
 * les coodonnées polaires $ (r,\theta)$ et $ (-r, \pi+\theta)$ représentent
 * alors le même point. Les formules ci-dessus sont encore applicables. "
 * @param radius Le rayon séparant le centre du point voulu. Doit être positif.
 * @param azimut La longueur du segment de cercle depuis l'axe horizontal.
 *
 */
PolarPoint::PolarPoint(const double radius, const double azimut)
    : radius{radius}, azimut{azimut}
{
}

/**
 * @brief PolarPoint::PolarPoint Copie d'un point polaire.
 * @param polarPoint Un autre point polaire.
 */
PolarPoint::PolarPoint(const PolarPoint & polarPoint)
    : PolarPoint{polarPoint.radius, polarPoint.azimut}
{
}

/**
 * @brief PolarPoint::PolarPoint Construit un point polaire à l'aide d'un
 * point cartésien.
 * Azimut sera toujours compris entre 0 et 360 (0 et 2\pi) pour permettre de
 * représenter un point d'une seule manière possible.
 * @see <a href="http://fr.wikipedia.org/wiki/Coordonn%C3%A9es_polaires">
 * wikipedia - Coordonnées polaires </a>
 */
PolarPoint::PolarPoint(const Point &point)
    : PolarPoint()
{
    int x = point.getX();
    int y = point.getY();

    this->radius = std::hypot(x, y);
    this->azimut = std::atan2(x, y);
}

/**
 * @brief PolarPoint::~PolarPoint
 */
PolarPoint::~PolarPoint()
{}

/**
 * @brief PolarPoint::isCenter
 */
bool PolarPoint::isCenter() const
{
    return (std::round(this->radius) == 0.);
}

/**
 * /// TODO : Precision double -> int pour pixels
 * CAST CAST CAST
 * @brief PolarPoint::toCartesian
 * @return
 */
Point PolarPoint::toCartesian() const
{
    return Point(
                this->radius * std::cos(this->azimut),
                this->radius * std::sin(this->azimut)
                );
}

/**
 * @brief PolarPoint::getRadius
 * @return
 */
double PolarPoint::getRadius() const
{
    return this->radius;
}
/**
 * @brief PolarPoint::getAzimut
 * @return
 */
double PolarPoint::getAzimut() const
{
    return this->azimut;
}

/**
 * @brief PolarPoint::getAzimutAsDegrees
 * @return
 */
double PolarPoint::getAzimutAsDegrees() const
{
    return (this->getAzimut() * 180.) / M_PI;
}

/**
 * @brief PolarPoint::rotate Pour faire une rotation autour d'un pivot et
 * non de l'origine, il suffit de translater le pivot sur l'origine.
 * @return
 */
PolarPoint & PolarPoint::rotateAround(const PolarPoint & polarPoint, double alpha)
{
    return this->rotateAround(polarPoint.toCartesian(), alpha);
}

PolarPoint & PolarPoint::rotateAround(const Point & pivot, const double alpha)
{
    Point point = this->toCartesian();

    point.setX(point.getX() - pivot.getX());
    point.setY(point.getY() - pivot.getY());

    PolarPoint pointModifie(point);
    pointModifie.rotate(alpha);

    return *this = pointModifie;
}

void PolarPoint::rotate(const double alpha)
{
    this->azimut += alpha;
}

PolarPoint & PolarPoint::operator=(const PolarPoint & polarPoint)
{
    this->radius = polarPoint.radius;
    this->azimut = polarPoint.azimut;

    return *this;
}

PolarPoint & PolarPoint::operator=(const Point & point)
{
    *this = PolarPoint{point};

    return *this;
}

    bool PolarPoint::operator==(const PolarPoint & polarPoint) const
    {
        return std::abs(this->radius - polarPoint.radius) <= 0.1
                && std::abs(this->azimut == polarPoint.azimut) <= 0.1;

    }
/**
 * @brief operator <<
 * @param out
 * @param polarCoordinate
 * @return
 */
std::ostream & operator<<(std::ostream & out, const PolarPoint & polarPoint)
{
    out << "(radius, azimut) = "
        << "(" << polarPoint.getRadius()
        << ", " << polarPoint.getAzimut() << ")";

    return out;
}
