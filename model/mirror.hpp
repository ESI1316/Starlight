#ifndef MIRROR_HPP
#define MIRROR_HPP

#include <ostream>
#include "model/element.hpp"
#include "model/point.hpp"

class Ray;

/**
 * Cette classe modélise les miroirs utilisés dans le jeu.
 * Un miroir est un segment de droite dont la propriété est
 * de réfléchir la lumière d'un seul côté uniquement. Si un
 * rayon lumineux touche un miroir du côté non réfléchissant,
 * le miroir se comporte comme un mur.
 * Les miroirs sont capables d'être déplacés et pivotés dans
 *  une certaine limite.
 */
class Mirror : public Element
{
    Point pivot;
    int length;
    int xpad;
    double xMin;
    double xMax;
    double yMin;
    double yMax;
    double alpha;
    double alphaMin;
    double alphaMax;

public:

    /**
     * Instancie un miroir en une position donnée, d'une certaine longueur et
     * orienté d'un certain angle. Comme dans ce constructeur les limites de
     * déplacement et de rotation du miroir ne sont pas définies, ce miroir
     * peut se déplacer et pivoter librement.
     *
     * @param pivot La position du pivot du miroir.
     * @param xpad Le décalage du pivot par rapport au bord gauche du miroir.
     * @param length La longueur du miroir.
     * @param alpha L'angle d'inclinaison du miroir.
     */
    Mirror(const Point &, int, int, double);

    /**
     * Instancie un miroir en une position donnée, d'une certaine longueur
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
     * @param pivot La position du pivot du miroir.
     * @param xpad Le décalage du pivot par rapport au bord gauche du miroir.
     * @param length La longueur du miroir.
     * @param alpha L'angle d'inclinaison du miroir.
     * @param pointMin Le point de coordonnées minimum.
     * @param pointMax Le point de coordonnées maximum.
     * @param alphaMin L'angle d'inclinaison minimum du miroir (en radian).
     * @param alphaMax L'angle d'inclinaison maximum du miroir (en radian).
     */
    Mirror(const Point &, int, int, double, Point, Point, double, double);

    /**
     * Retourne la position du pivot du miroir.
     *
     * @return La position du pivot du miroir.
     */
    const Point & getPivot() const;

    /**
     * Retourne la longueur du miroir.
     *
     * @return La longueur du miroir.
     */
    int getLength() const;

    /**
     * Retourne le décalage du pivot par rapport au bord gauche du miroir.
     *
     * @return Le décalage du pivot par rapport au bord gauche du miroir.
     */
    int getXPad() const;

    /**
     * Retourne l'inclinaison du miroir.
     *
     * @return l'inclinaison du miroir.
     */
    double getAngle() const;

    /**
     * Retourne l'inclinaison minimum du miroir.
     * Si l'intervalle de limite d'inclinaison [a,b] est tel que :
     * <ul>
     * <li>a < b, le miroir pivote dans le sens horloger</li>
     * <li>a = b, le miroir ne peut pas pivoter</li>
     * <li>a > b, le miroir pivote dans le sens anti-horloger</li>
     * <li>Si a = b = 0, le miroir peut être pivoté librement</li>
     * </ul>
     *
     * @return l'inclinaison minimum du miroir en radian.
     */
    double getMinAngle() const;

    /**
     * Retourne l'inclinaison minimum du miroir.
     * Si l'intervalle de limite d'inclinaison [a,b] est tel que :
     * <ul>
     * <li>a < b, le miroir pivote dans le sens horloger</li>
     * <li>a = b, le miroir ne peut pas pivoter</li>
     * <li>a > b, le miroir pivote dans le sens anti-horloger</li>
     * <li>Si a = b = 0, le miroir peut être pivoté librement</li>
     * </ul>
     *
     * @return l'inclinaison maximum du miroir en radian.
     */
    double getMaxAngle() const;

