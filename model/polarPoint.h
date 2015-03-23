#ifndef POLARCOORDINATE_HPP
#define POLARCOORDINATE_HPP
#include<model/point.h>
#include<ostream>
#include<string>

/**
 * @brief The PolarPoint class est une classe modélisant la représentation
 * polaire d'un point (une position dans R²). Celle-ci est basé sur deux argument :
 * <ul>
 * <li>
 * Radius : la distance du point par rapport à l'origine du plan cartésien.
 * </li>
 * <li>
 * Beta : le segment de cercle exprimé en radian depuis l'axe horizontal et
 * dans un sens anti-horlogé.
 * </li>
 * </ul>
 */
class PolarPoint
{

private :
    /**
     * @brief radius la distance du point par rapport à l'origine du plan cartésien.
     */
    double radius;
    /**
     * @brief beta le segment de cercle exprimé en radian depuis l'axe
     * horizontal et dans un sens anti-horlogé.
     */
    double beta;

public:
    /**
     * @brief PolarPoint Constructeur sans paramètre de point polaire,
     * reçoit un rayon 0 et un béta quelconque.
     */
    PolarPoint();

    /**
     * @brief PolarPoint Construteur avec paramètres, reçoit un rayon et un
     * beta passé en argument.
     */
    PolarPoint(double, double);

    /**
     * @brief PolarPoint Construction d'un point polaire ~ au point cartésien
     * passé en paramètre.
     */
    PolarPoint(Point &);

    /**
     * @brief PolarPoint Constructeur de recopie.
     */
    PolarPoint(PolarPoint &);

    /**
     * @brief ~PolarPoint Destructeur de point polaire.
     */
    ~PolarPoint();

    /**
     * @brief getRadius Permet d'obtenir la distance séparant le point du centre
     * de rotation.
     * @return Le rayon séparant le point polaire de son centre.
     */
    int getRadius() const;

    /**
     * @brief getBeta Permet d'obtenir l'angle de la coordonnée polaire courante.
     * @return L'amplitude courante du point polaire (en degré ? / radian ?)
     */
    double getBeta() const;

    /**
     * @brief toCartesian Transforme la coordonnée polaire courante en un
     * point cartésien caractérisé par une position sur un axe x et y.
     * @return
     */
    Point toCartesian();

    /**
     * @brief rotate Cette méthode change la position du point courant dans le
     * plan par rotation autour du centre (0,0).
     * @return Le point courant après rotation.
     */
    PolarPoint & rotate(double);

    /**
     * @brief toString Chaine de caractères représentant la coordonnée polaire
     * courante.
     * @return Une chaine formatée représentant l'objet courant.
     */
    std::string toString() const;

    //friend std::ostream & operator<<(std::ostream &, PolarPoint &);
};

#endif // POLARCOORDINATE_HPP
