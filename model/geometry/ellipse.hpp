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

    Point center;
    double xRadius;
    double yRadius;

    /*!
     * \brief Permet d'obtenir les valeurs des ordonnées des points d'intersection
     * entre l'éllipse et une droite verticale dont l'abcisse est entrée en
     * paramètre.
     *
     * \param xValue Abcisse de la droite verticale dont on désire les ordonnées
     * des points d'intersection avec l'éllipse.
     * \param y1 Conteneur de la valeur de l'ordonnée du premier point
     * d'intersection (non utilisé s'il n'existe pas de point d'intersection).
     * \param y2 Conteneur de la valeur de l'ordonné du deuxième point
     * d'intersection (non utilisé s'il n'existe pas de point d'intersection).
     *
     * \return true Si il existe des points d'intersection entre la droite et
     * l'éllipse.
     */
    bool getYOfIntersPoints(const double, double *, double *) const;

    /*!
     * \brief Permet d'obtenir les abcisses des points d'intersection entre une droite
     * non-verticale dont la pente et le terme independant de l'équation sont
     * entrés en paramètre.
     *
     * \param slope Pente de la droite dont on désire les abcisses des
     * points d'intersection avec l'éllipse.
     * \param lineIT Terme indépendant de l'équation de la droite dont on
     * désire les abcisses des points d'intersection avec l'éllipse.
     * \param x1 Conteneur de la valeur de l'abcisse du premier point
     * d'intersection (non utilisé s'il n'existe pas de point d'intersection).
     * \param x2 Conteneur de la valeur de l'abcisse du deuxième point
     * d'intersection (non utilisé s'il n'existe pas de point d'intersection).
     *
     * \return true Si il existe des points d'intersection entre la droite et
     * l' éllipse.
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
     * \brief Permet d'obtenir le centre de l'éllipse.
     *
     * \return Le centre de l'éllipse.
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
 * \return Le ostream rempli de la chaine formatée représentant l'Ellipse en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Ellipse &);

#endif // ELLIPSE_HPP
