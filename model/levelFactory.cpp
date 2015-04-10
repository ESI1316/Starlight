#include "model/levelFactory.hpp"

#include "model/source.hpp"
#include "model/nuke.hpp"
#include "model/wall.hpp"
#include "model/lens.hpp"
#include "model/mirror.hpp"
#include "model/crystal.hpp"
#include "model/dest.hpp"
#include "model/level.hpp"

Level * levelFactory::getLevelFromFile(std::string mapFilePath)
{
    std::ifstream mapFile(mapFilePath);
    double levelWidth, levelHeight;
    char type;
    Level * newLevel;

    mapFile >> levelWidth >> levelHeight;
    newLevel = new Level{levelWidth, levelHeight};

    while (mapFile >> type)
    {
        switch(type)
        {
        case 'S': newLevel->setSource(levelFactory::getSource(mapFile));
            break;
        case 'D': newLevel->setDestination(levelFactory::getDestination(mapFile));
            break;
        case 'C' : newLevel->addCrystal(levelFactory::getCrystal(mapFile));
            break;
        case 'L' : newLevel->addLens(levelFactory::getLens(mapFile));
            break;
        case 'W' : newLevel->addWall(levelFactory::getWall(mapFile));
            break;
        case 'N' : newLevel->addNuke(levelFactory::getNuke(mapFile));
            break;
        case 'M' : newLevel->addMirror(levelFactory::getMirror(mapFile));
            break;
        }
    }

    mapFile.close();

    return newLevel;
}

Source levelFactory::getSource(std::ifstream & mapFile)
{
    int edge, wavelength; double alpha, x, y;

    mapFile >> x >> y >> edge >> alpha >> wavelength;

    return Source{Point{x, y}, edge, alpha, wavelength};
}

Dest levelFactory::getDestination(std::ifstream & mapFile)
{
    int edge;
    double x, y;

    mapFile >> x >> y >> edge;

    return Dest{Point{x, y}, edge};
}

Crystal levelFactory::getCrystal(std::ifstream &  mapFile)
{
    double x, y, rad; int mod;

    mapFile >> x >> y >> rad >> mod;

    return Crystal{Point{x, y}, rad, mod};

}

Lens levelFactory::getLens(std::ifstream & mapFile)
{
    double x, y; int  width, height, wlmin, wlmax;

    mapFile >> x >> y >>  width >> height >> wlmin >> wlmax;

    return Lens{Point{x, y}, width, height, wlmin, wlmax};
}

Wall levelFactory::getWall(std::ifstream & mapFile)
{
    double x1, y1, x2, y2;

    mapFile >> x1 >> y1 >> x2 >> y2;

    return Wall{Point{x1, y1}, Point{x2, y2}};
}

Nuke levelFactory::getNuke(std::ifstream & mapFile)
{
    double x, y, rad;

    mapFile >> x >> y >> rad;

    return Nuke{Point{x, y}, rad};
}

Mirror levelFactory::getMirror(std::ifstream & mapFile)
{
    int length, xPad;
    double xMin, yMin, xMax, yMax, alpha, alphaMin, alphaMax, x, y;

    mapFile >> x >> y >> xPad >> length >> alpha >> xMin >> yMin >> xMax >> yMax
            >> alphaMin >> alphaMax;

    return Mirror{Point{x, y}, xPad, length, alpha, Point{xMin, yMin},
        Point{xMax, yMax}, alphaMin, alphaMax};
}
