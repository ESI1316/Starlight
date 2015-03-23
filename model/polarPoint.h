#ifndef POLARCOORDINATE_HPP
#define POLARCOORDINATE_HPP
#include<model/point.h>
#include<ostream>
#include<string>

/**
 * @brief The PolarPoint class est une classe modélisant la représentation polaire d'un point
 * (une position dans R²). Celle-ci est basé sur deux argument :
 * <ul>
 * <li>Radius : la distance du point par rapport à l'origine du plan cartésien.</li>
 * <li>Beta : le segment de cercle exprimé en radian depuis l'axe horizontal et dans un sens anti-horlogé.</li>
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
     * @brief beta le segment de cercle exprimé en radian depuis l'axe horizontal et dans un sens anti-horlogé.
     */
    double beta;

public:
    /**
     * @brief PolarPoint Constructeur sans paramètre de point polaire, reçoit un rayon 0 et un béta quelconque.
     */
    PolarPoint();
    /**
     * @brief PolarPoint Construteur avec paramètres, reçoit un rayon et un beta passé en argument.
     * @param radius Rayon devant être positif.
     * @param beta Angle exprimé en radian.
     */
    PolarPoint(double, double);
    /**
     * @brief PolarPoint
     */
    PolarPoint(Point &);
    /**
     * @brief PolarPoint
     */
    PolarPoint(PolarPoint &);

    /**
     * @brief ~PolarPoint Destructeur de point polaire.
     */
    ~PolarPoint();

    int getRadius() const;
    double getBeta() const;
    Point toCartesian();
    PolarPoint & rotate(double);
    std::string toString() const;

    //friend std::ostream & operator<<(std::ostream &, PolarPoint &);
};

#endif // POLARCOORDINATE_HPP
