#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "model/levelFactory.hpp"
#include "model/level.hpp"
#include "model/starlightexception.hpp"

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
            REQUIRE(level->getSource() == Source(Point(0., 0.), 29, 4.75, 400));
        }

        SECTION("vérification de la destination")
        {
            REQUIRE(level->getDestination() == Dest(Point(721., 275.), 29));
        }

        SECTION("vérification du crystal")
        {
            REQUIRE(level->getCrystals()[0] == Crystal(Point(464., 290.), 29, 40));
        }

        SECTION("vérification des bombes")
        {
            REQUIRE(level->getNukes()[0] == Nuke(Point(464., 232.), 29));
            REQUIRE(level->getNukes()[1] == Nuke(Point(464., 248.), 29));
        }

        SECTION("vérification des lentille")
        {
            //quand les lens seront fully des ellipses (franglais Jean Claude Vandamme)
        }

        SECTION("vérification des murs")
        {
            SECTION("murs entourant le level")
            {
                REQUIRE(level->getWalls()[0] == Wall(Point(0., 0.), Point(0., 580.)));
                REQUIRE(level->getWalls()[1] == Wall(Point(0., 580.), Point(720., 580.)));
                REQUIRE(level->getWalls()[2] == Wall(Point(720., 580.), Point(720., 0.)));
                REQUIRE(level->getWalls()[3] == Wall(Point(720, 0.), Point(0., 0.)));
            }

            SECTION("murs à l'intérieur du level")
            {
                REQUIRE(level->getWalls()[4] == Wall(Point(58., 0.), Point(58., 464.)));
                REQUIRE(level->getWalls()[5] == Wall(Point(116., 116.), Point(116., 580.)));
                REQUIRE(level->getWalls()[6] == Wall(Point(174., 0.), Point(174., 464.)));
                REQUIRE(level->getWalls()[7] == Wall(Point(580., 0.), Point(580., 232.)));
                REQUIRE(level->getWalls()[8] == Wall(Point(580., 348.), Point(580., 580.)));
            }
        }

        SECTION("vérification des mirroirs")
        {
            REQUIRE( level->getMirrors()[0] ==
                    Mirror(Point(0., 290.), 0, 58, -1.57, Point(0., 0.),
                           Point(0., 580.), -1.57, 1.57) );

            REQUIRE( level->getMirrors()[1] ==
                    Mirror(Point(116., 290), 0, 58, 1.57, Point(116., 116.),
                           Point(116., 522), 1.57, 4.71) );

            REQUIRE( level->getMirrors()[2] ==
                    Mirror(Point(58., 290.), 0, 58, 1.57, Point(58., 58.),
                           Point(58., 464.), -1.57, 1.57) );

            REQUIRE( level->getMirrors()[3] ==
                    Mirror(Point(174., 290.), 0, 58, 1.57, Point(174., 58.),
                           Point(174., 464.), 1.57, 4.71) );
        }
    }

    delete level;
}
