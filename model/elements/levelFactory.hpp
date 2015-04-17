#ifndef LEVELFACTORY
#define LEVELFACTORY

#include <iostream>
#include <fstream>
#include <sstream>

class Source;
class Nuke;
class Wall;
class Lens;
class Mirror;
class Crystal;
class Dest;
class Level;

/*!
 * \brief Fonctions utilitaires permettant divers éléments du jeu à partir d'un
 * fichier .lvl.
 */
namespace levelFactory
{

    /*!
     * \brief Permet d'obtenir une référence vers une nouvelle carte initiallisé à partir
     * d'un fichier .level.
     *
     * \param mapFilePath chemin vers le fichier .level.
     *
     * \return une référence vers une nouvelle carte initialisée.
     */
    Level * getLevelFromFile(std::string);

    /*!
     * \brief Permet d' obtenir une source à partir d'un fichier .lvl déjà ouvert.
     *
     * \param mapFile Fichier .lvl déjà ouvert.
     *
     * \return Une source.
     */
    Source getSource(std::ifstream &);

    /*!
     * \brief Permet d' obtenir une destination à partir d'un fichier .lvl déjà ouvert.
     *
     * \param mapFile Fichier .lvl déjà ouvert.
     *
     * \return Une destinatation.
     */
    Dest getDestination(std::ifstream &);

    /*!
     * \brief Permet d' obtenir un crystal à partir d'un fichier .lvl déjà ouvert.
     *
     * \param mapFile Fichier .lvl déjà ouvert.
     *
     * \return Un crystal.
     */
    Crystal getCrystal(std::ifstream &);

    /*!
     * \brief Permet d' obtenir une lentille à partir d'un fichier .lvl déjà ouvert.
     *
     * \param mapFile Fichier .lvl déjà ouvert.
     *
     * \return Une lentille.
     */
    Lens getLens(std::ifstream &);

    /*!
     * \brief Permet d' obtenir un mur à partir d'un fichier .lvl déjà ouvert.
     *
     * \param mapFile Fichier .lvl déjà ouvert.
     *
     * \return Un mur.
     */
    Wall getWall(std::ifstream &);

    /*!
     * \brief Permet d' obtenir une bombe à partir d'un fichier .lvl déjà ouvert.
     *
     * \param mapFile Fichier .lvl déjà ouvert.
     *
     * \return Une bombe.
     */
    Nuke getNuke(std::ifstream &);

    /*!
     * \brief Permet d' obtenir un mirroir à partir d'un fichier .lvl déjà ouvert.
     *
     * \param mapFile Fichier .lvl déjà ouvert.
     *
     * \return Un mirroir.
     */
    Mirror getMirror(std::ifstream &);
}

#endif // LEVELFACTORY

