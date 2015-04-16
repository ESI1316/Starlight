#include "test/catch.hpp"
#include "model/level.hpp"
#include "model/levelFactory.hpp"

// constructeur, accesseurs et mutateurs sont testés dans levelFactoryTest

TEST_CASE("computeRay")
{

    SECTION("des éléments se trouvent de part et d'autre de la trajectoire du rayon")
    {

    }

    SECTION("des éléments se trouvent dans la trajectoire du rayon")
    {

    }

    SECTION("Rencontre avecc un mur")
    {
        Level * level = levelFactory::getLevelFromFile("./ressources/W.lvl");
        level->computeRays();

        REQUIRE(level->getRays().size() == 1);
        delete level;
    }

    SECTION("Rencontre avec un miroir")
    {
        Level * level = levelFactory::getLevelFromFile("./ressources/MW.lvl");
        level->computeRays();
        delete level;
    }

    SECTION("Rencontre avec une bombe")
    {
        Level * level = levelFactory::getLevelFromFile("./ressources/N.lvl");
        level->computeRays();
        REQUIRE(level->getRays().size() == 1);

        bool boom = false;

        for(Nuke a : level->getNukes())
            boom = (boom || a.isLightedUp());

        REQUIRE(boom);

        delete level;
    }

    SECTION("Rencontre avec une lentille laissant passer le rayon")
    {
        Level * level = levelFactory::getLevelFromFile("./ressources/LW.lvl");
        level->computeRays();
        REQUIRE(level->getRays().size() == 1);
        delete level;

    }

    SECTION("Rencontre avec une lentille ne laissant pas passer le rayon")
    {
        Level * level = levelFactory::getLevelFromFile("./ressources/L_STOP.lvl");
        level->computeRays();
        REQUIRE(level->getRays().size() == 1);
        delete level;
    }
    SECTION("Rencontre avec une lentille ne laissant pas passer le rayon 2")
    {
        Level * level = levelFactory::getLevelFromFile("./ressources/ML_STOP.lvl");
        level->computeRays();
        REQUIRE(level->getRays().size() == 3);
        std::cout << level->getRays().at(2) << std::endl;
        delete level;
    }

    SECTION("Rencontre avec un crystal")
    {

    }
}

TEST_CASE("computeRays") // tous les parcours inclusent la rencontre avec des mirroirs
{
    SECTION("parcour menant à la rencontre d'un mur ")
    {
        Level * level = levelFactory::getLevelFromFile("./ressources/MW.lvl");
        level->computeRays();

        REQUIRE(level->getRays().size() == 2);

        Ray ray(Point(0, 0), 4.75, 400);
        REQUIRE((Line) level->getRays().at(0) ==  (Line)ray);

        delete level;
    }
/*
    SECTION("parcour menant à la l'illumination de la destination")
    {
        Level * level = levelFactory::getLevelFromFile("");

        REQUIRE(level.getRays().size() == );
        REQUIRE(level.getDestination().isLightedUp());

        delete level;
    }

    SECTION("parcour menant à la rencontre d'une bombe")
    {
        Level * level = levelFactory::getLevelFromFile("");

        REQUIRE(level.getRays().size() == );
        REQUIRE(level->thereIsAnExplodedNuke());

        delete level;
    }

    SECTION("parcour menant à la rencontre d'un crystal")
    {
        Level * level = levelFactory::getLevelFromFile("");

        REQUIRE(level.getRays().size() == );
        REQUIRE(level.getDestination().isLightedUp());

        delete level;
    }

    SECTION("parcour menant à la rencontre d'une lentille laissant passer le rayon")
    {
        Level * level = levelFactory::getLevelFromFile("");

        REQUIRE(level.getRays().size() == );
        REQUIRE(level.getDestination().isLightedUp());

        delete level;
    }

    SECTION("parcour menant à la rencontre d'une lentille ne laissant pas passer le rayon")
    {
        Level * level = levelFactory::getLevelFromFile("");

        REQUIRE(level.getRays().size() == );
        REQUIRE(level.getDestination().isLightedUp());

        delete level;
    }
    */
}
