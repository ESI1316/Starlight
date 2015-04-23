#ifndef ELEMENT_HPP
#define ELEMENT_HPP

class Level;
class Ray;
class Point;

/*!
 * \brief Un element est un composant du jeu se devant de communiquer son état
 * au niveau le gérant. Cette pratique permet au niveau d'écouter les actions à
 * éffectuer dicter par l'élément.
 */
class Element
{
private :

    /*!
     * Le niveau lié à un element.
     */
    Level * level{nullptr};

protected :

    /*!
     * Constructeur par défaut, en visibilité protected permettant d'éviter une
     * tentative d'instanciation de cette classe abstraite.
     */
    Element() = default;

public :

    /*!
     * \brief Réaction à l'exposition d'un rayon.
     *
     * \param ray Le rayon.
     */
    virtual void reactToRay(Ray) = 0;

    /*!
     * \brief Renseigne si l'élément est dans la trajectoire du rayon.
     *
     * \param ray Le rayon.
     *
     * \return <code>true</code> Si l'élément se trouve dans la trajectoire du rayon
     * entré en paramètre.
     */
    virtual Point * includeRay(const Ray &) const = 0;

    /*!
     * \brief Permet de modifier le level auquel appertient l'élément.
     *
     * \param nouveau level auquel appartient l'élément.
     */
    void setLevel(Level *);

    /*!
     * \brief Permet d'obtenir un pointeur sur le niveau auquel appartient l'élément.
     *
     * \return un pointeur vers le niveau auquel appartient l'élément.
     */
    Level * getLevel();

    /*!
     * \brief Compare deux éléments pour savoir si ils pointent vers le même niveau.
     *
     * \return <code>true</code> Si les deux éléments sont liés au même niveau.
     */
    bool operator==(const Element &) const;
};

inline Level * Element::getLevel()
{
    return this->level;
}

#endif // ELEMENT_HPP
