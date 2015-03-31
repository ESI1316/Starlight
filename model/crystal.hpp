#ifndef CRYSTAL_H
#define CRYSTAL_H

#include <ostream>
//#include "model/point.hpp"
#include "model/element.hpp"

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
    double radius;
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
    Crystal(const Point &, const double, const int);

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
     * Réaction à l'exposition d'un rayon.
     *
     * @param ray Le rayon.
     */
    void reactToRay(Ray &);

    /**
     * Renseigne si le crystal est dans la trajectoire du rayon.
     *
     * @param ray Le rayon.
     *
     * @return true Si le crystal se trouve dans la trajectoire du rayon entré
     * en paramètre.
     */
    Point * includeRay(const Ray &) const;

    /**
     * Permet de savoir si deux cristaux sont les même.
     *
     * @return <code>true</code> si deux cristaux sont les même.
     */
    bool operator==(const Crystal &) const;
};

#endif // CRYSTAL_H
