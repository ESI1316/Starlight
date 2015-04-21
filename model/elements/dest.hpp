#ifndef DEST_HPPPP
#define DEST_HPPPP

#include <ostream>

#include "model/elements/element.hpp"
#include "model/geometry/rectangle.hpp"

class Point;
class Ray;

/*!
 * \brief Cette classe modélise la destination utilisée dans le jeu.
 * Une destination est un objet carré qui, quand traversé par
 * un rayon lumineux, fait remporter la partie au joueur.
 */
class Dest : public Element, public Rectangle
{

private :

    bool light;

public:

    /*!
     * \brief Intancie une destination, de position et rayon donné.
     *
     * \param position Le coin supérieur gauche du carré modélisant la destination.
     * \param edge La longueur du côté du carré.
     */
    Dest(const Point &, const int);

    /*!
     * \brief Retourne la position du coin supérieur gauche du carré modélisant la destination.
     *
     * \return La position de la destination.
     */
    const Point & getPosition() const;

    /*!
     * \brief Retourne la longueur du côté du carré.
     *
     * \return La longueur du côté du carré.
     */
    int getEdge() const;

    /*!
     * \brief Permet de savoir si la destination est éclairée et donc si le jeu est
     * terminé.
     *
     * \return <code>true</code> Si la destination est illuminée.
     */
    bool isLightedUp() const;

    /*!
     * \brief Permet de changer l'état d'illumination de la destination.
     *
     * \param Le nouvelle état d'illumination de la destination.
     */
    void setLightedUp(const bool);

    /*!
     * \brief Cette méthode est lancé lorsque la destination courant est exposé à un rayon.
     * Elle va s'exposer comme illuminée.
     *
     * \param ray Un rayon percutant la destination.
     */
    void reactToRay(Ray);

    /*!
     * \brief Renseigne si la destination est dans la trajectoire du rayon.
     *
     * \param ray Le rayon.
     *
     * \return <code>true</code> Si la destination se trouve dans la trajectoire
     * du rayon entré en paramètre.
     */
    Point * includeRay(const Ray &) const;

    /*!
     * \brief Permet de savoir si deux destinations sont les même
     *
     * \return <code>true</code> Si les destinations sont les même.
     */
    bool operator==(const Dest &) const;

    /*!
     * \brief Permet de savoir si deux destinations sont différentes.
     *
     * \return <code>true</code> Si les destinations sont différentes.
     */
    bool operator!=(const Dest &) const;
};

/*!
 * \brief Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * \return Le ostream rempli de la chaine formatée représentant la Dest en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Dest &);

inline const Point & Dest::getPosition() const
{
    return this->upLeftCorner;
}

inline int Dest::getEdge() const
{
    return this->height;
}

inline bool Dest::isLightedUp() const
{
    return this->light;
}

#endif // DEST_HPP
