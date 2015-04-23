#ifndef MIRROR_HPP
#define MIRROR_HPP

#include <ostream>

#include "model/elements/element.hpp"
#include "model/geometry/line.hpp"
#include "model/geometry/point.hpp"

class Ray;

/*!
 * \brief Cette classe modélise les miroirs utilisés dans le jeu.
 * Un miroir est un segment de droite dont la propriété est
 * de réfléchir la lumière d'un seul côté uniquement. Si un
 * rayon lumineux touche un miroir du côté non réfléchissant,
 * le miroir se comporte comme un mur.
 * Les miroirs sont capables d'être déplacés et pivotés dans
 *  une certaine limite.
 */
class Mirror : public Element, public Line
{
    /*!
     * \brief Le point de pivot du miroir autour du quel celui-ci peut éffectuer
     * une rotation.
     */
    Point pivot;

    /*!
     * \brief La longueur totale du miroir.
     */
    int length;

    /*!
     * \brief La longueur séparant le point de pivot d'un point extrême du miroir.
     */
    int xpad;

    /*!
     * \brief Limite minimale d'abcisse où peut se situer le pivot du miroir.
     */
    double xMin;

    /*!
     * \brief Limite maximale d'abcisse où peut se situer le pivot du miroir.
     */
    double xMax;

    /*!
     * \brief Limite minimale d'ordonnée où peut se situer le pivot du miroir.
     */
    double yMin;

    /*!
     * \brief Limite maximale d'ordonnée où peut se situer le pivot du miroir.
     */
    double yMax;

    /*!
     * \brief L'angle actuel de rotation du miroir.
     */
    double alpha;

    /*!
     * \brief L'angle minimum dans lequel peut se trouver le miroir.
     */
    double alphaMin;

    /*!
     * \brief L'angle maximum dans lequel peut se trouver le miroir.
     */
    double alphaMax;

public:

    /*!
     * \brief Instancie un miroir en une position donnée, d'une certaine longueur et
     * orienté d'un certain angle. Comme dans ce constructeur les limites de
     * déplacement et de rotation du miroir ne sont pas définies, ce miroir
     * peut se déplacer et pivoter librement.
     *
     * \param pivot La position du pivot du miroir.
     * \param xpad Le décalage du pivot par rapport au bord gauche du miroir.
     * \param length La longueur du miroir.
     * \param alpha L'angle d'inclinaison du miroir.
     */
    Mirror(const Point &, int, int, double);

    /*!
     * \brief Instancie un miroir en une position donnée, d'une certaine longueur
     * et orienté d'un certain angle.
     * Ce constructeur permet également aux miroirs de pivoter
     * dans une certaine limite.
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que si :
     * <ul>
     * <li>a = b, le miroir ne peut être déplacé sur l'axe considéré</li>
     * <li>a < b, le miroir pivote dans le sens horloger</li>
     * <li>a = b le miroir ne peut pas pivoter</li>
     * <li>a > b, le miroir pivote dans le sens anti-horloger</li>
     * </ul>
     *
     * \param pivot La position du pivot du miroir.
     * \param xpad Le décalage du pivot par rapport au bord gauche du miroir.
     * \param length La longueur du miroir.
     * \param alpha L'angle d'inclinaison du miroir.
     * \param pointMin Le point de coordonnées minimum.
     * \param pointMax Le point de coordonnées maximum.
     * \param alphaMin L'angle d'inclinaison minimum du miroir (en radian).
     * \param alphaMax L'angle d'inclinaison maximum du miroir (en radian).
     */
    Mirror(const Point &, int, int, double, Point, Point, double, double);

    /*!
     * \brief Retourne la position du pivot du miroir.
     *
     * \return La position du pivot du miroir.
     */
    const Point & getPivot() const;

    /*!
     * \brief Retourne la longueur du miroir.
     *
     * \return La longueur du miroir.
     */
    int getLength() const;

    /*!
     * \brief Retourne le décalage du pivot par rapport au bord gauche du miroir.
     *
     * \return Le décalage du pivot par rapport au bord gauche du miroir.
     */
    int getXPad() const;

    /*!
     * \brief Retourne l'inclinaison du miroir.
     *
     * \return l'inclinaison du miroir.
     */
    double getAngle() const;

    /*!
     * \brief Retourne l'inclinaison minimum du miroir.
     * Si l'intervalle de limite d'inclinaison [a,b] est tel que :
     * <ul>
     * <li>a < b, le miroir pivote dans le sens horloger</li>
     * <li>a = b, le miroir ne peut pas pivoter</li>
     * <li>a > b, le miroir pivote dans le sens anti-horloger</li>
     * <li>Si a = b = 0, le miroir peut être pivoté librement</li>
     * </ul>
     *
     * \return l'inclinaison minimum du miroir en radian.
     */
    double getMinAngle() const;

    /*!
     * \brief Retourne l'inclinaison minimum du miroir.
     * Si l'intervalle de limite d'inclinaison [a,b] est tel que :
     * <ul>
     * <li>a < b, le miroir pivote dans le sens horloger</li>
     * <li>a = b, le miroir ne peut pas pivoter</li>
     * <li>a > b, le miroir pivote dans le sens anti-horloger</li>
     * <li>Si a = b = 0, le miroir peut être pivoté librement</li>
     * </ul>
     *
     * \return l'inclinaison maximum du miroir en radian.
     */
    double getMaxAngle() const;

