#include "test/catch.hpp"
#include "model/nuke.hpp"
#include "model/ray.hpp"
#include "model/starlightexception.hpp"
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
    Nuke duke(Nuke(Point(15., 20.), 10.));

    SECTION("Droite quelconque : pas d'intersection")
    {
        Ray ray{Point{0., 0.}, 83., 400};
        Point * intersection = duke.includeRay(ray);

        REQUIRE(intersection == 0);
    }
/*
    SECTION("Droite quelconque : tangeante")
    {
        Ray ray{Point{2., 1.}, 45.02, 400};
        Point * intersection = duke.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(3.5947954986, 2.4295116134));

        delete intersection;
    }

    SECTION("Droite quelconque : 2 intersections")
    {
        Ray ray{Point{2., 1.}, 0.7308006587, 400};
        Point * intersection = duke.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(3.5947954986, 2.4295116134));

        delete intersection;
    }

    SECTION("Droite horizontale : pas d'intersection")
    {
        Ray ray{Point{1.4191947327, 3.4719175286}, 0., 400};
        Point * intersection = wall.includeRay(ray);

        REQUIRE(intersection == 0);
    }

    SECTION("Droite horizontale : tangeante")
    {
        Ray ray{Point{1.4191947327, 2.4719175286}, 0., 400};
        Point * intersection = wall.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(3.7163445871, 2.4719175286));
        delete intersection;
    }

    SECTION("Droite horizontale : 2 intersections")
    {
        Ray ray{Point{1.4191947327, 2.4719175286}, 0., 400};
        Point * intersection = wall.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(3.7163445871, 2.4719175286));
        delete intersection;
    }

    SECTION("Droite verticale : pas d'intersection")
    {
        Ray ray{Point{2., 1.}, utilities::PI_2, 400};
        Point * intersection = wall.includeRay(ray);

        REQUIRE(intersection == 0);

    }

    SECTION("Droite verticale : tangeante")
    {
        Ray ray{Point{4.2685319879, 1.}, utilities::PI_2, 400};
        Point * intersection = wall.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(4.2685319879, 2.6645640747));
        delete intersection;

    }

    SECTION("Droite verticale : 2 intersctions")
    {
        Ray ray{Point{4.2685319879, 1.}, utilities::PI_2, 400};
        Point * intersection = wall.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(4.2685319879, 2.6645640747));
        delete intersection;

    }
    */
    // je sais pas comment créer un ray :(
    // Ray ray(point de depart, angle de tir, wavelenght)
    // tu créer une droite sur geogebra, tu utilises l'outils pour trouver l'angle (en radian)
    // de l'intersection avec l'axe des x
}
