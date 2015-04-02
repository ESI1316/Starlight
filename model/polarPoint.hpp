#ifndef POLARCOORDINATE_HPP
#define POLARCOORDINATE_HPP

#include<ostream>
#include<string>
#include "model/point.hpp"

/**
 * @brief The PolarPoint class est une classe modélisant la représentation
 * polaire d'un point (une position dans R²). Celle-ci est basé sur deux argument :
 * <ul>
 * <li>
 * radius : la distance du point par rapport à l'origine du plan cartésien.
 * </li>
 * <li>
 * azimut : exprime la mesure, dans le sens trigonométrique, de l’angle entre le point
 * et la demi-droite d’angle 0°, appelé axe polaire (équivalent à l’axe des
 * abscisses en coordonnées cartésiennes)
 * </li>
 * </ul>
 */
class PolarPoint
{

public :

    static const PolarPoint CARTESIAN_PLAN_ORIGIN;

private :

    /**
     * @brief radius la distance du point par rapport à l'origine du plan
     * cartésien.
     */
    double radius{0.};
    /**
     * @brief azimut le segment de cercle exprimé en radian depuis l'axe
     * horizontal et dans un sens anti-horlogé.
     */
    double azimut{0.};

public:

    /**
     * Constructeur sans paramètre de point polaire, reçoit un rayon 0
     * et un béta quelconque, soit le l'origin du plan cartesien.
     */
    PolarPoint() = default;

    /**
    * Créé un point polaire selon les arguments passés en paramètre.
    * "Il est commode d'autoriser des valeurs négatives de $ r$, étant entendu que
    * les coodonnées polaires $ (r,\theta)$ et $ (-r, \pi+\theta)$ représentent
    * alors le même point. Les formules ci-dessus sont encore applicables. "
    *
    * @param radius Le rayon séparant le centre du point voulu. Doit être positif.
    * @param azimut La longueur du segment de cercle depuis l'axe horizontal.
    *
    */
    PolarPoint(const double, const double);

    /**
    * Construit un point polaire à l'aide d'un point cartésien.
    * Azimut sera toujours dans l'interval [0 et 360[ [0 et 2\pi[ pour permettre de
    * représenter un point d'une seule manière possible.
    *
    * @param point Un point au format cartésien.
    *
    * @see <a href="http://fr.wikipedia.org/wiki/Coordonn%C3%A9es_polaires">
    * wikipedia - Coordonnées polaires </a>
    */
    PolarPoint(const Point &);

    /**
    * Copie un point polaire.
    *
    * @param polarPoint Un autre point au format polaire.
    */
    PolarPoint(const PolarPoint &);

    /**
     * Destructeur de point polaire.
     */
    ~PolarPoint();

    /**
     * Permet de savoir si le point courant est l'origine du plan cartésien.
     *
     * @return <code>true</code> Si le point courant est l'origine du plan
     * cartésien.
     */
    bool isCenter() const;

    /**
     * Permet d'obtenir la distance séparant le point du centre de rotation.
     *
     * @return Le rayon séparant le point polaire de son centre.
     */
    double getRadius() const;

    /**
     * Permet d'obtenir l'angle de la coordonnée polaire courante.
     *
     * @return L'amplitude du point polaire courant en radian.
     */
    double getAzimut() const;

    /**
     * Permet d'obtenir l'angle de la coordonnée polaire courante exprimée en degrés.
     *
     * @return L'amplitude du point polaire courant en degré.
     */
    double getAzimutAsDegrees() const;

    /**
     * Transforme le point courant, au format polaire, en un point au format
     * cartésien caractérisé par une position sur un axe x et y.
     *
     * @return Le point cartésien semblable au point polaire courant.
     */
    Point toCartesian() const;

    /**
     * Cette méthode change la position du point courant dans le plan par
     * rotation autour du point polaire passé en paramètre.
     *
     * @param pivot Le centre autour duquel le point courant doit tourner.
     * @param alpha L'amplitude de la rotation à effectuer (en radian).
     *
     * @return Le point courant après rotation.
     */
    PolarPoint & rotateAround(const PolarPoint &, const double);

    /**
     * Cette méthode change la position du point courant dans le plan par
     * rotation autour du point cartésien passé en paramètre.
     *
     * @param pivot Le centre autour duquel le point courant doit tourner.
     * @param alpha L'amplitude de la rotation à effectuer (en radian).
     *
     * @return Le point courant après rotation.
     */
    PolarPoint & rotateAround(const Point &, const double);

    /**
     * Effectue une rotation autour de l'origine du plan cartésien.
     *
     * @param alpha L'amplitude de la rotation à effectuer (en radian).
     */
    void rotate(const double);

    /**
     * Chaine de caractères représentant la coordonnée polaire courante.
     *
     * @return Une chaine formatée représentant l'objet courant.
     */
    std::string toString() const;

    /**
     * Operateur de copie d'un point polaire.
     *
     * @return Le point polaire courant.
     */
    PolarPoint & operator=(const PolarPoint &);

    /**
     * Operateur de copie d'un point cartésien en un point polaire.
     *
     * @return Le point polaire courant.
     */
    PolarPoint & operator=(const Point &);

    /**
     * Permet de savoir si deux points sont à la même position.
     *
     * @return <code>true</code> Si les deux points sont au même endroit sur le
     * plan.
     */
    bool operator==(const PolarPoint &) const;

    /**
     * Permet de savoir si deux points ne sont pas à la même position.
     *
     * @return <code>true</code> Si les deux points ne sont pas au même endroit sur le
     * plan.
     */
    bool operator!=(const PolarPoint &) const;
};

/**
 * Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * @return Le ostream rempli de la chaine formatée représentant le PolarPoint en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const PolarPoint &);

#endif // POLARCOORDINATE_HPP
