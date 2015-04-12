#include "test/catch.hpp"
#include <iostream>

#include "model/ray.hpp"
#include "model/geometry/utilities.hpp"

TEST_CASE("Point dans la trajectoire")
{
    SECTION("]0 ; PI_2[ : 1")
    {
        Ray ray(Point(2., 2.), utilities::PI_4, 400);
        REQUIRE(ray.isInTrajectory(Point(3., 3.)));
        REQUIRE(ray.isInTrajectory(Point(3., 4.)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2., 3.)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3., 2.)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1., 1.)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2., 1.)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1., 2.)));
    }

    SECTION("]0 ; PI_2[ : 2")
    {
        Ray ray(Point(2., 2.), - (7 * utilities::PI_4), 400);
        REQUIRE(ray.isInTrajectory(Point(3., 3.)));
        REQUIRE(ray.isInTrajectory(Point(3., 4.)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2., 3.)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3., 2.)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1., 1.)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2., 1.)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1., 2.)));
    }

    SECTION("]PI_2 ; PI[ : 1")
    {
        Ray ray(Point(2., 2.), (3 * utilities::PI_4), 400);
        REQUIRE(ray.isInTrajectory(Point(-1, 3)));
        REQUIRE(ray.isInTrajectory(Point(-2, 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2, 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2, 2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1, 1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3, 1)));
    }

    SECTION("]PI_2 ; PI[ : 2")
    {
        Ray ray(Point(2., 2.),  -4., 400);
        REQUIRE(ray.isInTrajectory(Point(-1, 3)));
        REQUIRE(ray.isInTrajectory(Point(-2, 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2, 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2, 2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1, 1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3, 1)));
    }

    SECTION("]PI ; 3PI_2[ : 1")
    {
        Ray ray(Point(2., 2.), (5 * utilities::PI_4), 400);
        REQUIRE(ray.isInTrajectory(Point(-1., -1)));
        REQUIRE(ray.isInTrajectory(Point(-2., -1)));
        REQUIRE(ray.isInTrajectory(Point(-1., -2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2., -2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(-2., 2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(-2., 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(8., 1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(8., 8)));
    }

    SECTION("]PI ; 3PI_2[ : 2")
    {
        Ray ray(Point(2., 2.), -2, 400);
        REQUIRE(ray.isInTrajectory(Point(-1., -1)));
        REQUIRE(ray.isInTrajectory(Point(-2., -1)));
        REQUIRE(ray.isInTrajectory(Point(-1., -2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2., -2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(-2., 2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(-2., 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(8., 1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(8., 8)));
    }

    SECTION("]3PI_2 ; 0[ : 1")
    {
        Ray ray(Point(2., 2.), (7 * utilities::PI_4), 400);
        REQUIRE(ray.isInTrajectory(Point(3., -1)));
        REQUIRE(ray.isInTrajectory(Point(8., -1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2., 2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1., 1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3., 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1., 3)));
    }

    SECTION("]3PI_2 ; 0[ : 2")
    {
        Ray ray(Point(2., 2.), -0.3, 400);
        REQUIRE(ray.isInTrajectory(Point(3., -1)));
        REQUIRE(ray.isInTrajectory(Point(8., -1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2., 2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1., 1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3., 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1., 3)));
    }

    SECTION("Angle 0")
    {
        Ray ray(Point(2., 2.), 0., 400);
        REQUIRE(ray.isInTrajectory(Point(4, 2)));
        REQUIRE(ray.isInTrajectory(Point(5, 2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(5, 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1, 2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2, 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(-1, 2)));
    }
    SECTION("Angle PI_2")
    {
        Ray ray(Point(2., 2.), utilities::PI_2, 400);
        REQUIRE(ray.isInTrajectory(Point(2, 3)));
        REQUIRE(ray.isInTrajectory(Point(2, 4)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(5, 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2, 1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1, 1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3, 3)));

    }

    SECTION("Angle PI")
    {
        Ray ray(Point(2., 2.), utilities::PI, 400);
        REQUIRE(ray.isInTrajectory(Point(1, 2)));
        REQUIRE(ray.isInTrajectory(Point(0, 2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1, 1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2, 1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3, 1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3, 2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3, 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2, 4)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1, 3)));
    }

    SECTION("Angle 3PI_2")
    {
        Ray ray(Point(2., 2.), (3 * utilities::PI_2), 400);
        REQUIRE(ray.isInTrajectory(Point(2, 1)));
        REQUIRE(ray.isInTrajectory(Point(2, 0)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3, 1)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3, 2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(3, 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(2, 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1, 3)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1, 2)));
        REQUIRE_FALSE(ray.isInTrajectory(Point(1, 1)));
    }
}
