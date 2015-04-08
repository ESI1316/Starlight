#ifndef LENS_H
#define LENS_H

#include <ostream>
#include "model/element.hpp"
#include "model/ellipse.hpp"

/**
 * Cette classe modélise les lentilles utilisées dans le jeu.
 *
 * Une lentille est un objet rectangulaire qui ne laisse passer
 * les rayons lumineux que dans un certain intervalle de longueur
 * d'onde. Si un rayon lumineux se trouve dans l'intervalle de
 * longueur d'onde autorisé, il traverse la lentille sans subir
 * aucune modification. Sinon, la lentille se comporte comme un
 * mur.
 */
class Lens : public Element, public Ellipse
{

private :

    int wlMin;
    int wlMax;

  public:

    /**
     * Créer une nouvelle lentille pouvant être un obstacle à un rayon :
     * si le rayon souhaite passer au travers, il devra être d'une longueur
     * d'onde comprise dans l'interval souhaité par cette lentille. Dans le cas
     * contraire, le rayon ne passera pas.
     *
     * @param position La position du coin supérieur gauche du rectangle
     * circonscrit à l'ellipse modélisant la lentille.
     * @param width La largeur du rectangle circonscrit à la lentille.
     * @param height la hauteur du rectangle circonscrit à la lentille.
     * @param wlMin La longueur d'onde minimale des rayons autorisés à
     * franchir la lentille.
     * @param wlMax La longueur d'onde maximale des rayons autorisés à franchir
     * la lentille.
     */
    Lens(const Point &, const int, const int, const int, const int);

    /**
     * Retourne la position du coin supérieur gauche du rectangle circonscrit
     * à la lentille.
     *
     * @return La coordonnée cartésienne du coin supérieur gauche du rectangle
     * modélisant la lentille.
     */
    const Point & getPosition() const;

    /**
     * Retourne la longueur d'onde minimale des rayons autorisés à franchir la
     * lentille.
     *
     * @return La longueur d'onde minimale des rayons autorisés à franchir
     * la lentille.
     */
    int getMinWaveLength() const;

    /**
     * Retourne la longueur d'onde maximale des rayons
     * autorisés à franchir la lentille
     *
     * @return La longueur d'onde maximale des rayon autorisés à franchir
     * la lentille.
     */
    int getMaxWaveLength() const;

    /**
     * Cette méthode est lancé lorsque la lentille courante est exposée à un rayon.
     * Elle va communiquer au niveau la fin du rayon si il ne peut pas passer
     * ou ne va rien faire si le rayon passe.
     *
     * @param ray Un rayon percutant la lentille.
     */
    void reactToRay(Ray &);

    /**
     * Renseigne si la lentille est dans la trajectoire du rayon.
     *
     * @param ray Le rayon.
     *
     * @return <code>true</code> Si la lentille se trouve dans la trajectoire
     * du rayon entré en paramètre.
     */
    Point * includeRay(const Ray &) const;

    /**
     * Permet de savoir si deux lentilles sont les mêmes.
     *
     * @return <code>true</code> Si les deux lentilles sont les même.
     */
    bool operator==(const Lens &) const;

    /**
     * Permet de savoir si deux lentilles sont différentes.
     *
     * @return <code>true</code> Si les deux lentilles sont différentes.
     */
    bool operator!=(const Lens &) const;
};

/**
 * Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * @return Le ostream rempli de la chaine formatée représentant la Lens en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Lens &);

#endif // LENS_H
