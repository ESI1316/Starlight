#ifndef NUKE_H
#define NUKE_H

#include <ostream>
//#include "model/point.hpp"
#include "model/element.hpp"

/**
 * Cette classe modélise les bombes utilisées dans le jeu.
 * </p>
 * Une bomnbe est un objet circulaire qui, si illuminé par
 * un rayon, fait perdre la partie au joueur.
 */
class Nuke : Element
{
    Point position;
    double radian;
    bool light {false};


public:

    /**
     * Instancie une bombe en une position donnée avec un rayon
     * déterminé.
     * @param p la position de la bombe
     * @param r le rayon de la bombe
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
     * Retourne vrai si la bombe est illuminée, faux sinon.
     * @return vrai si la bombe est illuminée, faux sinon.
     */
    bool isLightedUp() const;

    /**
     * Illumine la bombe ou non.
     *
     * @param q vrai si la bombe est illuminée, faux sinon.
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
     * @return true Si la bombe se trouve dans la trajectoire du rayon entré en
     * paramètre.
     */
    Point * includeRay(const Ray & ray) const;

    /**
     * Permet de savoir si deux bombes sont les mêmes.
     *
     * @return <code>true</code> Si les deux bombes sont les mêmes.
     */
    bool operator==(const Nuke &) const;
};

#endif // NUKE_H
