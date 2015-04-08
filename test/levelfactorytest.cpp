#define CATCH_CONFIG_MAIN
#include "./test/catch.hpp"
#include "../model/levelFactory.hpp"
#include "../model/level.hpp"

TEST_CASE("création d'un Level à partir d'un fichier .lvl", "levelFactory::getLevel(std::string)")
{
    Level * level = levelFactory::getLevelFromFile("./ressources/level.lvl");

    SECTION("vérification de la taille des vecteurs")
    {
        REQUIRE(level->getWalls().size() == 9);
        REQUIRE(level->getMirrors().size() == 11);
        REQUIRE(level->getCrystals().size() == 1);
        REQUIRE(level->getNukes().size() == 2);
        REQUIRE(level->getLenses().size() == 1);
        REQUIRE(level->getRays().size() == 0);
    }

    SECTION("vérification de la valeurs des éléments")
    {
        SECTION("vérification de la source")
        {
            REQUIRE(level->getSource().getPosition() == Point(0., 0.));
            REQUIRE(level->getSource().getEdge() == 29);
            REQUIRE(utilities::equals(level->getSource().getAngle(), 4.));
            REQUIRE(level->getSource().getWaveLength() == 400);
        }

        SECTION("vérification de la destination")
        {
            REQUIRE(level->getDestination().getPosition() == Point(721., 275.));
            REQUIRE(level->getDestination().getEdge() == 29);
        }

        SECTION("vérification d'un des crystals")
        {
            REQUIRE(level->getCrystals()[0].getCenter() == Point(464., 290.));
            REQUIRE(utilities::equals(level->getCrystals()[0].getRadius(), 29));
            REQUIRE(level->getCrystals()[0].getAmplifier() == 40);
        }

        SECTION("vérification d'une bombe")
        {
            REQUIRE(level->getNukes()[0].getLocation() == Point(464., 232.));
            REQUIRE(utilities::equals(level->getNukes()[0].getRadius(), 29.));
        }

        SECTION("vérification d'une lentille")
        {
            REQUIRE(level->getLenses()[0].getPosition() == Point(551, 232));
            //REQUIRE(level->getLenses()[0].getWidth() == 58);
            //REQUIRE(level->getLenses()[0].getHeight() == 116);
            REQUIRE(level->getLenses()[0].getMinWaveLength() == 500);
            REQUIRE(level->getLenses()[0].getMaxWaveLength() == 600);
        }
        SECTION("vérification des murs")
        {
            SECTION("murs entourant le level")
            {

            }

            SECTION("murs à l'intérieur du level")
            {

            }
        }
    }

    delete level;
}
