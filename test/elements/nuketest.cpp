/*
#include "test/catch.hpp"
#include "model/elements/nuke.hpp"
#include "model/elements/ray.hpp"
#include "model/exception/starlightexception.hpp"
#include "model/geometry/utilities.hpp"

TEST_CASE("construction")
{
    REQUIRE_NOTHROW(Nuke(Point(4., 3.), 7.));
    REQUIRE_THROWS_AS(Nuke(Point(2., 11.), -1000), StarlightException);
}

TEST_CASE("accesseurs et mutateurs")
{
    Nuke duke(Nuke(Point(4., 3.), 10.));

    REQUIRE(utilities::equals(duke.getRadius(), 10.));
    REQUIRE(duke.getLocation() == Point(4., 3.));
    REQUIRE_FALSE(duke.isLightedUp());
    duke.setLightedUp(true);
    REQUIRE(duke.isLightedUp());
}

TEST_CASE("includeRay(Ray)")
{
    Nuke duke{Nuke{Point{4.66, 5.88}, 10.}};

    SECTION("Droite quelconque : pas d'intersection")
    {
        Ray ray{Point{-6.9684096396, -6.7533025782}, 1.4876550949, 400};
        Point * intersection = duke.includeRay(ray);

        REQUIRE(intersection == 0);
    }

    SECTION("Droite quelconque : tangeante")
    {
        Ray ray{Point{-6.9684096396, -6.7533025782}, -1.4484713166, 400};
        Point * intersection = duke.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(-5.2652762061, 7.100201718));
        delete intersection;
    }


    SECTION("Droite quelconque : 2 intersections")
    {
        Ray ray{Point{-6.9684096396, -6.7533025782}, -0.5324265834, 400};
        Point * intersection = duke.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(14.6594015744, 5.9893990581));

        delete intersection;
    }

    SECTION("Droite horizontale : pas d'intersection")
    {
        Ray ray{Point{-6.9684096396, -6.7533025782}, 0., 400};
        Point * intersection = duke.includeRay(ray);

        REQUIRE(intersection == 0);
    }

    SECTION("Droite horizontale : tangeante")
    {
        Ray ray{Point{-6.9684096396, -4.12}, 0., 400};
        Point * intersection = duke.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(4.66, -4.12));
        delete intersection;
    }

    SECTION("Droite horizontale : 2 intersections")
    {
        Ray ray{Point{-6.9684096396, 4.7533025782}, 0., 400};
        Point * intersection = duke.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(14.5963249202, 4.7533025782));
        delete intersection;
    }

    SECTION("Droite verticale : pas d'intersection")
    {
        Ray ray{Point{-6.9684096396, -6.7533025782}, utilities::PI_2, 400};
        Point * intersection = duke.includeRay(ray);

        REQUIRE(intersection == 0);

    }

    SECTION("Droite verticale : tangeante")
    {
        Ray ray{Point{-5.34, -3.0920099007}, -utilities::PI_2, 400};
        Point * intersection = duke.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(-5.34, 5.88));
        delete intersection;

    }

    SECTION("Droite verticale : 2 intersctions")
    {
        Ray ray{Point{10.8200887993, -6.4217017861}, (3 * utilities::PI_2), 400};
        Point * intersection = duke.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(10.8200887993, 13.7573920802));
        delete intersection;
    }
}
*/
