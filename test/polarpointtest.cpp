#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../model/point.h"
#include "../model/polarPoint.h"

TEST_CASE( "Cartesian to polar", "Approximation des conversions" ){

    Point a(1,1);

    REQUIRE( PolarPoint(a).getRadius() >= 1.41421356 );
    REQUIRE( PolarPoint(a).getAzimut() == 45. );
}
