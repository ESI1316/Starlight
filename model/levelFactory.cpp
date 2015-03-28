#include "levelFactory.hpp"

Level * levelFactory::getLevelFromFile(std::string mapFilePath)
{
    std::ifstream mapFile(mapFilePath);
    int i; char c;
    Level * newLevel = new Level((mapFile >> i, i), (mapFile >> i, i));

    while (mapFile >> c)
    {
        switch(c)
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
    int x, y, edge, wavelength; double alpha;

    mapFile >> x >> y >> edge >> alpha >> wavelength;

    return Source(Point(x, y), edge, alpha, wavelength);
}

Dest levelFactory::getDestination(std::ifstream & mapFile)
{
    int x, y, edge;

    mapFile >> x >> y >> edge;

    return Dest(Point(x, y), edge);
}

Crystal levelFactory::getCrystal(std::ifstream &  mapFile)
{
    int x, y, rad, mod;

    mapFile >> x >> y >> rad >> mod;

    return Crystal(Point(x, y), rad, mod);
}

Lens levelFactory::getLens(std::ifstream & mapFile)
{
    int x, y, width, height, wlmin, wlmax;

    mapFile >> x >> y >>  width >> height >> wlmin >> wlmax;

    return Lens(Point(x, y), width, height, wlmin, wlmax);
}

Wall levelFactory::getWall(std::ifstream & mapFile)
{
    int x1, y1, x2, y2;

    mapFile >> x1 >> y1 >> x2 >> y2;

    return Wall(Point(x1, y1), Point(x2, y2));
}

Nuke levelFactory::getNuke(std::ifstream & mapFile)
{
    int x, y, rad;

    mapFile >> x >> y >> rad;

    return Nuke(Point(x, y), rad);
}

Mirror levelFactory::getMirror(std::ifstream & mapFile)
{
    int x, y, length, xPad, xMin, yMin, xMax, yMax;
    double alpha, alphaMin, alphaMax;

    mapFile >> x >> y >> length >> xPad >> alpha >> xMin >> yMin >> xMax >> yMax
        >> alphaMin >> alphaMax;

    return Mirror(Point(x, y), length, xPad, alpha, Point(xMin, yMin),
                  Point(xMax, yMax), alphaMin, alphaMax);
}
