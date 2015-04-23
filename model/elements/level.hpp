#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>
#include <map>
#include <string>

#include "model/exception/starlightexception.hpp"
#include "model/elements/wall.hpp"
#include "model/elements/mirror.hpp"
#include "model/elements/crystal.hpp"
#include "model/elements/lens.hpp"
#include "model/elements/nuke.hpp"
#include "model/elements/source.hpp"
#include "model/elements/dest.hpp"
#include "model/elements/ray.hpp"
#include "view/windows/levelview.hpp"

class Point;
class Element;

/*!
 * \brief Modélise une carte telle qu'utilisée dans le jeu.
 * Une carte est un ensemble de composant tels que des murs,
 * des miroirs, etc.
 */
class Level
{
private :

    /*!
     * \brief La largeur du niveau.
     */
    const double width;

    /*!
     * \brief La hauteur du niveau.
     */
    const double height;

    /*!
     * \brief La source du niveau.
     */
    Source source {Point{0, 0}, 10, 30., 400};

    /*!
     * \brief La destination du niveau.
     */
    Dest dest {Point{0, 0}, 5};

    /*!
     * \brief L'ensemble des murs du niveau, qu'ils soient ceux qui le délimitent
     * ou des murs supplémentaires ajoutés au niveau même.
     */
    std::vector<Wall> walls;

    /*!
     * \brief mirrors L'ensemble des miroirs présents dans le niveau.
     */
    std::vector<Mirror> mirrors;

    /*!
     * \brief crystals L'ensemble des cristaux présents dans le niveau.
     */
    std::vector<Crystal> crystals;

    /*!
     * \brief lenses L'ensemble des lentilles présentes dans le niveau.
     */
    std::vector<Lens> lenses;

    /*!
     * \brief rays L'ensemble des rayons créés dans le niveau quand la source
     * est allumée.
     */
    std::vector<Ray> rays;

    /*!
     * \brief nukes L'ensemble des bombes créées dans le niveau.
     */
    std::vector<Nuke> nukes;

    /*!
     * \brief views L'ensemble des vues qui observent le niveau.
     */
    std::vector<LevelView *> views;

    /*!
     * \brief Permet d'obtenir une map contenant les élément se trouvant sur la
     * trajectoire du rayon, ayant pour clé; le point d'intersection avec cet
     * élément.
     *
     * \param ray Rayon dont on désire obtenir les éléments sur sa trajectoire.
     *
     * \return Une map contenant les élément se trouvant sur la
     * trajectoire du rayon, ayant pour clé; le point d'intersection avec cet
     * élément.
     */
    std::map<Point *, Element *> getEltsInTrajectory(const Ray & ray);

public:

    /*!
     * \brief Instancie une carte de largeur et hauteur donnée.
     * </p>
     * Quand une carte est crée, quatre murs dénotant ses bords sont
     *  automatiquement ajoutés à la carte.
     * </p>
     * La source et la destination sont initialisées à des valeurs
     * par défaut inutilisables.
     * Vous devez manuellement initialiser la source et la destination
     * via les fonctions
     * appropriées.
     * \param w la largeur de la carte
     * \param h la hauteur de la carte
     */
    Level(const double, const double);

    /*!
     * \brief Permet d'obtenir la longueur du niveau.
     *
     * \return La longueur du niveau.
     */
    int getWidth() const;

    /*!
     * \brief Permet d'obtenir la hauteur du niveau.
     *
     * \return la hauteur du niveau.
     */
    int getHeight() const;

    /*!
     * \brief Retourne la source de la carte.
     *
     * \return la source de la carte.
     */
    Source &getSource();

    /*!
     * \brief Change la source de la carte
     *
     * \param value la nouvelle source
     */
    void setSource(const Source &);

    /*!
     * \brief Retourne la destination de la carte
     *
     * \return la destination de la carte
     */
    const Dest & getDestination() const;

