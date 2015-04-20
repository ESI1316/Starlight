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
     * \brief width
     */
    const double width;

    /*!
     * \brief height
     */
    const double height;

    Source source {Point{0, 0}, 10, 30., 400};
    Dest dest {Point{0, 0}, 5};

    std::vector<Wall> walls;
    std::vector<Mirror> mirrors;
    std::vector<Crystal> crystals;
    std::vector<Lens> lenses;
    std::vector<Ray> rays;
    std::vector<Nuke> nukes;

    std::vector<LevelView *> views;

    /*!
     * \brief Permet d'obtenir une map contenant les élément se trouvant sur la
     * trajectoire du rayon, ayant pour clé; le point d'intersection avec cet
     * élément.
     *
     * \param ray Rayon dont on désire obtenir les éléments sur sa trajectoire.
     *
     * \return Une map ontenant les élément se trouvant sur la
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
     * \param h la heuteur de la carte
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
     * \brief Retourne la desination de la carte
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
    const std::vector<Mirror> & getMirrors() const;

    /*!
     * \brief Permet d'ajouter un mirroir sur la carte.
     *
     * \param newMirror nouveau mirroir à ajouter.
     */
    void addMirror(Mirror);

    /*!
     * \brief Retourne l'ensemble des cristaux de la carte
     *
     * \return l'ensemble des cristaux de la carte
     */
    const std::vector<Crystal> & getCrystals() const;

    /*!
     * \brief Permet d'ajouter un crystal sur la carte.
     *
     * \param newCrystal nouveau crystal à ajouter.
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
     * \return true Si une bombe a explosé.
     */
    bool thereIsAnExplodedNuke() const;

    /*!
     * \brief Permet de calculer un rayon à partir du rayon entré en paramètre.
     *
     * \param ray Rayon précedent.
     */
    void computeRay(Ray);

    /*!
     * \brief Calcule les rayons lumineux de la carte.
     */
    void computeRays();

    /*!
     * \brief Permet d'abonner une nouvelle vue au model.
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

#endif // LEVEL_HPP
