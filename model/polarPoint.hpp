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
     * @brief PolarPoint Constructeur sans paramètre de point polaire,
     * reçoit un rayon 0 et un béta quelconque.
     */
    PolarPoint() = default;

    /**
     * @brief PolarPoint Construteur avec paramètres, reçoit un rayon et un
     * azimut passé en argument.
     */
    PolarPoint(const double, const double);

    /**
    * Construit un point polaire à l'aide d'un point cartésien.
    * Azimut sera toujours dans l'interval [0 et 360[ [0 et 2\pi[ pour permettre de
    * représenter un point d'une seule manière possible.
    * @see <a href="http://fr.wikipedia.org/wiki/Coordonn%C3%A9es_polaires">
    * wikipedia - Coordonnées polaires </a>
    */
    PolarPoint(const Point &);

    /**
     * @brief PolarPoint Constructeur de recopie.
     */
    PolarPoint(const PolarPoint &);

    /**
     * @brief ~PolarPoint Destructeur de point polaire.
     */
    ~PolarPoint();

    /**
     * @brief isCenter
     * @return
     */
    bool isCenter() const;

    /**
     * @brief getRadius Permet d'obtenir la distance séparant le point du centre
     * de rotation.
     * @return Le rayon séparant le point polaire de son centre.
     */
    double getRadius() const;

    /**
     * @brief getBeta Permet d'obtenir l'angle de la coordonnée polaire courante.
     * @return L'amplitude courante du point polaire en radian.
     */
    double getAzimut() const;

    /**
     * @brief getAzimutAsDegrees Permet d'obtenir l'angle de la coordonnée
     * polaire courante exprimée en degrés.
     * @return
     */
    double getAzimutAsDegrees() const;
    /**
     * @brief toCartesian Transforme la coordonnée polaire courante en un
     * point cartésien caractérisé par une position sur un axe x et y.
     * @return
     */
    Point toCartesian() const;

    /**
     * @brief rotate Cette méthode change la position du point courant dans le
     * plan par rotation autour du centre (0,0).
     * @return Le point courant après rotation.
     */
    PolarPoint & rotateAround(const PolarPoint &, const double);
    PolarPoint & rotateAround(const Point &, const double);

    void rotate(const double);

    /**
     * @brief toString Chaine de caractères représentant la coordonnée polaire
     * courante.
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
};

std::ostream & operator<<(std::ostream &, const PolarPoint &);

#endif // POLARCOORDINATE_HPP
