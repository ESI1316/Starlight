#ifndef DEST_H
#define DEST_H

#include <ostream>
#include "model/element.hpp"
#include "model/rectangle.hpp"

/**
 * Cette classe modélise la destination utilisée dans le jeu.
 * Une destination est un objet carré qui, quand traversé par
 * un rayon lumineux, fait remporter la partie au joueur.
 */
class Dest : public Element, public Rectangle
{

private :

    bool light;

public:

    /**
     * Intancie une destination, de position et rayon donné.
     *
     * @param position Le coin supérieur gauche du carré modélisant la destination.
     * @param edge La longueur du côté du carré.
     */
    Dest(const Point &, const int);

    /**
     * Retourne la position du coin supérieur gauche du carré modélisant la destination.
     *
     * @return La position de la destination.
     */
    const Point & getPosition() const;

    /**
     * Retourne la longueur du côté du carré.
     * @return La longueur du côté du carré.
     */
    int getEdge() const;

    /**
     * Permet de savoir si la destination est éclairée et donc si le jeu est
     * terminé.
     *
     * @return <code>true</code> Si la destination est illuminée.
     */
    bool isLightedUp() const;

    /**
     * Permet de changer l'état d'illumination de la destination.
     *
     * @param Le nouvelle état d'illumination de la destination.
     */
    void setLightedUp(const bool);

    /**
     * Cette méthode est lancé lorsque la destination courant est exposé à un rayon.
     * Elle va s'exposer comme illuminée.
     *
     * @param ray Un rayon percutant la destination.
     */
    void reactToRay(Ray &);

    /**
     * Renseigne si la destination est dans la trajectoire du rayon.
     *
     * @param ray Le rayon.
     *
     * @return <code>true</code> Si la destination se trouve dans la trajectoire
     * du rayon entré en paramètre.
     */
    Point * includeRay(const Ray &) const;

    /**
     * Permet de savoir si deux destinations sont les même
     *
     * @return <code>true</code> Si les destinations sont les même.
     */
    bool operator==(const Dest &) const;

    /**
     * Permet de savoir si deux destinations sont différentes.
     *
     * @return <code>true</code> Si les destinations sont différentes.
     */
    bool operator!=(const Dest &) const;
};

/**
 * Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * @return Le ostream rempli de la chaine formatée représentant la Dest en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Dest &);

#endif // DEST_H
