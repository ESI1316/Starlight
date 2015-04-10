#ifndef RAY_HPP
#define RAY_HPP

#include <ostream>

#include "model/point.hpp"
#include "model/geometry/line.hpp"


/**
 * Cette classe modélise les rayons lumineux, concept central du jeu.
 * Un rayon lumineux est un segment de droite muni d'une longueur
 * d'onde.
 */
class Ray : public Line
{

protected:

    Point start;
    Point end;
    int waveLength{Ray::WL_DFT};

  public:

    /**
     * Longueur d'onde minimum autorisée pour un rayon lumineux. Cette
     * valeur correspond à la longueur d'onde minimum (en nm) du
     * spectre visible de la lumière.
     */
    static const int WL_MIN{360};

    /**
     * Longueur d'onde maximum autorisée pour un rayon lumineux. Cette
     * valeur correspond à la longueur d'onde maximum (en nm) du
     * spectre visible de la lumière.
     */
    static const int WL_MAX{830};

    /**
     * Longueur d'onde par défaut pour un rayon lumineux. Cette
     * valeur correspond à la longueur d'onde (en nm) de la couleur
     * orangé-rouge du spectre visible de la lumière.
     */
    static const int WL_DFT{600};

    /**
     * Créer un nouveau rayon tel une demi droite possèdant un point,
     * un coefficiant angulaire, une longueur d'onde et un terme indépendant.
     * Ce dernier est calculé à la fin, permettant de d'écrire le rayon au format
     * y = mx + p
     */
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

    /**
     * Change la coordonnée du début du rayon.
     *
     * @param start La nouvelle coordonnée du début du rayon.
     */
    void setStart(const Point &);

    /**
     * Change la coordonnée de la fin du rayon.
     *
     * @param end La nouvelle coordonnée de la fin du rayon.
     */
    void setEnd(const Point &);

    /**
     * Change la longueur d'onde du rayon. Si la longueur d'onde
     * spécifiée est en dehors des limites autorisées, laisse la
     * longueur d'onde inchangée.
     * La longueur d'onde doit être comprise entre 360 et 830 nm.
     *
     * @param waveLength La nouvelle longueur d'onde du rayon
     *
     * @return <code>true</code> Si la longueur d'onde a été changé.
     */
    bool setWaveLength(const int);

    /**
     * Permet de savoir si deux rayons sont les mêmes.
     *
     * @return <code>true</code> Si deux rayons sont les même.
     */
    bool operator==(const Ray &) const;

    /**
     * Permet de savoir si deux rayons sont différents.
     *
     * @return <code>true</code> Si deux rayons sont différents.
     */
    bool operator!=(const Ray &) const;
};

/**
 * Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * @return Le ostream rempli de la chaine formatée représentant le Ray en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Ray &);

#endif // RAY_HPP
