#ifndef ELEMENT_HPP
#define ELEMENT_HPP

class Level;

class Element
{

private :

    Level * level{nullptr};

protected :

    Element() = default;
    ~Element();

public :

    void setLevel(Level *);
};

#endif // ELEMENT_HPP
