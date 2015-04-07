#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "model/line.h"
#include "model/point.hpp"

class Rectangle
{
private:

    int width;
    int height;
    Point upLeftCorner;
    Line edges[4];

public:

    /**
     * Permet de connaitre l'existence et d'obtenir le/les points d'intersection
     * entre le rectangle et la droite entrée en paramètre.
     *
     * @param line Droite dont on désire connaitre l'existence et/ou obtenir le
     * point d'intersection avec la droite courante.
     * @param pointInter1 Conteneur du premier point d'intersection avec la
     * droite entrée en paramètre (non utilisé s'il n'y a pas d'intersection).
     * @param pointInter2 Conteneur du deuxième point d'intersection avec la
     * droite entrée en paramètre (non utilisé s'il n'y a pas d'intersection).
     *
     * @return true Si le rectangle possède au moins une intersection avec la
     * droite entrée en paramètre.
     */
    bool getIntersections(const Line &, Point *, Point *) const;

    /**
     * Permet d'obtenir les côtés du rectangle sous forme de droites.
     *
     * @return Les côtés du rectangle sous forme de droites.
     */
    Line * getEdges() const;

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
};

#endif // RECTANGLE_H
