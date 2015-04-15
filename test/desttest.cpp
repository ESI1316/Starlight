#include "test/catch.hpp"
#include <iostream>
#include "model/dest.hpp"
#include "model/geometry/rectangle.hpp"
#include "model/geometry/utilities.hpp"
#include "model/point.hpp"
#include "model/ray.hpp"
#include "model/starlightexception.hpp"

TEST_CASE("Dest : constructeurs")
{
    REQUIRE_THROWS_AS(Dest(Point(2, 2), 0), StarlightException);
    REQUIRE_THROWS_AS(Dest(Point(2, 2), -1), StarlightException);
    REQUIRE_NOTHROW(Dest(Point(2, 2), 3));
}

TEST_CASE("Dest : accesseurs")
{
    Dest dest{Point{2., 3.}, 18};

    REQUIRE(dest.getEdge() == 18);
    REQUIRE_FALSE(dest.isLightedUp());
    dest.setLightedUp(true);
    REQUIRE(dest.isLightedUp());
}

TEST_CASE("Dest : operateurs")
{
    Dest dest{Point{2., 3.}, 18};
    Dest de{Point{2., 3.}, 18};
    Dest d{Point{2., 3.}, 48};

    REQUIRE(dest == de);
    REQUIRE_FALSE(dest != de);
    REQUIRE(dest != d);

    de.setLightedUp(true);
    REQUIRE_FALSE(dest == de);
}

TEST_CASE("Dest : includeRay")
{
    Dest dest{Point{5.4, 3.}, 18};

    SECTION("droite quelconque : pas d'intersection")
    {
        Ray ray{Point{2.7766139723, -2.5169499277}, -0.2415937631, 649};
        Point * intersection = dest.includeRay(ray);
        REQUIRE(intersection == 0);
    }
    SECTION("droite quelconque : intersection")
    {
        Ray ray{Point{2.7766139723, -2.5169499277}, -0.4413298865, 649};

        Point * intersection = dest.includeRay(ray);
        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(23.4, 7.2256651053));
        delete intersection;
    }

    SECTION("droite verticale : pas d'intersection")
    {
        Ray ray{Point{2.7766139723, -2.5169499277}, -utilities::PI_2, 649};

        Point * intersection = dest.includeRay(ray);
        REQUIRE(intersection == 0);
    }

    SECTION("droite verticale : intersection")
    {
        Ray ray{Point{9.7766139723, -2.5169499277}, -utilities::PI_2, 649};

        Point * intersection = dest.includeRay(ray);
        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(9.7766139723, 21));
        delete intersection;
    }
    SECTION("droite verticale : pas d'intersection")
    {
        Ray ray{Point{-5.132736737, 25.752491025}, 0., 649};

        Point * intersection = dest.includeRay(ray);
        REQUIRE(intersection == 0);
    }
    SECTION("droite verticale : intersection")
    {
        Ray ray{Point{-5.132736737, 12.752491025}, 0., 649};

        Point * intersection = dest.includeRay(ray);
        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(23.4, 12.752491025));
        delete intersection;
    }
}

