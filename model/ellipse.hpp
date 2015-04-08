#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <vector>

#include "model/point.hpp"
#include "model/line.hpp"

/**
 * Représente un cercle sous la forme;
 * \f$ circle \equiv x^2/xRadius^2 + y^2/yRadius^2 = 1 \f$
 */
class Ellipse
{

protected:

    Point center;
    double xRadius;
    double yRadius;

public:

    /**
     * Permet de construire une nouvelle ellipse initialisée.
     *
     * @param xRadius Valeur du ratio de largeur de l'ellipse.
     * @param yRadius Valeur du ratio de hauteur de l'ellipse.
     * @parm center Point du centre de l'ellipse.
     */
    Ellipse(double, double, const Point &);

    /**
     * Permet d'obtenir les points d'intersection entre le cercle et la droite
     * entrée en paramètre.
     *
     * @return Un vecteur contenant les points d'intersections entre le cercle
     * et la droite entrée en paramètre.
     */
    std::vector<Point> getIntersections(const Line &) const;

    /**
     * Permet d'obtenir la valeur du ratio de largeur de l'ellipse.
     *
     * @return La valeur du ratio de largeur de l'ellipse.
     */
    double getXRadius() const;

    /**
     * @brief getHeight
     * @return
     */
    double getHeight() const;

    /**
     * Permet d'obtenir la valeur du ratio de hauteur de l'ellipse.
     *
     * @return La valeur du ratio de hauteur de l'ellipse.
     */
    double getYRadius() const;

    /**
     * @brief getWidth
     * @return
     */
    double getWidth() const;

    /**
     * @brief getCenter
     * @return
     */
    Point getCenter() const;

    bool operator==(const Ellipse &) const;
};

#endif // ELLIPSE_H
