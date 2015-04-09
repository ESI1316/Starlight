#ifndef UTILITIES
#define UTILITIES


class Point;

/**
 * Diverse fonctions utilitaires de géometrie.
 */
namespace utilities
{

    /**
     * @brief PI Représentation de la constante PI sur 26 décimales.
     */
    const double PI{3.14159265358979323846};

    /**
     * @brief PI_2 Représentation de la constante PI/2 sur 26 décimales.
     */
    const double PI_2{1.57079632679489661923};

    /**
     * @brief PI_4 Représentation de la constante PI/4 sur 26 décimales.
     */
    const double PI_4{0.785398163397448309616};

    /**
     * @brief ONE_PI Représentation de la constante 1/PI sur 26 décimales.
     */
    const double ONE_PI{0.318309886183790671538};

    /**
     * @brief TWO_PI Représentation de la constante 2/PI sur 26 décimales.
     */
    const double TWO_PI{0.636619772367581343076};

    /**
     * @brief EPSILON Représentation de la marge d'erreur maximale acceptée.
     */
    const double EPSILON{10E-7};

    /**
     * Permet de trouver les racines (si elles existe) d'une fonction du
     * deuxième degré de forme \f$ax² + bx + c\f$
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
     * <li>\f$\alpha < 0\f$</li>
     * <li>\f$\alpha \geq 2\pi\f$</li>
     * <li>\f$0 \leq \alpha < 2\pi\f$</li>
     * </ul>
     *
     * @param alpha Un angle en radian.
     *
     * @return L'angle exprimé en degré dans l'interval \f$[0, 360°[\f$
     */
    double angleAsDegree0to360(const double);

    /**
     * Cette méthode permet de savoir si deux double sont égaux avec une
     * marge d'erreur Epsilon passée en paramètre ou imposée par défaut à
     * \f$ \epsilon = 10^{-7}\f$.
     *
     * @param nb1 Un réel.
     * @param nb2 Un réel.
     * @param epsilon Niveau de précision souhaitée permettant de justifier
     * l'égalité ou \f$ \epsilon = 10^{-7}\f$ par défault.
     *
     * @return <code>true</code> Si les deux nombres sont égaux avec la précision
     * souhaitée.
     */
    bool equals(const double, const double, const double = utilities::EPSILON);

    /**
     * @brief slopeFromPoints
     * @return
     */
    double slopeFromPoints(const Point &, const Point &);

    bool isHalfPiPlusNPi(const double);
}
#endif // UTILITIES
