#ifndef DEST_H
#define DEST_H

#include <ostream>
#include "model/element.hpp"

/**
 * Cette classe modélise la destination utilisée dans le jeu.
 * </p>
 * Une destination est un objet carré qui, quand traversé par
 * un rayon lumineux, fait remporter la partie au joueur.
 */
class Dest : public Element
{
    Point position;
    int edge;
    bool light;

public:

    /**
     * Intancie une destination, de position et rayon donné.
     * @param p le coin supérieur gauche du carré modélisant
     *        la destination.
     * @param e la longueur du côté du carré.
     */
    Dest(const Point &, const int);

    /**
     * Retourne la position du coin supérieur gauche du carré
     * modélisant la destination.
     * @return la position de la destination.
     */
    const Point & getPosition() const;

    /**
     * Retourne la longueur du côté du carré.
     * @return la longueur du côté du carré.
     */
    int getEdge() const;

    /**
     * Retourne vrai si la destination est illuminée,
     * faux sinon.
     * @return vrai si la destination est illuminée,
     * faux sinon.
     */
    bool isLightedUp() const;

    /**
     * Illumine la destination ou non.
     * @param vrai si la destination doit être illuminée,
     * faux sinon.
     */
    void setLightedUp(const bool);

    /**
     * Réaction à l'exposition d'un rayon.
     *
     * @param ray Le rayon.
     */
    void reactToRay(Ray &);

    /**
     * Renseigne si la destination est dans la trajectoire du rayon.
     *
     * @param ray Le rayon.
     *
     * @return true Si la destination se trouve dans la trajectoire du rayon
     * entré en paramètre.
     */
    Point * includeRay(const Ray &) const;

    /**
     * Permet de savoir si deux destinations sont les même
     *
     * @return <code>true</code> Si les destinations sont les même.
     */
    bool operator==(const Dest &) const;
};

#endif // DEST_H
