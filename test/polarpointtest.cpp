#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../model/point.h"
#include "../model/polarPoint.h"

SCENARIO("Converting a cartesian point to a polar one ", "PolarPoint")
{
    GIVEN( "A cartesian point" )
    {
        Point a(1,1);

        REQUIRE( a.getX() == 1 );
        REQUIRE( a.getY() >= 1 );

        WHEN(" Converted as a polar point")
        {
            PolarPoint pr(a);

            THEN("Attributes are expressed as radius")
            {
                REQUIRE( pr.getRadius() >= 1.4141);
                REQUIRE( pr.getRadius() <= 1.4143);
                REQUIRE( pr.getAzimut() >= 0.7852);
                REQUIRE( pr.getAzimut() <= 0.7855);
            }
        }
    }
}

SCENARIO("Converting a polar point to a cartesian one ", "PolarPoint")
{
    GIVEN(" A polar point")
    {
        PolarPoint pp(1.4142, 0.7853);

        WHEN(" Converted as a cartesian point")
        {
            Point p = pp.toCartesian();

            THEN("Attributes are expressed as coordinates")
            {
                REQUIRE( p.getX() == 1);
                REQUIRE( p.getY() == 1);
            }
        }
    }
}
