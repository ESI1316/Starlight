#ifndef LINE_H
#define LINE_H

#include <cmath>

#include "model/utilities.hpp"
#include "model/point.hpp"


/**
 * Représente une droite sous la forme de son équation complète;
 * y = slope * x + indepTerm.
 */
class Line
{
private:

    double indepTerm;
    double slope;

    double xValue; //Contient la valeur de x lorsque la droite est verticale.

public:

    /**
     * Permet de construire une nouvelle droite initialisée.
     *
     * @param slope Pente de la droite.
     * @param indepTerm Terme indépendant de la droite.
     * @param xValue Valeur de x si la droite est verticale.
     */
    Line(double, double, double);

    /**
     * Permet d'obtenir le point d'intersection entre la droite et celle entrée
     * en paramètre.
     *
     * @param line Droite dont on désire obtenir le point d'intersection avec
     * la droite courante.
     *
     * @return Un pointeur vers un le point d'intersection entre la droite et
     * celle entrée en paramètre si il existe, un pointeur nul sinon.
     */
    Point * getIntersectionPoint(const Line &) const;

    /**
     * Renseigne si le point entré en paramètre est inclus dans la droite.
     *
     * @param point Point dont on désire savoir s'il est inclus dans la droite.
     *
     * @return true si le point entré en paramètre est inclus dans la droite.
     */
    bool includes(const Point &) const;

    /**
     * Permet d'obtenir la pente de la droite.
     *
     * @return La pente de la droite.
     */
    double getSlope() const;

    /**
     * Permet d'obtenir le terme indépendant.
     *
     * @return Le terme indépendant.
     */
    double getIndepTerm() const;

    /**
     * Renseigne si la droite est verticale.
     *
     * @return true Si la droite est verticale.
     */
    bool isVertical() const;
};

#endif // LINE_H
