#include "levelFactory.h"

Level * levelFactory::getLevelFromFile(std::string mapFilePath)
{
    std::ifstream mapFile(mapFilePath);
    int i; double d; char c;
    Level * newLevel = new Level((mapFile >> i, i), (mapFile >> i, i));
    std::string line;

    while (std::getline(mapFile, line))
    {
        std::istringstream iss(line);

        switch((iss >> c, c))
        {
        case 'S': newLevel->setSource
                    (Source(Point((iss >> i, i), (iss >> i, i)), (iss >> i, i),
                            (iss >> d, d), (iss >> i, i)));
            break;
        case 'D': newLevel->setDestination
                    (Dest(Point((iss >> i, i), (iss >> i, i)), (iss >> i, i)) );
            break;
        case 'C' : newLevel->addCrystal
                    (Crystal(Point((iss >> i, i), (iss >> i, i)), (iss >> i, i),
                             (iss >> i, i)));
            break;
        case 'L' : newLevel->addLens
                    (Lens(Point((iss >> i, i), (iss >> i, i)), (iss >> i, i),
                          (iss >> i, i), (iss >> i, i),(iss >> i, i)));
            break;
        case 'W' : newLevel->addWall
                    (Wall(Point((iss >> i, i), (iss >> i, i)),
                          Point((iss >> i, i), (iss >> i, i))));
            break;
        case 'N' : newLevel->addNuke
                    (Nuke(Point((iss >> i, i), (iss >> i, i)), (iss >> i, i)));
            break;
        case 'M' : newLevel->addMirror
                    (Mirror(Point((iss >> i, i), (iss >> i, i)), (iss >> i, i),
                            (iss >> i, i), (iss >> d, d),
                            Point((iss >> i, i), (iss >> i, i)),
                            Point((iss >> i, i), (iss >> i, i)), (iss >> d, d),
                            (iss >> d, d)));
            break;
        }
    }

    return newLevel;
}
