#ifndef NUKE_H
#define NUKE_H

#include <ostream>

#include "model/element.hpp"
#include "model/point.hpp"
#include "model/geometry/ellipse.hpp"

/**
 * Cette classe modélise les bombes utilisées dans le jeu.
 * Une bombe est un objet circulaire qui, si illuminé par un rayon, fait
 * perdre la partie au joueur.
 */
class Nuke : public Element, public Ellipse
{
    bool light {false};

public:

    /**
     * Instancie une bombe en une position donnée avec un rayon déterminé.
     *
     * @param position La position du centre de la bombe.
     * @param radius Le rayon de la bombe.
     */
    Nuke(const Point &,const double);

    /**
     * Retourne la position de la bombe.
     * @return la position de la bombe.
     */
    const Point & getLocation() const;

    /**
     * Retourne le rayon de la bombe.
     * @return le rayon de la bombe.
     */
    int getRadius() const;

    /**
     * Cette méthode permet de savoir si la bombe est illuminée.
     *
     * @return <code>true</code> Si la bombe est illuminée, faux sinon.
     */
    bool isLightedUp() const;

    /**
     * Cette méthode permet d'établir un nouvel état d'illumination de la bombe.
     *
     * @param light Le nouvel état d'illumination de la bombe.
     */
    void setLightedUp(const bool);

    /**
     * Réaction à l'exposition d'un rayon.
     *
     * @param ray Le rayon.
     */
    void reactToRay(Ray &);

    /**
     * Renseigne si la bombe est dans la trajectoire du rayon.
     *
     * @param ray Le rayon.
     *
     * @return <code>true</code> Si la bombe se trouve dans la trajectoire du
     * rayon entré en paramètre.
     */
    Point * includeRay(const Ray & ray) const;

    /**
     * Permet de savoir si deux bombes sont les mêmes.
     *
     * @return <code>true</code> Si les deux bombes sont les mêmes.
     */
    bool operator==(const Nuke &) const;

    /**
     * Permet de savoir si deux bombes sont différentes.
     *
     * @return <code>true</code> Si les deux bombes sont différentes.
     */
    bool operator!=(const Nuke &) const;
};

/**
 * Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * @return Le ostream rempli de la chaine formatée représentant le Nuke en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Nuke &);

#endif // NUKE_H