    /*!
     * \brief Retourne la position minimum du miroir.
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que :
     * <ul>
     * <li>a = b, le miroir ne peut être déplacé sur l'axe considéré</li>
     * <li>a = b = 0, le miroir peut être déplacé librement</li>
     * </ul>
     *
     * \return la position minimum du miroir.
     */
    Point getMinPivot() const;

    /*!
     * \brief Retourne la position maximum du miroir.
     * </p>
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que a = b, le miroir ne peut
     * être déplacé sur l'axe considéré. Si a = b = 0, le miroir
     * peut être déplacé librement.
     * \return la position minimum du miroir.
     */
    Point getMaxPivot() const;

    /*!
     * \brief Déplace le miroir en la position donnée, si celle-ci est autorisée.
     *
     * \see Mirror::getPivot()
     *
     * \return <code>true</code> Si le déplacement a été effectué.
     */
    bool setPivot(const Point &);

    /*!
     * \brief Pivote le miroir sur un angle donné, si celui-ci est autorisé.
     *
     * \see Mirror::getAngle()
     *
     * \return <code>true</code> Si la rotation a été effectuée.
     */
    bool setAngle(double);

    /*!
     * \brief Permet d'<b>essayer</b> d'éffectuer une rotation du miroir courant.
     *
     * \param alpha L'angle de rotation en degrés.
     *
     * \return <code>true</code> Si le miroir ne sort pas des limites après
     * rotation.
     */
    bool rotate(double);

    /*!
     * \brief Permet de déplacer le miroir dans le plan en lui donnant un abcisse
     * et une ordonnée de translation.
     *
     * \param x Le déplacement sur l'axe des abcisses.
     * \param y Le déplacement sur l'axe des ordonnées.
     *
     * \return <code>true</code> Si le miroir ne sort pas des limites après
     * translations.
     */
    bool translate(const double, const double);

    /*!
     * \brief Retourne le point de départ du segment de droite représentant le
     * miroir.
     *
     * \return Le point de départ du segment de droite représentant le miroir.
     */
    Point getStart() const;

    /*!
     * \brief Retourne le point d' arrivé du segment de droite représentant le
     * miroir.
     *
     * \return Le point d'arrivé du segment de droite représentant le miroir.
     */
    Point getEnd() const;

    /*!
     * \brief Permet d'obtenir le point de départ et d'arrivé du segment de droite
     * représentant le miroir; pour éviter de retourner un conteneur de points,
     * ceux-ci sont passés en entrée-sortie des paramètres.
     */
    void getBounds(Point *, Point *) const;

    /*!
     * \brief Retoune vrai si le miroir peut être pivoté sur
     * l'angle donné, retourne faux sinon.
     *
     * \return <code>true</code> si le miroir peut être pivoté sur
     * l'angle donné, retourne faux sinon.
     *
     */
    bool checkAngleRange(double) const;

    /*!
     * \brief Retoune vrai si le miroir peut être éplacé en la
     * position donnée, retourne faux sinon.
     *
     * \return <code>true</code> si le miroir peut être déplacé en
     * la position donnée, retourne faux sinon.
     *
     */
    bool checkPivotRange(const Point &) const;

    /*!
     * \brief Réaction à l'exposition d'un rayon; celui-ci est réflechi selon le
     * principe naturel de la reflexion de la lumière dans l'air.
     *
     * Cette méthode communiquera au niveau de prendre en compte le nouveau rayon
     * créé.
     *
     * \param ray Le rayon incident.
     */
    void reactToRay(Ray);

    /*!
     * \brief Renseigne si le mirroir est dans la trajectoire du rayon.
     *
     * \param ray Le rayon.
     *
     * \return <code>true</code> Si le mirroir se trouve dans la trajectoire du rayon entré
     * en paramètre.
     */
    Point * includeRay(const Ray &) const;

    /*!
     * \brief Permet de savoir si deux mirroirs sont les même.
     *
     * \return <code>true</code> Si deux mirroirs sont les même.
     */
    bool operator==(const Mirror &) const;

    /*!
     * \brief Permet de savoir si deux mirroirs sont différents.
     *
     * \return <code>true</code> Si deux mirroirs sont différents.
     */
    bool operator!=(const Mirror &) const;

};

/*!
 * \brief Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * \return Le ostream rempli de la chaine formatée représentant le Mirror en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Mirror &);

inline const Point & Mirror::getPivot() const
{
    return this->pivot;
}

inline int Mirror::getLength() const
{
    return this->length;
}

inline int Mirror::getXPad() const
{
    return this->xpad;
}

inline double Mirror::getAngle() const
{
    return this->alpha;
}

inline double Mirror::getMinAngle() const
{
    return this->alphaMin;
}

inline double Mirror::getMaxAngle() const
{
    return this->alphaMax;
}

#endif // MIRROR_HPP
