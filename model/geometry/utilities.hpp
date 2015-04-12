#ifndef UTILITIES_HPP
#define UTILITIES_HPP


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

    /*!
     * \brief Cette méthode permet de vérifier l'inégalité \f$ nb_1 \geq nb_2 \f$ sur
     * deux nombres réels avec une marge d'erreur Epsilon passée en paramètre
     * ou imposée par défaut à \f$ \epsilon = 10^{-7}\f$.
     *
     * \param nb1 Un nombre rééls.
     * \param nb2 Un nombre rééls.
     *
     * \return <code>true</code> Si l'inégalité \f$ nb_1 \geq nb_2 \f$ est vérifiée.
     */
    bool greaterOrEquals(const double, const double, const double = utilities::EPSILON);

    /*!
     * \brief Cette méthode permet de vérifier l'inégalité \f$ nb_1 \leq nb_2 \f$ sur
     * deux nombres réels avec une marge d'erreur Epsilon passée en paramètre
     * ou imposée par défaut à \f$ \epsilon = 10^{-7}\f$.
     *
     * \param nb1 Un nombre rééls.
     * \param nb2 Un nombre rééls.
     *
     * \return <code>true</code> Si l'inégalité \f$ nb_1 \geq nb_2 \f$ est vérifiée.
     */
    bool lessOrEquals(const double, const double, const double = utilities::EPSILON);

    /*!
     * \brief Permet de trouver la pente d'une droite formée par deux points.
     *
     * \param p1 Un point.
     * \param p2 Un point.
     *
     * \return La pente de l'équation de droite passant par ces deux points.
     */
    double slopeFromPoints(const Point &, const Point &);

    /*!
     * \brief Permet de savoir si l'angle, en radian, vaut
     * \f$ \frac{\pi}{2} + n \cdot (2 \cdot \pi)\f$
     *
     * \return <code>true</code> Si \f$ angle = \frac{\pi}{2} + n \cdot (2 \cdot \pi) \f$
     */
    bool isHalfPiPlusNPi(const double);

    /*!
     * \brief Permet d'avoir la valeur trigonométrique tangante d'un angle
     * ou l'infini si \f$ angle = \frac{\pi}{2} + n \cdot 2 \cdot \pi \f$.
     *
     * \return La tangante de l'angle ou l'infini.
     *
     */
    double tan(const double);

    /*!
     * \brief Permet d'avoir l'angle "absolu" de celui passé en paramètre,
     * [0, PI_2].
     *
     * \return L'angle absolu de celui passé en paramètre.
     */
    double absoluteAngle(const double);

    /**
     * @brief Permet de recadrer un angle dans un interval [0 ; 2PI[.
     *
     * @return L'angle passé en paramètre dans l'interval [0 ; 2PI[
     */
    double inZeroTwoPi(const double);
}
#endif // UTILITIES_HPP
