#ifndef LEVEL_H
#define LEVEL_H

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

class Point;
class Element;

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

    Source source {Point{0, 0}, 10, 30., 400};
    Dest dest {Point{0, 0}, 5};

    std::vector<Wall> walls;
    std::vector<Mirror> mirrors;
    std::vector<Crystal> crystals;
    std::vector<Lens> lenses;
    std::vector<Ray> rays;
    std::vector<Nuke> nukes;

    /**
     * Permet d'obtenir une map contenant les élément se trouvant sur la
     * trajectoire du rayon, ayant pour clé; le point d'intersection avec cet
     * élément.
     *
     * @param ray Rayon dont on désire obtenir les éléments sur sa trajectoire.
     *
     * @return Une map ontenant les élément se trouvant sur la
     * trajectoire du rayon, ayant pour clé; le point d'intersection avec cet
     * élément.
     */
    std::map<Point *, Element *> getEltsInTrajectory(const Ray & ray);

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
     * Renseigne si une bombe a explosé.
     *
     * @return true Si une bombe a explosé.
     */
    bool thereIsAnExplodedNuke() const;

    /**
     * Permet de calculer un rayon à partir du rayon entré en paramètre.
     *
     * @param ray Rayon précedent.
     */
    void computeRay(Ray);

    /**
     * Calcule les rayons lumineux de la carte.
     */
    void computeRays();
};

#endif // LEVEL_H
