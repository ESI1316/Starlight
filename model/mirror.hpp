#ifndef MIRROR_H
#define MIRROR_H

#include <ostream>
//#include "model/point.hpp"
#include "model/element.hpp"

/**
 * Cette classe modélise les miroirs utilisés dans le jeu.
 * </p>
 * Un miroir est un segment de droite dont la propriété est
 * de réfléchir la lumière d'un seul côté uniquement. Si un
 * rayon lumineux touche un miroir du côté non réfléchissant,
 * le miroir se comporte comme un mur.
 * </p>
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
     * Instancie un miroir en une position donnée, d'une certaine
     * longueur et orienté d'un certain angle.
     * </p>
     * Comme dans ce constructeur les limites de déplacement et
     * de rotation du miroir ne sont pas définies, ce miroir
     * peut se déplacer et pivoter librement.
     * @param p la position (et le point de pivot) du miroir
     * @param len la longueur du miroir
     * @param x le décalage du pivot par rapport au bord gauche
     *          du miroir
     * @param a l'angle d'inclinaison du miroir
     */
    Mirror(const Point &, int, int, double);

    /**
     * Instancie un miroir en une position donnée, d'une certaine
     * longueur et orienté d'un certain angle.
     * </p>
     * Ce constructeur permet également aux miroirs de pivoter
     * dans une certaine limite.
     * </p>
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que a = b, le miroir ne peut
     * être déplacé sur l'axe considéré.
     * </p>
     * Si l'intervalle de limite d'inclinaison [a,b] est tel que
     * a < b, le miroir pivote dans le sens horloger, si a = b le
     * miroir ne peut pas pivoter, si a > b, le miroir
     * pivote dans le sens anti-horloger.
     * @param p la position (et le point de pivot) du miroir
     * @param len la longueur du miroir
     * @param x le décalage du pivot par rapport au bord gauche
     *          du miroir
     * @param a l'angle d'inclinaison du miroir
     * @param min l'abscisse et l'ordonnée minimum du miroir.
     * @param max l'abscisse et l'ordonnée maximum du miroir.
     * @param amin l'angle d'inclinaison minimum du miroir.
     * @param amax l'angle d'inclinaison maximum du miroir.
     */
    Mirror(const Point &, int, int, double, Point, Point, double, double);

    /**
     * Retourne la position (et le pivot) du miroir.
     * @return la position (et le pivot) du miroir.
     */
    const Point & getPivot() const;

    /**
     * Retourne la longueur du miroir
     * @return la longueur du miroir
     */
    int getLength() const;

    /**
     * Retourne le décalage du pivot par rapport au bord gauche
     * du miroir.
     * @return le décalage du pivot par rapport au bord gauche
     * du miroir.
     */
    int getXPad() const;

    /**
     * Retourne l'inclinaison du miroir.
     * @return l'inclinaison du miroir.
     */
    double getAngle() const;

    /**
     * Retourne l'inclinaison minimum du miroir.
     * </p>
     * Si l'intervalle de limite d'inclinaison [a,b] est tel que
     * a < b, le miroir pivote dans le sens horloger, si a = b
     * le miroir ne peut pas pivoter, si a > b, le miroir pivote
     * dans le sens anti-horloger. Si a = b = 0, le miroir peut
     * être pivoté librement.
     * @return l'inclinaison minimum du miroir.
     */
    double getMinAngle() const;

    /**
     * Retourne l'inclinaison maximum du miroir.
     * </p>
     * Si l'intervalle de limite d'inclinaison [a,b] est tel
     * que a < b, le miroir pivote dans le sens horloger, si
     * a = b le miroir ne peut pas pivoter, si a > b, le miroir
     * pivote dans le sens anti-horloger. Si a = b = 0, le miroir
     * peut être pivoté librement.
     * @return l'inclinaison minimum du miroir.
     */
    double getMaxAngle() const;

    /**
     * Retourne la position minimum du miroir.
     * </p>
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que a = b, le miroir ne peut
     * être déplacé sur l'axe considéré. Si a = b = 0, le miroir
     * peut être déplacé librement.
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
     * Déplace le miroir en la position donnée, si c'est
     * autorisé. Retourne vrai si le déplacement a été
     * effectué correctement, retourne faux sinon.
     * @return vrai si le déplacement a été effectué
     * correctement, retourne faux sinon.
     * @see Mirror::getPivot()
     */
    bool setPivot(const Point &);

    /**
     * Pivote le miroir sur un angle donné, si c'est
     * autorisé. Retourne vrai si la rotation a été effectuée
     * correctement, retourne faux sinon.
     * @return vrai si la rotation a été effectuée
     * correctement, retourne faux sinon.
     * @see Mirror::getAngle()
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
     * Angle réflechis = 180 - (â + (360 - ê))
     * 					= 180 - (â + 360 - ê)
     * 					= 180 - â - 360 + ê
     * 					= - 180 + ê - â
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
};

std::ostream & operator<<(std::ostream &, const Mirror &);

#endif // MIRROR_H
