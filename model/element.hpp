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
    virtual bool includeRay(const Ray &) const = 0;

    void setLevel(Level *);
    Level * getLevel() const;
};

#endif // ELEMENT_HPP
