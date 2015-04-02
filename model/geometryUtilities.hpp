#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif
#ifndef M_PI_4
#define M_PI_4 0.785398163397448309616
#endif
#ifndef M_1_PI
#define M_1_PI 0.318309886183790671538
#endif
#ifndef M_2_PI
#define M_2_PI 0.636619772367581343076
#endif
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

    /**
     * Permet de trouver l'angle en degré d'un angle en radian.
     * @param alpha Un angle en radian.
     * @return L'angle exprimé en degré.
     */
    double angleAsDegree(double);

    /**
     * Permet de trouver l'angle en degré, entre 0 et 360, d'un angle en radian.
     * @param alpha Un angle en radian.
     * @return L'angle exprimé en degré dans l'interval [0, 360°[
     */
    double angleAsDegree0to360(double);
}
#endif // GEOMETRYUTILITIES
