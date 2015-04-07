#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include "model/point.hpp"

/**
 * Modélise la source lumineuse utilisée dans le jeu.
 * La source est un objet carré qui, si allumée, emet un rayon
 * lumineux de longueur d'onde donnée dont l'angle ne peut pas
 * être changé.
 * Le rayon lumineux est émis depuis la position, i.e., le coin
 * supérieur gauche, de la source.
 */
class Source
{
    /**
     * Etat d'émission de la source.
     */
    bool on {false};

    /**
     * La position cartésienne du coin supérieur gauche de la source.
     */
    Point position;

    /**
     * La longueur du coté du carré représentant la source.
     */
    int edge;

    /**
     * L'angle, en radian, d'émission de la source lumineuse.
     */
    double alpha;

    /**
     * La longueur d'onde du rayon tiré par la source.
     */
    int waveLength;


public:

    /**
     * Instancie une nouvelle source de position, côté et longueur d'onde donnée.
     * La position dénote la coordonnée du coin supérieur gauche du carré
     * modélisant la source. La source est intialement éteinte. Si la longueur
     * d'onde du rayon lumineux émis n'est pas comprise entre 360 nm et 830 nm,
     * elle est réglée sur 600 nm.
     * @param position La position du coin supérieur gauche de la source.
     * @param edge La longueur du côté du carré modélisant la source.
     * @param waveLength La longueur d'onde du rayon lumineux émis.
     *
     * @see Ray::WL_MIN
     * @see Ray::WL_MAX
     * @see Ray::WL_DFT
     */
    Source(const Point &, const int, const double, const int);

    /**
     * Retourne la coordonnée du coin supérieur gauche du carré modélisant la
     * destination.
     *
     * @return La coordonnée du coin supérieur gauche du carré modélisant la source.
     */
    const Point & getPosition() const;

    /**
     * Retourne l'angle du rayon émis.
     *
     * @return l'angle du rayon émis.
     */
    double getAngle() const;

    /**
     * Retourne la longueur du côté du carré.
     *
     * @return la longueur du côté du carré.
     */
    int getEdge() const;

    /**
     * Retourne la longueur d'onde du rayon émis.
     *
     * @return la longueur d'onde du rayon émis.
     */
    int getWaveLength() const;

    /**
     * Permet de savoir l'état d'émission de la source.
     *
     * @return <code>true</code> Si la source émet un rayon lumineux.
     */
    bool isOn() const;

    /**
     * Allume ou éteint la source.
     *
     * @param on Le nouvel état de la source.
     */
    void setOn(const bool);

    /**
     * Permet de savoir si deux sources sont les mêmes.
     *
     * @return <code>true</code> Si deux sources sont les mêmes.
     */
    bool operator==(const Source &) const;

    /**
     * Permet de savoir si deux sources sont différentes.
     *
     * @return <code>true</code> Si deux sources sont différentes.
     */
    bool operator!=(const Source &) const;
};

/**
 * Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * @return Le ostream rempli de la chaine formatée représentant la Source en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Source &);

#endif // SOURCE_H
