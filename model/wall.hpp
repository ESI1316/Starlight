#ifndef WALL_H
#define WALL_H

#include <iostream>
#include "point.hpp"

class Level;

/**
 * Cette classe modélise les murs utilisés dans le jeu.
 * </p>
 * Les murs sont des segments de droite qui ne réfléchissent
 * pas la lumière.
 */
class Wall
{
    Point start;
    Point end;

    Level * level;

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

    Wall & operator=(const Wall &);
    /**
     * Surcharge l'opérateur de flux de sortie pour afficher
     * un récapitulatif des caractéristiques du mur sous-jacent
     * en console.
     * @return le flux dans lequel le mur a été imprimé.
     */
    // friend std::ostream & operator<<(std::ostream &, const Wall &);
};

#endif // WALL_H
