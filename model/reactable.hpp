#ifndef REACTABLE_HPP
#define REACTABLE_HPP
#include "ray.hpp"

class Reactable
{

public:

    virtual void reactToRay(Ray &) = 0;
    virtual bool includePoint(Point &) = 0;

protected:
    // Sinon la classe "abstraite" peut être instanciable.
    Reactable();
    ~Reactable();

};

#endif // REACTABLE_HPP
