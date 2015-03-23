#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../model/point.h"
#include "../model/polarPoint.h"

TEST_CASE( "Cartesian to polar", "Approximation des conversions" )
{

    Point a(1,1);

    SECTION("Rayon")
    {
        PolarPoint pr(a);
        REQUIRE( pr.getRadius() >= 1.4141);
        REQUIRE( pr.getRadius() <= 1.4143);

    }
    SECTION("Angle")
    {
        PolarPoint pa(a);
        REQUIRE( pa.getAzimut() >= 0.7852);
        REQUIRE( pa.getAzimut() <= 0.7855);
    }
}


TEST_CASE("Polar to cartesian", "Approximations des conversions")
{
    PolarPoint p(1.4142, 0.7853);

    SECTION("Abcisse")
    {
        REQUIRE( p.toCartesian().getX() == 1);
    }
    SECTION("Ordonnée")
    {
        REQUIRE( p.toCartesian().getY() == 1);
    }
}
