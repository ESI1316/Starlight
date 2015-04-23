#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include <vector>
#include <ostream>

#include "model/geometry/point.hpp"

class Line;

/*!
 * \brief Représente un cercle sous la forme;
 * \f$ circle \equiv x^2/xRadius + y^2/yRadius = 1 \f$
 */
class Ellipse
{

protected:

    /*!
     * \brief La position du centre de l'ellipse.
     */
    Point center;

    /*!
     * \brief La hauteur du rectangle circonscrit à l'ellipse.
     */
    double height;

    /*!
     * \brief La largeur du rectangle circonscrit à l'ellipse.
     */
    double width;

    /*!
     * \brief La valeur de la demi hauteur au carré.
     */
    double xRadius;

    /*!
     * \brief La valeur de la demi largeur au carré.
     */
    double yRadius;

    /*!
     * \brief Permet d'obtenir les valeurs des ordonnées des points d'intersection
     * entre l'ellipse et une droite verticale dont l'abscisse est entrée en
     * paramètre.
     *
     * \param xValue Abscisse de la droite verticale dont on désire les ordonnées
     * des points d'intersection avec l'ellipse.
     * \param y1 Conteneur de la valeur de l'ordonnée du premier point
     * d'intersection (non utilisé s'il n'existe pas de point d'intersection).
     * \param y2 Conteneur de la valeur de l'ordonne du deuxième point
     * d'intersection (non utilisé s'il n'existe pas de point d'intersection).
     *
     * \return <code>true</code> Si il existe des points d'intersection entre la droite et
     * l'éllipse.
     */
    bool getYOfIntersPoints(const double, double *, double *) const;

    /*!
     * \brief Permet d'obtenir les abscisses des points d'intersection entre une droite
     * non-verticale dont la pente et le terme indépendant de l'équation sont
     * entrés en paramètre.
     *
     * \param slope Pente de la droite dont on désire les abscisses des
     * points d'intersection avec l'ellipse.
     * \param lineIT Terme indépendant de l'équation de la droite dont on
     * désire les abscisses des points d'intersection avec l'ellipse.
     * \param x1 Conteneur de la valeur de l'abscisse du premier point
     * d'intersection (non utilisé s'il n'existe pas de point d'intersection).
     * \param x2 Conteneur de la valeur de l'abscisse du deuxième point
     * d'intersection (non utilisé s'il n'existe pas de point d'intersection).
     *
     * \return <code>true</code> Si il existe des points d'intersection entre la droite et
     * l'ellipse.
     */
    bool getXOfIntersPoints(const double, const double, double *, double *) const;

public:

    /*!
     * \brief Permet de construire une nouvelle ellipse initialisée.
     *
     * \param xRadius Valeur du ratio de largeur de l'ellipse.
     * \param yRadius Valeur du ratio de hauteur de l'ellipse.
     * \param center Point du centre de l'ellipse.
     */
    Ellipse(double, double, const Point &);

    /*!
     * \brief Permet d'obtenir les points d'intersection entre le cercle et la droite
     * entrée en paramètre.
     *
     * \param line droite dont on désire obtenir les points d'intersection avec
     * l'éllipse.
     *
     * \return Un vecteur contenant les points d'intersections entre le cercle
     * et la droite entrée en paramètre.
     */
    std::vector<Point> getIntersectionPoints(const Line &) const;

    /*!
     * \brief Permet d'obtenir la valeur du ratio de largeur de l'ellipse.
     *
     * \return La valeur du ratio de largeur de l'ellipse.
     */
    double getXRadius() const;

    /*!
     * \brief Permet d'obtenir la valeur du ratio de hauteur de l'ellipse.
     *
     * \return La valeur du ratio de hauteur de l'ellipse.
     */
    double getYRadius() const;

    /*!
     * \brief Permet d'obtenir le centre de l'ellipse.
     *
     * \return Le centre de l'ellipse.
     */
    Point getCenter() const;

    /*!
     * \brief Permet d'obtenir le coin supérieur gauche du rectangle entourant
     * l'ellipse.
     *
     * \return le coin supérieur gauche du rectangle entourant
     * l'ellipse.
     */
    Point getUpLeftCorner() const;

    /*!
     * \brief Permet d'obtenir la largeur de l'ellipse.
     *
     * \return La largeur de l'ellipse.
     */
    double getWidth() const;

    /*!
     * \brief Permet d'obtenir la hauteur de l'ellipse.
     *
     * \return La hauteur de l'ellipse.
     */
    double getHeight() const;

    /*!
     * \brief Permet de savoir si deux Ellipse sont les mêmes.
     *
     * \return <code>true</code> Si deux Ellipses sont identiques.
     */
    bool operator==(const Ellipse &) const;

    /*!
     * \brief Permet de savoir si deux Ellipse sont différentes.
     *
     * \return <code>true</code> Si deux Ellipses sont différentes.
     */
    bool operator!=(const Ellipse &) const;
};

/*!
 * \brief Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * \return Le ostream rempli de la chaine formatée représentant l'ellipse en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Ellipse &);

inline double Ellipse::getWidth() const
{
    return this->width;
}

inline double Ellipse::getHeight() const
{
    return this->height;
}

inline double Ellipse::getXRadius() const
{
    return this->xRadius;
}

inline double Ellipse::getYRadius() const
{
    return this->yRadius;
}

inline Point Ellipse::getCenter() const
{
    return this->center;
}

#endif // ELLIPSE_HPP
