#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

#include "model/wall.hpp"
#include "model/mirror.hpp"
#include "model/crystal.hpp"
#include "model/lens.hpp"
#include "model/nuke.hpp"
#include "model/source.hpp"
#include "model/dest.hpp"

/**
 * Modélise une carte telle qu'utilisée dans le jeu.
 * Une carte est un ensemble de composant tels que des murs,
 * des miroirs, etc.
 */
class Level
{
private :

    const double width;
    const double height;

    Source source {Point{0, 0}, 5, 5., 600};
    Dest dest {Point{0, 0}, 5};

    std::vector<Wall> walls;
    std::vector<Mirror> mirrors;
    std::vector<Crystal> crystals;
    std::vector<Lens> lenses;
    std::vector<Ray> rays;
    std::vector<Nuke> nukes;

public:

    /**
     * Instancie une carte de largeur et hauteur donnée.
     * </p>
     * Quand une carte est crée, quatre murs dénotant ses bords sont
     *  automatiquement ajoutés à la carte.
     * </p>
     * La source et la destination sont initialisées à des valeurs
     * par défaut inutilisables.
     * Vous devez manuellement initialiser la source et la destination
     * via les fonctions
     * appropriées.
     * @param w la largeur de la carte
     * @param h la heuteur de la carte
     */
    Level(const double, const double);

    /**
     * Retourne la source de la carte.
     *
     * @return la source de la carte.
     */
    const Source & getSource() const;

    /**
     * Change la source de la carte
     *
     * @param value la nouvelle source
     */
    void setSource(const Source &);

    /**
     * Retourne la desination de la carte
     *
     * @return la destination de la carte
     */
    const Dest & getDestination() const;

    /**
     * Change la destination de la carte
     *
     * @param value la destination de la carte
     */
    void setDestination(const Dest &);

    /**
     * Retourne l'ensemble des murs de la carte
     *
     * @return l'ensemble des murs de la carte
     */
    const std::vector<Wall> & getWalls() const;

    /**
     * Permet d'ajouter un mur sur la carte.
     *
     * @param newWall nouveau mur à ajouter.
     */
    void addWall(const Wall &);

    /**
     * Retourne l'ensemble des miroirs de la carte
     *
     * @return l'ensemble des miroirs de la carte
     */
    const std::vector<Mirror> & getMirrors() const;

    /**
     * Permet d'ajouter un mirroir sur la carte.
     *
     * @param newMirror nouveau mirroir à ajouter.
     */
    void addMirror(Mirror);

    /**
     * Retourne l'ensemble des cristaux de la carte
     *
     * @return l'ensemble des cristaux de la carte
     */
    const std::vector<Crystal> & getCrystals() const;

    /**
     * Permet d'ajouter un crystal sur la carte.
     *
     * @param newCrystal nouveau crystal à ajouter.
     */
    void addCrystal(Crystal);

    /**
     * Retourne l'ensemble des lentilles de la carte
     *
     * @return l'ensemble des lentilles de la carte
     */
    const std::vector<Lens> & getLenses() const;

    /**
     * Permet d'ajouter une lentille sur la carte.
     *
     * @param newLens nouvelle lentille à ajouter.
     */
    void addLens(Lens);

    /**
     * Retourne l'ensemble des rayons de la carte
     *
     * @return l'ensemble des rayons de la carte
     */
    const std::vector<Ray> & getRays() const;

    /**
     * Change l'ensemble des rayons de la carte
     *
     * @param le nouvel ensemble de rayons de la carte
     */
    void setRays(const std::vector<Ray> &);

    /**
     * Retourne l'ensemble des bombes de la carte
     *
     * @return l'ensemble des bombes de la carte
     */
    const std::vector<Nuke> & getNukes() const;

    /**
     * Permet d'ajouter une bombe sur la carte.
     *
     * @param newNuke nouvelle bombe à ajouter.
     */
    void addNuke(const Nuke &);

    /**
     * Permet de calculer un rayon à partir du rayon entré en paramètre.
     *
     * @param ray Rayon précedent.
     */
    void computeRay(const Ray);

    /**
     * Permet d'ajouter un rayon au level.
     */
    void addRay(Ray &);

    /**
     * Calcule les rayons lumineux de la carte.
     */
    void computeRays();
};

#endif // LEVEL_H
