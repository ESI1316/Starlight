#ifndef POINT_HPP
#define POINT_HPP

#include <ostream>

/*!
 * \brief Cette classe modélise un point de coordonnés dans le plan \f$ R^2 \f$ sous
 * deux formes :
 * <ul>
 * <li> coordonnées cartésiennes sous la forme \f$ c(x, y) \f$,</li>
 * <li> coordonnées polaires sous la forme \f$ p(r, \alpha) \f$.</li>
 * </ul>
 * Elle sert à définir la position d'un objet dans l'espace à deux dimensions.
 */
class Point
{

private :
    /*!
     * \brief x La distance, sur l'axe des abscisses, du point par rapport à
     * l'origine.
     */
    double x {0.};

    /*!
     * \brief y La distance, sur l'axe des ordonnées, du point par rapport à
     * l'origine.
     */
    double y {0.};

    /*!
     * \brief radius la distance du point par rapport à l'origine du plan
     * cartésien.
     */
    double radius{0.};

    /*!
     * \brief azimut le segment de cercle exprimé en radian depuis l'axe
     * horizontal et dans un sens anti-horloger.
     */
    double azimut{0.};

public:

    /*!
     * \brief Instancie le point \f$c(0, 0) p(0, 0)\f$
     */
    Point() = default;

    /*!
     * \brief Instancie le point de coordonnées spécifiées.
     * \param x l'abscisse du point
     * \param y l'ordonnée du point
     */
    Point(const double, const double);

    /*!
     * \brief Instancie un point par copie d'un autre point : constructeur de recopie.
     */
    Point(const Point &);

    /*!
     * \brief Retourne l'abscisse du point.
     * \return l'abscisse du point.
     */
    double getX() const;

    /*!
     * \brief Retourne l'ordonnée du point.
     * \return l'ordonnée du point.
     */
    double getY() const;

    /*!
     * \brief Déplace le point en l'abscisse donnée.
     * \param x l'abscisse où déplacer le point.
     */
    void setX(const double);

    /*!
     * \brief Déplace le point en l'ordonnée donnée.
     * \param y l'ordonnée où déplacer le point.
     */
    void setY(const double);

    /*!
     * \brief Permet d'obtenir la distance séparant le point du centre de rotation.
     *
     * \return Le rayon séparant le point polaire de son centre.
     */
    double getRadius() const;

    /*!
     * \brief Permet d'obtenir l'angle de la coordonnée polaire courante.
     *
     * \return L'amplitude du point polaire courant en radian.
     */
    double getAzimut() const;

    /*!
     * \brief Permet d'obtenir l'angle de la coordonnée polaire courante exprimée en degrés.
     *
     * \return L'amplitude du point polaire courant en degré.
     */
    double getAzimutAsDegrees() const;

    /*!
     * \brief Cette méthode change la position du point courant dans le plan par
     * rotation autour du point cartésien passé en paramètre.
     *
     * \param pivot Le centre autour duquel le point courant doit tourner.
     * \param alpha L'amplitude de la rotation à effectuer (en radian).
     *
     * \return Le point courant après rotation.
     */
    Point & rotateAround(const Point &, const double);

    /*!
     * \brief Effectue une rotation autour de l'origine du plan cartésien.
     *
     * \param alpha L'amplitude de la rotation à effectuer (en radian).
     */
    void rotate(const double);

    /*!
     * \brief Considère la position d'un point par rapport à un point quelconque.
     *
     * \param origin La nouvelle origine du plan. Si ce paramètre est omis,
     * l'origine du plan est rétabli.
     */
    void setOrigin(const Point & = Point{0., 0.});

    /*!
     * \brief Modifie le point pour lui donner un position de même angle en lui
     * ajoutant un radius.
     *
     * \param radius Un nouveau radius.
     */
    void extend(const double);

    /*!
     * \brief Déplace le point en la coordonnée cartésienne donnée.
     * \param x l'abscisse où déplacer le point.
     * \param y l'ordonnée où déplacer le point.
     */
    void setCartesianLocation(const double, const double);

    /*!
     * \brief Déplace le point en la coordonnée polaire donnée.
     * \param radius La distance séparant le point de l'origine.
     * \param azimut L'angle, en radian, selon le cercle trigonométrique.
     */
    void setPolarLocation(const double, const double);

    /*!
     * \brief Permet de connaitre la distance séparant le point courant d'un autre.
     * La distance est calculée à l'aide du théorème de Pythagore au triangle
     * rectangle :
     * soient les deux points du plan cartésien reliés formant un segment de
     * droite, en traçant les parallèles aux axes passant par ces points on peut
     * délimiter un triangle rectangle par l'intersection des deux droites.
     * De là, il est simple d'appliquer le théorème de Pythagore aux triangles
     * rectangles :
     * l'hypoténuse au carré = la somme du carré des deux autres cotés
     * \f$ distance(p1, p2)^2 = (p1.x - p2.x)^2 + (p1.y - p2.y)^2 \f$
     * Dans la bibliothèque standard C++, la fonction std::hypot de <cmath>
     * nous permet de faire cette opération en lui passant simplement les cotés
     * autre que l'hypoténuse.
     * \param point Un autre point.
     * \return La distance séparant deux point.
     */
    double distanceFrom(const Point &) const;

    /*!
     * \brief Permet de copier le contenu d'un point dans un autre point.
     *
     * \return Le point courant modifié.
     */
    Point & operator=(const Point &);

    /*!
     * \brief Permet de savoir si deux points sont aux même endroit.
     *
     * \return <code>true</code> Si les deux points ont les même coordonnées.
     */
    bool operator==(const Point &) const;

    /*!
     * \brief Permet de savoir si deux points ne sont pas au même endroit.
     *
     * \return <code>true</code> Si les deux points ne sont pas les mêmes.
     */
    bool operator!=(const Point &) const;
};

/*!
 * \brief Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * \return Le ostream rempli de la chaine formatée représentant le Point en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Point &);

inline double Point::getX() const
{
    return this->x;
}

inline double Point::getY() const
{
    return this->y;
}

inline double Point::getRadius() const
{
    return this->radius;
}

inline double Point::getAzimut() const
{
    return this->azimut;
}

#endif // POINT_HPP
