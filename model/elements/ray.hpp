#ifndef RAY_HPP
#define RAY_HPP

#include <ostream>

#include "model/geometry/point.hpp"
#include "model/geometry/line.hpp"


/*!
 * \brief Cette classe modélise les rayons lumineux, concept central du jeu.
 * Un rayon lumineux est un segment de droite muni d'une longueur
 * d'onde.
 */
class Ray : public Line
{

protected:

    Point start;
    Point end;
    int waveLength{Ray::WL_DFT};
    double alpha;

  public:

    /*!
     * \brief Longueur d'onde minimum autorisée pour un rayon lumineux. Cette
     * valeur correspond à la longueur d'onde minimum (en nm) du
     * spectre visible de la lumière.
     */
    static const int WL_MIN{360};

    /*!
     * \brief Longueur d'onde maximum autorisée pour un rayon lumineux. Cette
     * valeur correspond à la longueur d'onde maximum (en nm) du
     * spectre visible de la lumière.
     */
    static const int WL_MAX{830};

    /*!
     * \brief Longueur d'onde par défaut pour un rayon lumineux. Cette
     * valeur correspond à la longueur d'onde (en nm) de la couleur
     * orangé-rouge du spectre visible de la lumière.
     */
    static const int WL_DFT{600};

    /*!
     * \brief Créer un nouveau rayon.
     */
    Ray(const Point, double, int);

    /*!
     * \brief Retourne le début du rayon.
     * \return le début du rayon.
     */
    const Point & getStart() const;

    /*!
     * \brief Retourne la fin du rayon.
     * \return la fin du rayon.
     */
    const Point & getEnd() const;

    /*!
     * \brief Retourne la longueur d'onde du rayon.
     * \return la longueur d'onde du rayon.
     */
    int getWaveLength() const;

    double getAlpha() const;
    /*!
     * \brief Change la coordonnée du début du rayon.
     *
     * \param start La nouvelle coordonnée du début du rayon.
     */
    void setStart(const Point &);

    /*!
     * C\brief hange la coordonnée de la fin du rayon.
     *
     * \param end La nouvelle coordonnée de la fin du rayon.
     */
    void setEnd(const Point &);

    /*!
     * C\brief hange la longueur d'onde du rayon. Si la longueur d'onde
     * spécifiée est en dehors des limites autorisées, la longueur d'onde
     * vaudra la borne la plus proche.
     * La longueur d'onde doit être comprise entre 360 et 830 nm.
     *
     * \param waveLength La nouvelle longueur d'onde du rayon
     *
     */
    void setWaveLength(const int);

    /*!
     * \brief isInTrajectory
     * \return
     */
    bool isInTrajectory(const Point &) const;

    /*!
     * \brief Permet de savoir si deux rayons sont les mêmes.
     *
     * \return <code>true</code> Si deux rayons sont les même.
     */
    bool operator==(const Ray &) const;

    /*!
     * \brief Permet de savoir si deux rayons sont différents.
     *
     * \return <code>true</code> Si deux rayons sont différents.
     */
    bool operator!=(const Ray &) const;
};

/*!
 * \brief Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * \return Le ostream rempli de la chaine formatée représentant le Ray en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Ray &);

inline const Point & Ray::getStart() const
{
    return this->start;
}

inline const Point & Ray::getEnd() const
{
    return this->end;
}

inline int Ray::getWaveLength() const
{
    return this->waveLength;
}

inline double Ray::getAlpha() const
{
    return this->alpha;
}

#endif // RAY_HPP
