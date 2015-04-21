#include "model/elements/element.hpp"

#include "model/elements/level.hpp"


void Element::setLevel(Level * level)
{
    this->level = level;
}

bool Element::operator==(const Element & element) const
{
    return this->level == element.level;
}
