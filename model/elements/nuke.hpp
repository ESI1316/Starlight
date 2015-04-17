#ifndef NUKE_HPP
#define NUKE_HPP

#include <ostream>

#include "model/elements/element.hpp"
#include "model/geometry/ellipse.hpp"

class Point;
class Ray;

/*!
 * \brief Cette classe modélise les bombes utilisées dans le jeu.
 * Une bombe est un objet circulaire qui, si illuminé par un rayon, fait
 * perdre la partie au joueur.
 */
class Nuke : public Element, public Ellipse
{
    bool light {false};

public:

    /*!
     * \brief Instancie une bombe en une position donnée avec un rayon déterminé.
     *
     * \param position La position du centre de la bombe.
     * \param radius Le rayon de la bombe.
     */
    Nuke(const Point &,const double);

    /*!
     * \brief Retourne la position de la bombe.
     * \return la position de la bombe.
     */
    const Point & getLocation() const;

    /*!
     * \brief Retourne le rayon de la bombe.
     * \return le rayon de la bombe.
     */
    double getRadius() const;

    /*!
     * \brief Cette méthode permet de savoir si la bombe est illuminée.
     *
     * \return <code>true</code> Si la bombe est illuminée, faux sinon.
     */
    bool isLightedUp() const;

    /*!
     * \brief Cette méthode permet d'établir un nouvel état d'illumination de la bombe.
     *
     * \param light Le nouvel état d'illumination de la bombe.
     */
    void setLightedUp(const bool);

    /*!
     * \brief Réaction à l'exposition d'un rayon.
     *
     * \param ray Le rayon.
     */
    void reactToRay(Ray);

    /*!
     * \brief Renseigne si la bombe est dans la trajectoire du rayon.
     *
     * \param ray Le rayon.
     *
     * \return <code>true</code> Si la bombe se trouve dans la trajectoire du
     * rayon entré en paramètre.
     */
    Point * includeRay(const Ray & ray) const;

    /*!
     * \brief Permet de savoir si deux bombes sont les mêmes.
     *
     * \return <code>true</code> Si les deux bombes sont les mêmes.
     */
    bool operator==(const Nuke &) const;

    /*!
     * \brief Permet de savoir si deux bombes sont différentes.
     *
     * \return <code>true</code> Si les deux bombes sont différentes.
     */
    bool operator!=(const Nuke &) const;
};

/*!
 * \brief Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * \return Le ostream rempli de la chaine formatée représentant le Nuke en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Nuke &);

#endif // NUKE_HPP
