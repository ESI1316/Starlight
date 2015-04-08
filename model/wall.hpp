#ifndef WALL_H
#define WALL_H

#include <ostream>
#include "model/element.hpp"

/**
 * Cette classe modélise les murs utilisés dans le jeu. Les murs sont des
 * segments de droite qui ne réfléchissent pas la lumière.
 */
class Wall : public Element, public Line
{
    Point start;
    Point end;

public:

    /**
     * Instancie un mur.
     * @param start Le début du mur.
     * @param end La fin du mur.
     */
    Wall(const Point &, const Point &);

    /**
     * Retourne le début du mur.
     *
     * @return Le début du mur.
     */
    const Point & getStart() const;

    /**
     * Retourne la fin du mur.
     *
     * @return La fin du mur.
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

    /**
     * Permet de savoir si deux murs sont différents.
     *
     * @return <code>true</code> Si les murs sont différents.
     */
    bool operator!=(const Wall &) const;
};

/**
 * Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * @return Le ostream rempli de la chaine formatée représentant le Wall en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Wall &);

#endif // WALL_H