    /*!
     * \brief Change la destination de la carte
     *
     * \param value la destination de la carte
     */
    void setDestination(const Dest &);

    /*!
     * \brief Retourne l'ensemble des murs de la carte
     *
     * \return l'ensemble des murs de la carte
     */
    const std::vector<Wall> & getWalls() const;

    /*!
     * \brief Permet d'ajouter un mur sur la carte.
     *
     * \param newWall nouveau mur à ajouter.
     */
    void addWall(const Wall &);

    /*!
     * \brief Retourne l'ensemble des miroirs de la carte
     *
     * \return l'ensemble des miroirs de la carte
     */
    std::vector<Mirror> & getMirrors();

    /*!
     * \brief Permet d'ajouter un miroir sur la carte.
     *
     * \param newMirror nouveau miroir à ajouter.
     */
    void addMirror(Mirror);

    /*!
     * \brief Retourne l'ensemble des cristaux de la carte
     *
     * \return l'ensemble des cristaux de la carte
     */
    const std::vector<Crystal> & getCrystals() const;

    /*!
     * \brief Permet d'ajouter un cristal sur la carte.
     *
     * \param newCrystal nouveau cristal à ajouter.
     */
    void addCrystal(Crystal);

    /*!
     * \brief Retourne l'ensemble des lentilles de la carte
     *
     * \return l'ensemble des lentilles de la carte
     */
    const std::vector<Lens> & getLenses() const;

    /*!
     * \brief Permet d'ajouter une lentille sur la carte.
     *
     * \param newLens nouvelle lentille à ajouter.
     */
    void addLens(Lens);

    /*!
     * \brief Retourne l'ensemble des rayons de la carte
     *
     * \return l'ensemble des rayons de la carte
     */
    std::vector<Ray> &getRays();

    /*!
     * \brief Change l'ensemble des rayons de la carte
     *
     * \param le nouvel ensemble de rayons de la carte
     */
    void setRays(const std::vector<Ray> &);

    /*!
     * \brief Retourne l'ensemble des bombes de la carte
     *
     * \return l'ensemble des bombes de la carte
     */
    const std::vector<Nuke> & getNukes() const;

    /*!
     * \brief Permet d'ajouter une bombe sur la carte.
     *
     * \param newNuke nouvelle bombe à ajouter.
     */
    void addNuke(const Nuke &);

    /*!
     * \brief Renseigne si une bombe a explosé.
     *
     * \return <code>true</code> Si une bombe a explosé.
     */
    bool thereIsAnExplodedNuke() const;

    /*!
     * \brief Permet de calculer un rayon à partir du rayon entré en paramètre.
     *
     * \param ray Rayon précèdent.
     */
    void computeRay(Ray);

    /*!
     * \brief Calcule les rayons lumineux de la carte.
     */
    void computeRays();

    /*!
     * \brief Permet d'abonner une nouvelle vue au modèle.
     *
     * \param newView Nouvelle vue abonnée au niveau.
     */
    void addView(LevelView *);

    /*!
     * \brief Permet de notifier les vues abonnées au niveau que son état a
     * changé.
     */
    void notifyViews();
};

inline int Level::getWidth() const
{
    return std::round(this->width);
}

inline int Level::getHeight() const
{
    return std::round(this->height);
}

inline Source & Level::getSource()
{
    return this->source;
}

inline const Dest & Level::getDestination() const
{
    return this->dest;
}

inline const std::vector<Wall> & Level::getWalls() const
{
    return this->walls;
}

inline std::vector<Mirror> & Level::getMirrors()
{
    return this->mirrors;
}

inline const std::vector<Crystal> & Level::getCrystals() const
{
    return this->crystals;
}

inline const std::vector<Lens> & Level::getLenses() const
{
    return this->lenses;
}

inline std::vector<Ray> & Level::getRays()
{
    return this->rays;
}

inline const std::vector<Nuke> & Level::getNukes() const
{
    return this->nukes;
}

#endif // LEVEL_HPP
