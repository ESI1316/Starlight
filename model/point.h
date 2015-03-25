#ifndef POINT_H
#define POINT_H

#include <iostream>

/**
 * Cette classe modélise un simple point de coordonnées entières,
 * utilisés pour modéliser les positions des objets dans le jeu.
 */
class Point
{
    int x {0};
    int y {0};

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
    Point(const int, const int);

    /**
     * Retourne l'abscisse du point.
     * @return l'abscisse du point.
     */
    int getX() const;

    /**
     * Retourne l'ordonnée du point.
     * @return l'ordonnée du point.
     */
    int getY() const;

    /**
     * Déplace le point en l'abscisse donnée.
     * @param x l'abscisse où déplacer le point.
     */
    void setX(const int);

    /**
     * Déplace le point en l'ordonnée donnée.
     * @param y l'ordonnée où déplacer le point.
     */
    void setY(const int);

    /**
     * Déplace le point en la coordonnée donnée.
     * @param x l'abscisse où déplacer le point.
     * @param y l'ordonnée où déplacer le point.
     */
    void setLocation(const int, const int);

    /**
     * @brief distanceFrom
     * @param p
     * @return
     */
    int distanceFrom(const Point & p);

    /**
     * @brief operator ==
     * @return
     */
    bool operator==(const Point &) const;

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher un
     * récapitulatif des caractéristiques du point sous-jacent en
     * console.
     * @return le flux dans lequel le point a été imprimé.
     */
    friend std::ostream & operator<<(std::ostream &, const Point &);
};

#endif // POINT_H
