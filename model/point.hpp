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
     * Instancie un point par copie d'un autre point : constructeur de recopie.
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
     * Permet de connaitre la distance séparant le point courant d'un autre.
     * La distance est calculée à l'aide du théorème de pythagore au triangle
     * rectangle :
     * soient les deux points du plan cartésien reliés formant un segment de
     * droite, en tracant les paralleles aux axes passant par ces points on peut
     * délimiter un triangle rectangle par l'intersection des deux droites.
     * De là, il est simple d'appliquer le théorème de Pythagore aux triangles
     * rectangles :
     * l'hypothénuse au carré = la somme du carré des deux autres cotés
     * distance(p1, p2)² = (p1.x - p2.x)² + (p1.y - p2.y)²
     * Dans la bibliothèque standard C++, la fonction std::hypot de <cmath>
     * nous permet de faire cette opération en lui passant simplement les cotés
     * autre que l'hypothénuse.
     * @param point Un autre point.
     * @return La distance séparant deux point.
     */
    double distanceFrom(const Point &) const;

    /**
     * Permet de copier le contenu d'un point dans un autre point.
     *
     * @return Le point courant modifié.
     */
    Point & operator=(const Point &);

    /**
     * Permet de savoir si deux points sont aux même endroit.
     *
     * @return <code>true</code> Si les deux points ont les même coordonnées.
     */
    bool operator==(const Point &) const;

    /**
     * Permet de savoir si deux points ne sont pas au même endroit.
     *
     * @return <code>true</code> Si les deux points ne sont pas les mêmes.
     */
    bool operator!=(const Point &) const;
};

/**
 * Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * @return Le ostream rempli de la chaine formatée représentant le Point en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Point &);

#endif // POINT_H
