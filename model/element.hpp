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

    virtual void reactToRay(Ray &) = 0;
    virtual bool includePoint(Point &) = 0;

    void setLevel(Level *);
};

#endif // ELEMENT_HPP
