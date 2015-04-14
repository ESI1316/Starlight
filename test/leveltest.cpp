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

    }

    SECTION("Rencontre avec un miroir")
    {

    }

    SECTION("Rencontre avec une bombe")
    {

    }

    SECTION("Rencontre avec une lentille laissant passer le rayon")
    {

    }

    SECTION("Rencontre avec une lentille ne laissant pas passer le rayon")
    {

    }

    SECTION("Rencontre avec un crystal")
    {

    }
}
/*
TEST_CASE("computeRays") // tous les parcours inclusent la rencontre avec des mirroirs
{
    SECTION("parcour menant à la rencontre d'un mur ")
    {
        Level * level = levelFactory::getLevelFromFile("");

        REQUIRE(level.getRays().size() == );
        REQUIRE(level.getRays()[0] == );
        
        delete level;
    }

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
}
*/
