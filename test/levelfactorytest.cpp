#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../model/levelFactory.hpp"
#include "../model/level.hpp"

TEST_CASE("creation of a level from a file", "levelFactory::getLevel(std::string)")
{
    Level * level = levelFactory::getLevelFromFile("./ressources/level.lvl");

    REQUIRE(level != 0);
    SECTION("checking sizes of vectors")
    {
        REQUIRE(level->getWalls().size() == 9);
        REQUIRE(level->getMirrors().size() == 11);
        REQUIRE(level->getCrystals().size() == 1);
        REQUIRE(level->getNukes().size() == 2);
        REQUIRE(level->getLenses().size() == 1);
        REQUIRE(level->getRays().size() == 0);
    }

    SECTION("checking correctness of components attributes value")
    {
        REQUIRE(level->getSource().getPosition() == Point(0, 0));
        REQUIRE(level->getSource().getEdge() == 29);
        REQUIRE(level->getSource().getAngle() == 4.75);
        REQUIRE(level->getSource().getWaveLength() == 400);

        REQUIRE(level->getDestination().getPosition() == Point(721, 275));
        REQUIRE(level->getDestination().getEdge() == 29);
    }
    delete level;
}
