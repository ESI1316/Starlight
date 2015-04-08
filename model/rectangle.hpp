#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vector>
#include <ostream>

#include "model/line.hpp"
#include "model/point.hpp"

class Rectangle
{
private:

    int width;
    int height;
    Point upLeftCorner;
    std::vector<Line> edges;

public:

    /**
     * Permet de construire un nouveau rectangle initialisé.
     *
     * @param width Largeur du rectangle.
     * @param height Hauteur du rectangle.
     * @param upLeftCorner Côté supérieur gauche du rectangle.
     */
    Rectangle(int width, int height, const Point & upLeftCorner);

    /**
     * Permet d'obtenir les points d'intersection entre le rectangle et la
     * droite entrée en paramètre.
     *
     * @param line Droite dont on désire obtenir le point d'intersection avec
     * la droite courante.
     *
     * @return Un vecteur contenant les points d'intersection entre la droite
     * entrée en paramètre et le rectangle.
     */
    std::vector<Point> getIntersectionPoints(const Line &) const;

    /**
     * Renseigne si un point se trouve sur la bordure du rectangle.
     *
     * @param point Point dont on désire savoir s'il est inclus sur la bordure
     * du rectangle.
     *
     * @return true Si le Point entré en paramètre est inclus sur la bordure du
     * rectangle.
     */
    bool isOnBorder(const Point &) const;

    /**
     * Permet d'obtenir les côtés du rectangle sous forme de droites.
     *
     * @return Les côtés du rectangle sous forme de droites.
     */
    std::vector<Line> getEdges() const;

    /**
     * Permet d'obtenir la longueur du rectangle.
     *
     * @return La longueur du rectangle.
     */
    int getWidth() const;

    /**
     * Permet d'obtenir la hauteur du rectangle.
     *
     * @return La hauteur du rectangle.
     */
    int getHeight() const;

    /**
     * Permet d'obtenir les coordonnées du coté supérieur du rectangle.
     *
     * @return Les coordonnées du coté supérieur du rectangle.
     */
    Point getUpLeftCorner() const;

    /**
     * Permet de savoir si deux rectangles sont identiques.
     *
     * @return <code>true</code> Si les deux rectangles sont identiques.
     */
    bool operator==(const Rectangle &) const;

    /**
     * Permet de savoir si deux rectangles sont différents.
     *
     * @return <code>true</code> Si les deux rectangles sont différents.
     */
    bool operator!=(const Rectangle &) const;
};

std::ostream & operator<<(std::ostream, const Rectangle &);
#endif // RECTANGLE_H
