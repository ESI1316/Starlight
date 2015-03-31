#ifndef LENS_H
#define LENS_H

#include <ostream>
//#include "model/point.hpp"
#include "model/element.hpp"

/**
 * Cette classe modélise les lentilles utilisées dans le jeu.
 * </p>
 * Une lentille est un objet rectangulaire qui ne laisse passer
 * les rayons lumineux que dans un certain intervalle de longueur
 * d'onde. Si un rayon lumineux se trouve dans l'intervalle de
 * longueur d'onde autorisé, il traverse la lentille sans subir
 * aucune modification. Sinon, la lentille se comporte comme un
 * mur.
 */
class Lens : public Element
{
    Point position;

    int width;
    int height;

    int wlMin;
    int wlMax;

  public:

    /**
     * Instancie une lentille à l'aide de toutes ses
     * caractéristiques.
     * @param p la position du coin supérieur gauche du
     *          rectangle modélisant la lentille.
     * @param w la largeur de la lentille
     * @param h la hauteur de la lentille
     * @param wlMin la longueur d'onde minimale des rayons
     *              autorisés à franchir la lentille
     * @param wlMax la longueur d'onde maximale des rayons
     *              autorisés à franchir la lentille
     */
    Lens(const Point &, const int, const int, const int, const int);

    /**
     * Retourne la position du coin supérieur gauche du
     * rectangle modélisant la lentille.
     * @return la position du coin supérieur gauche du
     * rectangle modélisant la lentille.
     */
    const Point & getPosition() const;

    /**
     * Retourne la largeur de la lentille
     * @return la largeur de la lentille
     */
    int getWidth() const;

    /**
     * Retourne la hauteur de la lentille
     * @return la hauteur de la lentille
     */
    int getHeight() const;

    /**
     * Retourne la longueur d'onde minimale des rayons
     * autorisés à franchir la lentille
     * @return la longueur d'onde minimale des rayons
     * autorisés à franchir la lentille
     */
    int getMinWaveLength() const;

    /**
     * Retourne la longueur d'onde maximale des rayons
     * autorisés à franchir la lentille
     * @return la longueur d'onde maximale des rayons
     * autorisés à franchir la lentille
     */
    int getMaxWaveLength() const;

    /**
     * Réaction à l'exposition d'un rayon.
     *
     * @param ray Le rayon.
     */
    void reactToRay(Ray &);

    /**
     * Renseigne si la lentille est dans la trajectoire du rayon.
     *
     * @param ray Le rayon.
     *
     * @return true Si la lentille se trouve dans la trajectoire du rayon entré
     * en paramètre.
     */
    Point * includeRay(const Ray &) const;

    /**
     * Permet de savoir si deux lentilles sont les mêmes.
     *
     * @return <code>true</code> Si les deux lentilles sont les même.
     */
    bool operator==(const Lens &) const;
};

#endif // LENS_H
