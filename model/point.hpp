#ifndef POINT_H
#define POINT_H

#include <iostream>

/**
 * Cette classe modélise un simple point de coordonnées entières,
 * utilisés pour modéliser les positions des objets dans le jeu.
 */
class Point
{
    double x {0.};
    double y {0.};

public:

    /**
     * Instancie le point (0,0)
     */
    Point() = default;

    /**
     * Instancie le point de coordonnées spécifiées.
     * @param x l'abscisse du point
     * @param y l'ordonnée du point
     */
    Point(const double, const double);

    /**
     * @brief Point
     */
    Point(const Point &);

    /**
     * Retourne l'abscisse du point.
     * @return l'abscisse du point.
     */
    double getX() const;

    /**
     * Retourne l'ordonnée du point.
     * @return l'ordonnée du point.
     */
    double getY() const;

    /**
     * Déplace le point en l'abscisse donnée.
     * @param x l'abscisse où déplacer le point.
     */
    void setX(const double);

    /**
     * Déplace le point en l'ordonnée donnée.
     * @param y l'ordonnée où déplacer le point.
     */
    void setY(const double);

    /**
     * Déplace le point en la coordonnée donnée.
     * @param x l'abscisse où déplacer le point.
     * @param y l'ordonnée où déplacer le point.
     */
    void setLocation(const double, const double);

    /**
     * @brief distanceFrom
     * @param p
     * @return
     */
    double distanceFrom(const Point & p) const;

    /**
     * @brief operator =
     * @return
     */
    Point & operator=(const Point &);

    /**
     * Permet de savoir si deux points sont aux même endroit.
     *
     * @return <code>true</code> Si les deux points ont les même coordonnées.
     */
    bool operator==(const Point &) const;
};
std::ostream & operator<<(std::ostream &, const Point &);

#endif // POINT_H
