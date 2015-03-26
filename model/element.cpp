#include "element.hpp"
#include "level.hpp"


/**
 * @brief Element::setLevel
 * @param level
 */
void Element::setLevel(Level * level)
{
    if(this->level == nullptr)
        this->level = level;
}
