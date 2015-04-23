#ifndef WALL_HPP
#define WALL_HPP

#include <ostream>

#include "model/geometry/line.hpp"
#include "model/elements/element.hpp"
#include "model/geometry/point.hpp"

class Ray;

/*!
 * \brief Cette classe modélise les murs utilisés dans le jeu. Les murs sont des
 * segments de droite qui ne réfléchissent pas la lumière.
 */
class Wall : public Element, public Line
{
    /*!
     * \brief Le point de départ du segment de droite représentant le mur.
     */
    Point start;

    /*!
     * \brief Le point d'arrivé du segment de droite représentant le mur.
     */
    Point end;

public:

    /*!
     * \brief Instancie un mur.
     * \param start Le début du mur.
     * \param end La fin du mur.
     */
    Wall(const Point &, const Point &);

    /*!
     * \brief Retourne le début du mur.
     *
     * \return Le début du mur.
     */
    const Point & getStart() const;

    /*!
     * \brief Retourne la fin du mur.
     *
     * \return La fin du mur.
     */
    const Point & getEnd() const;

    /*!
     * \brief Réaction à l'exposition d'un rayon.
     *
     * \param ray Le rayon.
     */
    void reactToRay(Ray);

    /*!
     * \brief Renseigne si le mur est dans la trajectoire du rayon.
     *
     * \param ray Le rayon.
     *
     * \return <code>true</code> Si la mur se trouve dans la trajectoire du rayon
     * entré en paramètre.
     */
    Point * includeRay(const Ray &) const;

    /*!
     * \brief Permet de savoir si deux murs sont identiques.
     *
     * \return <code>true</code> Si les murs sont les même.
     */
    bool operator==(const Wall &) const;

    /*!
     * \brief Permet de savoir si deux murs sont différents.
     *
     * \return <code>true</code> Si les murs sont différents.
     */
    bool operator!=(const Wall &) const;
};

/*!
 * \brief Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * \return Le ostream rempli de la chaine formatée représentant le Wall en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Wall &);

inline const Point & Wall::getStart() const
{
    return this->start;
}

inline const Point & Wall::getEnd() const
{
    return this->end;
}

#endif // WALL_HPP
