#ifndef UTILITIES
#define UTILITIES

#include "model/point.hpp"

/**
 * Diverse fonctions utilitaires de géometrie.
 */
namespace utilities
{

    const double _M_PI{3.14159265358979323846};
    const double _M_PI_2{1.57079632679489661923};
    const double _M_PI_4{0.785398163397448309616};
    const double _M_1_PI{0.318309886183790671538};
    const double _M_2_PI{0.636619772367581343076};
    const double _EPSILON{10E-7};

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
    double angleAsDegree(const double);

    /**
     * Permet de trouver l'angle en degré, entre 0 et 360, d'un angle en radian.
     * Le calcul permet d'encadrer les cas où
     * <ul>
     * <li>alpha < 0</li>
     * <li>alpha >= 2\pi</li>
     * <li>0 <= alpha < 2\pi</li>
     * </ul>
     *
     * @param alpha Un angle en radian.
     *
     * @return L'angle exprimé en degré dans l'interval [0, 360°[
     */
    double angleAsDegree0to360(const double);

    /**
     * Cette méthode permet de savoir si deux double sont égaux avec une
     * marge d'erreur Epsilon passée en paramètre.
     *
     * @param nb1 Un réel.
     * @param nb2 Un réel.
     * @param epsilon Niveau de précision souhaitée permettant de justifier
     * l'égalité.
     *
     * @return <code>true</code> Si les deux nombres sont égaux avec la précision
     * souhaitée.
     */
    bool equals(const double, const double, const double);

    /**
     * Cette méthode permet de savoir si deux double sont égaux avec une
     * marge d'erreur Epsilon imposée à $10^{-7}$
     *
     * @param nb1 Un réel.
     * @param nb2 Un réel.
     * @param epsilon Niveau de précision souhaitée permettant de justifier
     * l'égalité.
     *
     * @return <code>true</code> Si les deux nombres sont égaux avec la précision
     * $10^{-7}$
     */
    bool equals(const double, const double);
}
#endif // UTILITIES
