#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <vector>
#include <ostream>

#include "model/geometry/point.hpp"
#include "model/geometry/line.hpp"

/*!
 * \brief Le rectangle est objet géométrique, du plan, à quatre coté parallèles
 * deux à deux.
 */
class Rectangle
{

protected:

    /*!
     * \brief La largeur du rectangle.
     */
    double width;

    /*!
     * \brief La longueur du rectangle.
     */
    double height;

    /*!
     * \brief La position du coin supérieur gauche du rectangle.
     */
    Point upLeftCorner;

    /*!
     * \brief Les équations des 4 droites composant le rectangle.
     */
    std::vector<Line> edges;

public:

    /*!
     * \brief Permet de construire un nouveau rectangle initialisé.
     *
     * \param width Largeur du rectangle.
     * \param height Hauteur du rectangle.
     * \param upLeftCorner Côté supérieur gauche du rectangle.
     */
    Rectangle(double, double, const Point &);

    /*!
     * \brief Permet d'obtenir les points d'intersection entre le rectangle et la
     * droite entrée en paramètre.
     *
     * \param line Droite dont on désire obtenir le point d'intersection avec
     * la droite courante.
     *
     * \return Un vecteur contenant les points d'intersection entre la droite
     * entrée en paramètre et le rectangle.
     */
    std::vector<Point> getIntersectionPoints(const Line &) const;

    /*!
     * \brief Renseigne si un point se trouve sur la bordure du rectangle.
     *
     * \param point Point dont on désire savoir s'il est inclus sur la bordure
     * du rectangle.
     *
     * \return <code>true</code> Si le Point entré en paramètre est inclus sur la bordure du
     * rectangle.
     */
    bool isOnBorder(const Point &) const;

    /*!
     * \brief Permet d'obtenir les côtés du rectangle sous forme de droites.
     *
     * \return Les côtés du rectangle sous forme de droites.
     */
    std::vector<Line> getEdges() const;

    /*!
     * \brief Permet d'obtenir la longueur du rectangle.
     *
     * \return La longueur du rectangle.
     */
    virtual double getWidth() const;

    /*!
     * \brief Permet d'obtenir la hauteur du rectangle.
     *
     * \return La hauteur du rectangle.
     */
    virtual double getHeight() const;

    /*!
     * \brief Permet d'obtenir les coordonnées du coté supérieur du rectangle.
     *
     * \return Les coordonnées du coté supérieur du rectangle.
     */
    Point getUpLeftCorner() const;

    /*!
     * \brief Permet de savoir si deux rectangles sont identiques.
     *
     * \return <code>true</code> Si les deux rectangles sont identiques.
     */
    bool operator==(const Rectangle &) const;

    /*!
     * \brief Permet de savoir si deux rectangles sont différents.
     *
     * \return <code>true</code> Si les deux rectangles sont différents.
     */
    bool operator!=(const Rectangle &) const;

    /*!
     * \brief Permet de copier un rectangle dans un autre.
     *
     * \return Le rectangle courant modifié.
     */
    Rectangle & operator=(const Rectangle &);
};

/*!
 * \brief Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * \return Le ostream rempli de la chaine formatée représentant le Rectangle en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Rectangle &);

inline std::vector<Line> Rectangle::getEdges() const
{
    return this->edges;
}

inline double Rectangle::getWidth() const
{
    return this->width;
}

inline double Rectangle::getHeight() const
{
    return this->height;
}

inline Point Rectangle::getUpLeftCorner() const
{
    return this->upLeftCorner;
}

#endif // RECTANGLE_HPP
