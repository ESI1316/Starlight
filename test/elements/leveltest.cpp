#include "main.hpp"

#ifdef RUN_TEST

#include "test/catch.hpp"
#include "model/elements/level.hpp"
#include "model/elements/levelFactory.hpp"

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
        Level * level = levelFactory::getLevelFromFile("./ressources/maps_test/W.lvl");
        level->getSource().setOn(true);
        level->computeRays();

        REQUIRE(level->getRays().size() == 1);
        delete level;
    }

    SECTION("Rencontre avec un miroir")
    {
        Level * level = levelFactory::getLevelFromFile("./ressources/maps_test/MW.lvl");
        level->getSource().setOn(true);
        level->computeRays();
        delete level;
    }

    SECTION("Rencontre avec une bombe")
    {
        Level * level = levelFactory::getLevelFromFile("./ressources/maps_test/N.lvl");
        level->getSource().setOn(true);
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
    }

    SECTION("Rencontre avec une lentille ne laissant pas passer le rayon")
    {
    }
    SECTION("Rencontre avec une lentille ne laissant pas passer le rayon 2")
    {
    }

    SECTION("Rencontre avec un crystal")
    {
    }
}

TEST_CASE("computeRays") // tous les parcours inclusent la rencontre avec des mirroirs
{
    SECTION("parcour menant à la rencontre d'un mur ")
    {
    }

    SECTION("parcour menant à la l'illumination de la destination")
    {
    }

    SECTION("parcour menant à la rencontre d'une bombe")
    {
    }

    SECTION("parcour menant à la rencontre d'un crystal")
    {
    }

    SECTION("parcour menant à la rencontre d'une lentille laissant passer le rayon")
    {
    }

    SECTION("parcour menant à la rencontre d'une lentille ne laissant pas passer le rayon")
    {
    }
}

#endif

