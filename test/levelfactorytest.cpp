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
            REQUIRE(level->getNukes()[1] == Nuke(Point(464., 348.), 29));
        }

        SECTION("vérification de la lentille")
        {
            REQUIRE(level->getLenses().at(0) == Lens(Point(551., 232.), 58, 116, 500, 600));
        }

        SECTION("vérification des murs")
        {
            SECTION("murs entourant le level")
            {
                REQUIRE(level->getWalls()[0] == Wall(Point(0., 0.), Point(0., 580.)));
                REQUIRE(level->getWalls()[1] == Wall(Point(0., 580.), Point(750., 580.)));
                REQUIRE(level->getWalls()[2] == Wall(Point(750., 580.), Point(750., 0.)));
                REQUIRE(level->getWalls()[3] == Wall(Point(750, 0.), Point(0., 0.)));
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

            REQUIRE( level->getMirrors()[4] ==
                    Mirror(Point(116., 290.), 0, 58, -1.57, Point(116., 116.),
                           Point(116., 522.), -1.57, 1.57) );

            REQUIRE( level->getMirrors()[5] ==
                    Mirror(Point(580., 116.), 0, 58, 1.57, Point(580., 58.),
                           Point(580., 174.), 1.57, 3.14) );

            REQUIRE( level->getMirrors()[6] ==
                    Mirror(Point(377., 0.), 0, 58, 3.14, Point(232., 0.),
                           Point(522., 0.), 3.14, 6.28) );

            REQUIRE( level->getMirrors()[7] ==
                    Mirror(Point(580., 464.), 0, 58, 4.71, Point(580., 406.),
                           Point(580., 522.), 3.14, 4.71) );

            REQUIRE( level->getMirrors()[8] ==
                    Mirror(Point(203., 406.), 29, 58, 2.35, Point(203., 377.),
                           Point(290., 435.), 0.78, 2.35) );

            REQUIRE( level->getMirrors()[9] ==
                    Mirror(Point(464., 348.), 29, 58, 2.35, Point(464., 348.),
                           Point(551., 464.), 0.78, 2.35) );

            REQUIRE( level->getMirrors()[10] ==
                    Mirror(Point(203., 261.), 29, 58, 2.35, Point(203., 261.),
                           Point(290., 522.), 0.78, 2.35) );
        }
    }

    delete level;
}
