#ifndef LINE_H
#define LINE_H

#include

/**
 * Représente une droite sous la forme de son équation complète;
 * ay + bx + c = 0.
 */
class Line
{
private:

    int yParam;
    int xParam;
    int indepTerm;

public:

    /**
     * Permet de connaitre l'existence et d'obtenir le point d'intersection
     * entre la droite et celle entrée en paramètre.
     *
     * @param line Droite dont on désire connaitre l'existence et/ou obtenir le
     * point d'intersection avec la droite courante.
     * @param pointInter Conteneur du point d'intersection avec la droite entrée
     * en paramètre (non utilisé s'il n'y a pas d'intersection).
     *
     * @return true Si la droite possède une intersection avec celle entrée en
     * paramètre.
     */
    bool getIntersection(const Line &, Point *) const;

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
     * Permet d'obtenir le paramètre de Y.
     *
     * @return Le paramètre de Y.
     */
    int getYParam() const;

    /**
     * Permet d'obtenir le paramètre de X.
     *
     * @return Le paramètre de X.
     */
    int getXParam() const;

    /**
     * Permet d'obtenir le terme indépendant.
     *
     * @return Le terme indépendant.
     */
    int getIndepTerm() const;
};

#endif // LINE_H
