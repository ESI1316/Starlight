#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include "point.hpp"

/**
 * Modélise la source lumineuse utilisée dans le jeu.
 * </p>
 * La source est un objet carré qui, si allumée, emet un rayon
 * lumineux de longueur d'onde donnée dont l'angle ne peut pas
 * être changé.
 * </p>
 * Le rayon lumineux est émis depuis la position, i.e., le coin
 * supérieur gauche, de la source.
 */
class Source
{
    bool on {false};
    Point position;
    int edge;
    double alpha;
    int waveLength;


public:
    /**
     * Instancie une nouvelle source de position, côté et
     * longueur d'onde donnée.
     * </p>
     * La position dénote la coordonnée du coin supérieur gauche
     * du carré modélisant la source.
     * </p>
     * La source est intialement éteinte.
     * </p> Si la longueur d'onde du rayon lumineux émis n'est
     * pas comprise entre 360 nm et 830 nm, elle est réglée
     * sur 600 nm.
     * @param p la position de la source.
     * @param e la longueur du côté de la source.
     * @param wl la longueur d'onde du rayon lumineux émis.
     * @see Ray::WL_MIN
     * @see Ray::WL_MAX
     * @see Ray::WL_DFT
     */
    Source(const Point &, const int, const double, const int);

    /**
     * Retourne la coordonnée du coin supérieur gauche du carré
     * modélisant la destination.
     * @return la coordonnée du coin supérieur gauche du carré
     * modélisant la source.
     */
    const Point & getPosition() const;

    /**
     * Retourne l'angle du rayon émis.
     * @return l'angle du rayon émis.
     */
    int getAngle() const;

    /**
     * Retourne la longueur du côté du carré.
     * @return la longueur du côté du carré.
     */
    int getEdge() const;

    /**
     * Retourne la longueur d'onde du rayon émis.
     * @return la longueur d'onde du rayon émis.
     */
    int getWaveLength() const;

    /**
     * Retourne vrai si la source émet un rayon lumineux,
     * faux sinon.
     * @return vrai si la source émet un rayon lumineux,
     * faux sinon.
     */
    bool isOn() const;

    /**
     * Allume ou éteint la source.
     * @param q vrai si la source doit être allumée,
     * faux sinon.
     */
    void setOn(const bool);

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher
     * un récapitulatif des caractéristiques de la source
     * sous-jacente en console.
     * @return le flux dans lequel la source a été imprimée.
     */
    //friend std::ostream & operator<<(std::ostream &, const Source &);
};

#endif // SOURCE_H
