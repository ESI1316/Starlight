#ifndef CRYSTAL_HPP
#define CRYSTAL_HPP

#include <ostream>

#include "model/elements/element.hpp"
#include "model/geometry/ellipse.hpp"
#include "model/geometry/utilities.hpp"

class Ray;
class Point;

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
class Crystal : public Element, public Ellipse
{
private :

    /**
     * Le modificateur de longueur d'onde agissant sur un rayon passant dans ce
     * cristal.
     */
    int amplifier;

public:

    /**
     * Instancie un cristal :
     * <ul>
     * <li>centré au point donné</li>
     * <li>avec un rayon donné</li>
     * <li>et un amplifier de longueur d'ondes donné</li>
     * </ul>,
     *
     * ce crystal modifie la longueur d'onde du rayon le traversant en suivant
     * la règle suivante : si la longueur d'onde modifié sort de l'interval
     * [longueur d'onde minimale, longueur d'onde maximale] alors elle ne sera
     * pas appliquée.
     *
     * @param point Le point du centre du cristal.
     * @param radius Le rayon du cristal.
     * @param amplifieur le modificateur de longueur d'onde du cristal.
     */
    Crystal(const Point &, const double, const int);

    /**
     * Retourne le modifieur de longueur d'onde du cristal
     *
     * @return  le modifieur de longueur d'onde du cristal
     */
    int getAmplifier() const;

    /**
     * Retourne la longueur du rayon du cristal
     *
     * @return la longueur du rayon du cristal
     */
    double getRadius() const;

    /**
     * Cette méthode est lancé lorsque le miroir courant est exposé à un rayon.
     * Il va communiquer au niveau le nouveau rayon sortant du cristal.
     *
     * @param ray Un rayon percutant le miroir.
     */
    void reactToRay(Ray);

    /**
     * Renseigne si le crystal est dans la trajectoire du rayon.
     *
     * @param ray Un rayon.
     *
     * @return Un pointeur vers le point d'intersection (le plus eloigné) avec
     * le rayon s'il existe un pointeur null sinon.
     */
    Point * includeRay(const Ray &) const;

    /**
     * Permet de savoir si deux cristaux sont les même.
     *
     * @return <code>true</code> si deux cristaux sont les même.
     */
    bool operator==(const Crystal &) const;

    /**
     * Permet de savoir si deux cristaux sont différents.
     *
     * @return <code>true</code> si deux cristaux sont différents.
     */
    bool operator!=(const Crystal &) const;
};

/**
 * Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * @return Le ostream rempli de la chaine formatée représentant le Crystal en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Crystal &);

#endif // CRYSTAL_HPP
