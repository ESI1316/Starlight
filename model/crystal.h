#ifndef CRYSTAL_H
#define CRYSTAL_H

#include "point.h"
#include <ostream>

/**
 * Cette classe modélise les cristaux utilisés dans le jeu.
 * </p>
 * Un cristal est un objet circulaire centré en un point, et
 * d'un certain rayon.
 * </p>
 * Un rayon lumineux passant à travers un crystal modifie sa
 * longueur d'onde (en l'augmentant ou en la diminuant d'une
 * certaine valeur) mais pas sa trajectoire.
 */
class Crystal
{
    Point center;
    int rad;
    int mod;

  public:
    /**
     * Instancie un cristal centré au point donné, d'un certain
     * rayon et modifiant la longueur d'onde des rayons qui le
     * traversent d'une valeur donnée.
     * @param p le centre du cristal
     * @param r le rayon du cristal
     * @param m le modificateur de longueur d'onde du cristal
     */
    Crystal(const Point & p, int r, int m);

    /**
     * Retourne la coordonée du centre du cristal
     * @return  la coordonée du centre du cristal
     */
    const Point & getCenter() const;

    /**
     * Retourne le modificateur de longueur d'onde du cristal
     * @return  le modificateur de longueur d'onde du cristal
     */
    int getModifier() const;

    /**
     * Retourne le rayon du cristal
     * @return le rayon du cristal
     */
    int getRadius() const;

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher
     * un récapitulatif des caractéristiques du cristal
     * sous-jacent en console.
     * @return le flux dans lequel le cristal a été imprimé.
     */
    friend std::ostream & operator<<(std::ostream &,
                                     const Crystal &);

};

#endif // CRYSTAL_H