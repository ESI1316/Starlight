#ifndef LINE_H
#define LINE_H

#include <cmath>

#include "model/utilities.hpp"
#include "model/point.hpp"


/**
 * Représente une droite sous la forme de son équation complète;
 * \f$ eq \equiv y = slope \cdot x + indepTerm \f$.
 */
class Line
{

protected:

    /**
     * @brief slope Valeur du coefficiant angulaire de la droite.
     */
    double slope;

    /**
     * @brief indepTerm Contient la valeur du terme indépendant de la droite.
     */
    double indepTerm;

    /**
     * @brief xValue Contient la valeur de x lorsque la droite est verticale.
     */
    double xValue;

public:

    /**
     * Permet de construire une nouvelle droite initialisée.
     *
     * @param slope Pente de la droite.
     * @param indepTerm Terme indépendant de la droite.
     * @param xValue Valeur de x si la droite est verticale.
     */
    Line(double, double, double = 0);

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
     * Permet de connaitre la valeur de x, cette valeur est incohérence si
     * la droite n'est pas verticale.
     *
     * @return La valeur de x si la droite est verticale.
     */
    double getXValue() const;

    /**
     * Renseigne si la droite est verticale.
     *
     * @return true Si la droite est verticale.
     */
    bool isVertical() const;

    double findX(const double) const;
    double findY(const double) const;

    /**
     * Permet de savoir si deux lignes sont identiques.
     *
     * @return <code>true</code> Si deux lignes sont identiques.
     */
    bool operator==(const Line &) const;

    /**
     * Permet de savoir si deux lignes sont différentes.
     *
     * @return <code>true</code> Si deux lignes sont différentes.
     */
    bool operator!=(const Line &) const;
};

/**
 * Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * @return Le ostream rempli de la chaine formatée représentant la Ligne en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Line &);

#endif // LINE_H