    /**
     * Retourne la position minimum du miroir.
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que :
     * <ul>
     * <li>a = b, le miroir ne peut être déplacé sur l'axe considéré</li>
     * <li>a = b = 0, le miroir peut être déplacé librement</li>
     * </ul>
     *
     * @return la position minimum du miroir.
     */
    Point getMinPivot() const;

    /**
     * Retourne la position maximum du miroir.
     * </p>
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que a = b, le miroir ne peut
     * être déplacé sur l'axe considéré. Si a = b = 0, le miroir
     * peut être déplacé librement.
     * @return la position minimum du miroir.
     */
    Point getMaxPivot() const;

    /**
     * Déplace le miroir en la position donnée, si celle-ci est autorisée.
     *
     * @see Mirror::getPivot()
     *
     * @return <code>true</code> Si le déplacement a été effectué.
     */
    bool setPivot(const Point &);

    /**
     * Pivote le miroir sur un angle donné, si celui-ci est autorisé.
     *
     * @see Mirror::getAngle()
     *
     * @return <code>true</code> Si la rotation a été effectuée.
     */
    bool setAngle(double);

    /**
     * Retoune vrai si le miroir peut être pivoté sur
     * l'angle donné, retourne faux sinon.
     * @return vrai si le miroir peut être pivoté sur
     * l'angle donné, retourne faux sinon.
     * @see Mirror::getAngle()
     */
    bool checkAngleRange(double) const;

    /**
     * Retoune vrai si le miroir peut être éplacé en la
     * position donnée, retourne faux sinon.
     * @return vrai si le miroir peut être déplacé en
     * la position donnée, retourne faux sinon.
     * @see Mirror::getPivot()
     */
    bool checkPivotRange(const Point &) const;

    /**
     * Réaction à l'exposition d'un rayon.
     * Le rayon incident du miroir égal au rayon réflechi. Pour ainsi calculer
     * le coeficiant angulaire de l'angle réflechis, on utilise la démonstration
     * suivante :
     *
     * Soient alpha l'angle de pivot du miroir (sens anti-horlogé, augmentation
     * des degré dans le sens du cercle trigonométrique), slope le coefficiant
     * angulaire du rayon déjà tiré, et ray.getEnd() le point de colision avec
     * le miroir,
     *          \
     *           \MIROIR
     * _ _ _ __ _ê\ _ _ _ _ MIROIR AVEC ALPHA 0
     *             \ê       ê = ê car opposés par le sommet
     *              \
     * _ _  _ _ _ _ ê\_ _ _ ê = ê car alterne interne
     *             ô/ \		ô = â car les angles sont alterne-interne
     *             /   \
     *            /     \
     *           /       \
     *          /         \
     *         /â		   \ 	ê = angle de rotation du miroir
     * --------------------		â = angle (coefficiant ang.) du rayon
     *
     * Angle réflechis = M_PI - (â + (2 * M_PI - ê))
     * 					= M_PI - (â + 2 * M_PI - ê)
     * 					= M_PI - â - 2 * M_PI + ê
     * 					= - M_PI + ê - â
     *
     * @param ray Le rayon.
     */
    void reactToRay(Ray &);

    /**
     * Renseigne si le mirroir est dans la trajectoire du rayon.
     *
     * @param ray Le rayon.
     *
     * @return true Si le mirroir se trouve dans la trajectoire du rayon entré
     * en paramètre.
     */
    Point * includeRay(const Ray &) const;

    /**
     * Permet de savoir si deux mirroirs sont les même.
     *
     * @return <code>true</code> Si deux mirroirs sont les même.
     */
    bool operator==(const Mirror &) const;

    /**
     * Permet de savoir si deux mirroirs sont différents.
     *
     * @return <code>true</code> Si deux mirroirs sont différents.
     */
    bool operator!=(const Mirror &) const;

};

/**
 * Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * @return Le ostream rempli de la chaine formatée représentant le Mirror en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Mirror &);

#endif // MIRROR_HPP
