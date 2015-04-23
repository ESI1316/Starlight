#ifndef SOURCE_HPP
#define SOURCE_HPP

#include <ostream>

#include "model/geometry/rectangle.hpp"
#include "model/elements/element.hpp"

class Point;

/*!
 * \brief Modélise la source lumineuse utilisée dans le jeu.
 * La source est un objet carré qui, si allumée, émet un rayon
 * lumineux de longueur d'onde donnée dont l'angle ne peut pas
 * être changé.
 * Le rayon lumineux est émis depuis la position, i.e., le coin
 * supérieur gauche, de la source.
 */
class Source : public Element, public Rectangle
{
    /*!
     * \brief État d'émission de la source.
     */
    bool on;

    /*!
     * \brief L'angle, en radian, d'émission de la source lumineuse.
     */
    double alpha;

    /*!
     * \brief La longueur d'onde du rayon tiré par la source.
     */
    int waveLength;

public:

    /*!
     * \brief Instancie une nouvelle source de position, côté et longueur d'onde donnée.
     * La position dénote la coordonnée du coin supérieur gauche du carré
     * modélisant la source. La source est initialement éteinte. Si la longueur
     * d'onde du rayon lumineux émis n'est pas comprise entre 360 nm et 830 nm,
     * elle est réglée sur 600 nm.
     * \param position La position du coin supérieur gauche de la source.
     * \param edge La longueur du côté du carré modélisant la source.
     * \param waveLength La longueur d'onde du rayon lumineux émis.
     *
     * \see Ray::WL_MIN
     * \see Ray::WL_MAX
     * \see Ray::WL_DFT
     */
    Source(const Point &, const int, const double, const int);

    /*!
     * \brief Retourne la coordonnée du coin supérieur gauche du carré modélisant la
     * destination.
     *
     * \return La coordonnée du coin supérieur gauche du carré modélisant la source.
     */
    const Point & getPosition() const;

    /*!
     * \brief Retourne l'angle du rayon émis.
     *
     * \return l'angle du rayon émis.
     */
    double getAngle() const;

    /*!
     * \brief Retourne la longueur du côté du carré.
     *
     * \return la longueur du côté du carré.
     */
    int getEdge() const;

    /*!
     * \brief Retourne la longueur d'onde du rayon émis.
     *
     * \return la longueur d'onde du rayon émis.
     */
    int getWaveLength() const;

    /*!
     * \brief Permet de savoir l'état d'émission de la source.
     *
     * \return <code>true</code> Si la source émet un rayon lumineux.
     */
    bool isOn() const;

    /*!
     * \brief Allume ou éteint la source.
     *
     * \param on Le nouvel état de la source.
     */
    void setOn(const bool);

    /*!
     * \brief Permet de savoir si deux sources sont les mêmes.
     *
     * \return <code>true</code> Si deux sources sont les mêmes.
     */
    bool operator==(const Source &) const;

    /*!
     * \brief Permet de savoir si deux sources sont différentes.
     *
     * \return <code>true</code> Si deux sources sont différentes.
     */
    bool operator!=(const Source &) const;

    /*!
     * \brief Permet de copier la source en paramètre dans la source locale.
     * \return La source locale modifiée.
     */
    Source & operator=(const Source &);

    /*!
     * \brief Cette méthode est la réaction de la source face à un rayon. Celui-
     * ci ne fait rien.
     */
    void reactToRay(Ray);

    /*!
     * \brief Cette méthode permet de savoir si la source comprend un point.
     *
     * \return <code>nullptr</code> dans tout les cas, la source est un objet
     * qui ne réagit pas.
     */
    Point * includeRay(const Ray &) const;
};

/*!
 * \brief Définition, externe, de l'opérateur permettant de produire un affichage
 * formaté.
 *
 * \return Le ostream rempli de la chaine formatée représentant la Source en
 * paramètre.
 */
std::ostream & operator<<(std::ostream &, const Source &);

inline const Point & Source::getPosition() const
{
    return this->upLeftCorner;
}

inline double Source::getAngle() const
{
    return this->alpha;
}

inline int Source::getEdge() const
{
    return this->width;
}

inline int Source::getWaveLength() const
{
    return this->waveLength;
}

inline bool Source::isOn() const
{
    return this->on;
}

#endif // SOURCE_HPP
