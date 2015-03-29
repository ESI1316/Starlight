#ifndef RAY_H
#define RAY_H

#include <iostream>
#include "model/point.hpp"
#include "model/polarPoint.hpp"

/**
 * Cette classe modélise les rayons lumineux, concept central du jeu.
 * </p>
 * Un rayon lumineux est un segment de droite muni d'une longueur
 * d'onde.
 */
class Ray
{
    Point start;
    Point end;
    int waveLength;
    double slope{0.};
    double indTerm{0.};

  public:

    /**
     * Longueur d'onde minimum autorisée pour un rayon lumineux. Cette
     * valeur correspond à la longueur d'onde minimum (en nm) du
     * spectre visible de la lumière.
     */
    static const int WL_MIN {360};

    /**
     * Longueur d'onde maximum autorisée pour un rayon lumineux. Cette
     * valeur correspond à la longueur d'onde maximum (en nm) du
     * spectre visible de la lumière.
     */
    static const int WL_MAX {830};

    /**
     * Longueur d'onde par défaut pour un rayon lumineux. Cette
     * valeur correspond à la longueur d'onde (en nm) de la couleur
     * orangé-rouge du spectre visible de la lumière.
     */
    static const int WL_DFT {600};

    Ray(const PolarPoint, double, int);
    Ray(const Point, double, int);

    /**
     * Retourne le début du rayon.
     * @return le début du rayon.
     */
    const Point & getStart() const;

    /**
     * Retourne la fin du rayon.
     * @return la fin du rayon.
     */
    const Point & getEnd() const;

    /**
     * Retourne la longueur d'onde du rayon.
     * @return la longueur d'onde du rayon.
     */
    int getWaveLength() const;

    double getSlope() const;
    double getIndTerm() const;
    void setIndTerm(const double);
    /**
     * Change la coordonnée du début du rayon.
     * @param p la nouvelle coordonnée du début du rayon.
     */
    void setStart(const Point &);

    /**
     * Change la coordonnée de la fin du rayon.
     * @param p la nouvelle coordonnée de la fin du rayon.
     */
    void setEnd(const Point &);

    /**
     * Change la longueur d'onde du rayon. Si la longueur d'onde
     * spécifiée est en dehors des limites autorisées, laisse la
     * longueur d'onde inchangée.
     * </p> La longueur d'onde doit être comprise entre 360 et 830 nm.
     * @param f la nouvelle longueur d'onde du rayon
     * @return vrai si la longueur d'onde a bel et bien été changée,
     * retourne faux sinon.
     */
    bool setWaveLength(const int);

    /**
     * Permet de savoir si deux rayons sont les mêmes.
     *
     * @return <code>true</code> Si deux rayons sont les même.
     */
    bool operator==(const Ray &) const;

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher un
     * récapitulatif des caractéristiques du rayon sous-jacent en
     * console.
     * @return le flux dans lequel le rayon a été imprimé.
     */
    friend std::ostream & operator<<(std::ostream &, const Ray &);
};

#endif // RAY_H
