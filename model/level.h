#ifndef LEVEL_H
#define LEVEL_H

#include "crystal.h"
#include "dest.h"
#include "lens.h"
#include "mirror.h"
#include "ray.h"
#include "source.h"
#include "wall.h"
#include "point.h"
#include "nuke.h"

#include <vector>

/**
 * Modélise une carte telle qu'utilisée dans le jeu.
 * </p>
 * Une carte est un ensemble de composant tels que des murs,
 * des miroirs, etc.
 */
class Level
{
    const int width;
    const int height;

    Source s {{0, 0}, -1, 5, 600};
    Dest d {{0, 0}, 5};

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
    Level(int w, int h);

    /**
     * Retourne la source de la carte.
     * @return la source de la carte.
     */
    const Source & getSource() const;

    /**
     * Change la source de la carte
     * @param value la nouvelle source
     */
    void setSource(const Source & value);

    /**
     * Retourne la desination de la carte
     * @return la destination de la carte
     */
    const Dest & getDestination() const;

    /**
     * Change la destination de la carte
     * @param value la destination de la carte
     */
    void setDestination(const Dest & value);

    /**
     * Retourne l'ensemble des murs de la carte
     * @return l'ensemble des murs de la carte
     */
    const std::vector<Wall> & getWalls() const;

    /**
     * Permet d'ajouter un mur sur la carte.
     * @param newWall nouveau mur à ajouter.
     */
    void addWall(const Wall & newWall);

    /**
     * Retourne l'ensemble des miroirs de la carte
     * @return l'ensemble des miroirs de la carte
     */
    const std::vector<Mirror> & getMirrors() const;

    /**
     * Permet d'ajouter un mirroir sur la carte.
     * @param newMirror nouveau mirroir à ajouter.
     */
    void addMirror(const Mirror & newMirror);

    /**
     * Retourne l'ensemble des cristaux de la carte
     * @return l'ensemble des cristaux de la carte
     */
    const std::vector<Crystal> & getCrystals() const;

    /**
     * Permet d'ajouter un crystal sur la carte.
     * @param newCrystal nouveau crystal à ajouter.
     */
    void addCrystal(const Crystal & newCrystal);

    /**
     * Retourne l'ensemble des lentilles de la carte
     * @return l'ensemble des lentilles de la carte
     */
    const std::vector<Lens> & getLenses() const;

    /**
     * Permet d'ajouter une lentille sur la carte.
     * @param newLens nouvelle lentille à ajouter.
     */
    void addLens(const Lens & newLens);

    /**
     * Retourne l'ensemble des rayons de la carte
     * @return l'ensemble des rayons de la carte
     */
    const std::vector<Ray> & getRays() const;

    /**
     * Change l'ensemble des rayons de la carte
     * @param le nouvel ensemble de rayons de la carte
     */
    void setRays(const std::vector<Ray> & v);

    /**
     * Retourne l'ensemble des bombes de la carte
     * @return l'ensemble des bombes de la carte
     */
    const std::vector<Nuke> & getNukes() const;

    /**
     * Permet d'ajouter une bombe sur la carte.
     * @param newNuke nouvelle bombe à ajouter.
     */
    void addNuke(const Nuke & newNuke);

    /**
     * Calcule les rayons lumineux de la carte.
     * </p>
     * Cette fonction doit être surchargée obligatoirement.
     */
    void computeRays();
};

#endif // LEVEL_H
