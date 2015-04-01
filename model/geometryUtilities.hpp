#ifndef GEOMETRYUTILITIES
#define GEOMETRYUTILITIES

#include "model/point.hpp"

/**
 * Diverse fonctions utilitaires de géometrie.
 */
namespace geometryUtilities
{
    /**
    * Permet d'obtenir les points d'intersection entre une droite (déterminée
    * par sa pente et le terme indépendant de son équation) et un cercle
    * (déterminé par son son centre (un point) et son rayon).
    *
    * @param slope Pente de la droite.
    * @param indepTerm Terme indépendant de l'équation de la droite.
    * @param circleCenter Centre du cercle.
    * @param radius Rayon du cercle.
    * @param intersec1 Pointeur vers le conteneur du point du premier point d'
    * intersection (non utilisé s'il n'existe pas d' intersection).
    * @param intersec2 Pointeur vers le conteneur du point du deuxième point d'
    * intersection (non utilisé s'il n'existe pas d' intersection).
    *
    * @return true s'il existe une intersection.
    */
    bool intersecPointsLineCircle(const double, const int, const Point &,
                                  const int, Point *, Point *);
    /**
     * Permet de trouver les racines (si elles existe) d'une fonction du
     * deuxième degré de forme ax² + bx + c.
     *
     * @param a Paramètre de x².
     * @param b Paramètre de x.
     * @param c Terme indépendant.
     * @param rad1 Pointeur vers le conteneur de la valeur de la racine obtenue
     * avec delta positif (non utilisé s'il n'existe pas de racines).
     * @param rad2 Pointeur vers le conteneur de la valeur de la racine obtenue
     * avec delta négatif (non utilisé s'il n'existe pas de racines).
     *
     * @return true S'il existe des racines.
     */
    bool secondDegreeEquationSolver(double, double, double, double *, double *);
}
#endif // GEOMETRYUTILITIES
