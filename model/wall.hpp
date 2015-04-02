#ifndef WALL_H
#define WALL_H

#include <ostream>
//#include "model/point.hpp"
#include "model/element.hpp"

/**
 * Cette classe modélise les murs utilisés dans le jeu.
 * </p>
 * Les murs sont des segments de droite qui ne réfléchissent
 * pas la lumière.
 */
class Wall : public Element
{
    Point start;
    Point end;

public:

    /**
     * Instancie un mur.
     * @param p1 le début du mur.
     * @param p2 la fin du mur.
     */
    Wall(const Point & p1, const Point & p2);

    /**
     * Retourne le début du mur.
     * @return le début du mur.
     */
    const Point &getStart() const;

    /**
     * Retourne la fin du mur.
     * @return la fin du mur.
     */
    const Point & getEnd() const;

    /**
     * Réaction à l'exposition d'un rayon.
     *
     * @param ray Le rayon.
     */
    void reactToRay(Ray &);

    /**
     * Renseigne si le mur est dans la trajectoire du rayon.
     *
     * @param ray Le rayon.
     *
     * @return true Si la mur se trouve dans la trajectoire du rayon
     * entré en paramètre.
     */
    Point * includeRay(const Ray &) const;

    /**
     * Permet de savoir si deux murs sont identiques.
     *
     * @return <code>true</code> Si les murs sont les même.
     */
    bool operator==(const Wall &) const;
};

std::ostream & operator<<(std::ostream &, const Wall &);

#endif // WALL_H
