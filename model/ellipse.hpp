#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <vector>

#include "model/point.hpp"
#include "model/line.hpp"

/**
 * Représente un cercle sous la forme;
 * x²/xRadius² + y²/yRadius² = 1;
 */
class Ellipse
{
private:

    int xRadius;
    int yRadius;

public:

    /**
     * Permet de construire une nouvelle ellipse initialisée.
     *
     * @param xRadius Valeur du ratio de largeur de l'ellipse.
     * @param yRadius Valeur du ratio de hauteur de l'ellipse.
     */
    Ellipse(int xRadius, int yRadius);

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
    int getXRadius() const;

    /**
     * Permet d'obtenir la valeur du ratio de hauteur de l'ellipse.
     *
     * @return La valeur du ratio de hauteur de l'ellipse.
     */
    int getYRadius() const;
};

#endif // ELLIPSE_H
