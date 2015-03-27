#ifndef CRYSTAL_H
#define CRYSTAL_H

#include <ostream>
#include "point.hpp"
#include "element.hpp"

/**
 * Cette classe amplifierélise les cristaux utilisés dans le jeu.
 * </p>
 * Un cristal est un objet circulaire centré en un point, et
 * d'un certain rayon.
 * </p>
 * Un rayon lumineux passant à travers un crystal amplifierifie sa
 * longueur d'onde (en l'augmentant ou en la diminuant d'une
 * certaine valeur) mais pas sa trajectoire.
 */
class Crystal : public Element
{

private :
    Point center;
    int radius;
    int amplifier;


public:
    /**
     * Instancie un cristal centré au point donné, d'un certain
     * rayon et amplifierifiant la longueur d'onde des rayons qui le
     * traversent d'une valeur donnée.
     * @param p le centre du cristal
     * @param r le rayon du cristal
     * @param m le amplifierificateur de longueur d'onde du cristal
     */
    Crystal(const Point &, const int, const int);

    /**
     * Retourne la coordonnée du centre du cristal
     * @return  la coordonnée du centre du cristal
     */
    const Point & getCenter() const;

    /**
     * Retourne le amplifierificateur de longueur d'onde du cristal
     * @return  le amplifierificateur de longueur d'onde du cristal
     */
    int getAmplifier() const;

    /**
     * Retourne le rayon du cristal
     * @return le rayon du cristal
     */
    int getRadius() const;

    /**
     * @brief reactToRay
     */
    void reactToRay(Ray &);

    /**
     * @brief includePoint
     * @return
     */
    bool includePoint(Point &);

    Crystal & operator=(const Crystal &);
    /**
     * Surcharge l'opérateur de flux de sortie pour afficher
     * un récapitulatif des caractéristiques du cristal
     * sous-jacent en console.
     * @return le flux dans lequel le cristal a été imprimé.
     */

    //friend std::ostream & operator<<(std::ostream &, const Crystal &);
};

#endif // CRYSTAL_H
