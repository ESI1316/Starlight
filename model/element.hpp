#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "ray.hpp"

class Level;

class Element
{
private :

    Level * level{nullptr};

protected :

    Element() = default;

public :

    /**
     * Réaction à l'exposition d'un rayon.
     *
     * @param ray Le rayon.
     */
    virtual void reactToRay(Ray &) = 0;

    /**
     * Renseigne si l'élément est dans la trajectoire du rayon.
     *
     * @param ray Le rayon.
     *
     * @return true Si l'élément se trouve dans la trajectoire du rayon
     * entré en paramètre.
     */
    virtual bool includeRay(const Ray &) const = 0;

    /**
     * Permet de modifier le level auquel appertient l'élément.
     *
     * @param nouveau level auquel appartient l'élément.
     */
    void setLevel(Level *);

    /**
     * Permet d'obtenir un pointeur sur le niveau auquel appartient l'élément.
     *
     * @return un pointeur vers le niveau auquel appartient l'élément.
     */
    Level * getLevel() const;

    /**
     * Compare deux éléments pour savoir si ils pointent vers le même niveau.
     *
     * @return <code>true</code> Si les deux éléments sont liés au même niveau.
     */
    bool operator==(const Element &) const;
};

#endif // ELEMENT_HPP
