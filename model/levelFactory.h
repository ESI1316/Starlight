#ifndef LEVELFACTORY
#define LEVELFACTORY

#include <iostream>
#include <fstream>
#include <sstream>
#include "level.h"

/**
 * fonctions utilitaires permettant d'obtenir une nouvelle carte du jeu initialisée.
 */
namespace levelFactory
{

    /**
     * Permet d'obtenir une référence vers une nouvelle carte initiallisé à partir
     * d'un fichier .map.
     *
     * @param mapFilePath chemin vers le fichier .map.
     *
     * @return une référence vers une nouvelle carte initialisée.
     */
    Level * getLevelFromFile(std::string);
}

#endif // LEVELFACTORY

