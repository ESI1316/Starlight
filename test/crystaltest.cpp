#include <iostream>
#include "test/catch.hpp"
#include "model/starlightexception.hpp"
#include "model/crystal.hpp"
#include "model/ray.hpp"

TEST_CASE("Constructions de cristaux")
{
    REQUIRE_THROWS_AS(Crystal(Point(1., 1.), -2., -181), StarlightException);
    REQUIRE_NOTHROW(Crystal(Point(0., 0.), 2., 100));

    Crystal cristal{Point{0.,0.}, 2., 100};
    REQUIRE(cristal.getCenter() == Point(0., 0.));
    REQUIRE(utilities::equals(cristal.getRadius(), 2.));
    REQUIRE(utilities::equals(cristal.getAmplifier(), 100));
}

TEST_CASE("reaction au rayon : Doit être similé car le rayon passe en copie")
{
    Crystal cristal{Point{0.,0.}, 2., 100};
    Ray ray{Point{2., 2.}, (utilities::PI / 3), 500};

    ray.setWaveLength(ray.getWaveLength() + cristal.getAmplifier());

    REQUIRE(ray.getWaveLength() == 600);
}

TEST_CASE("Cristal : operateurs")
{
    Crystal cristal{Point{0.,0.}, 2., 100};
    Crystal crist{Point{0.,0.}, 2., 100};
    Crystal cri{Point{3.,0.}, 2., 100};

    REQUIRE(cristal == crist);
    REQUIRE(!(cristal != crist));
    REQUIRE_FALSE(cristal == cri);
    REQUIRE_FALSE(crist == cri);
    REQUIRE(cristal != cri);
    REQUIRE(crist != cri);
}

TEST_CASE("Intersection cristal et rayon ! le point de sortie")
{
    SECTION("Droite quelconque : pas d'intersection")
    {
        Crystal cristal{Point{3., 3.}, 2.5862714475, -72};
        Ray ray{Point{-2.38, -1.62},0.2670937998, 373};

        Point * intersection = cristal.includeRay(ray);

        REQUIRE(intersection == 0);
    }

    SECTION("Droite quelconque : intersection")
    {
        Crystal cristal{Point{3., 3.}, 2.5862714475, -72};
        Ray ray{Point{-2.38, -1.62}, 0.4644210041, 373};

        Point * intersection = cristal.includeRay(ray);
        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(5.4969245226, 2.3260801767));
        delete intersection;
    }

    SECTION("Droite verticale : pas d'intersection")
    {
        Crystal cristal{Point{3., 3.}, 2.5862714475, -72};
        Ray ray{Point{-2.38, -1.62}, utilities::PI_2, 373};

        Point * intersection = cristal.includeRay(ray);

        REQUIRE(intersection == 0);
    }

    SECTION("Droite verticale : intersection")
    {
        Crystal cristal{Point{3., 3.}, 2.5862714475, -72};
        Ray ray{Point{1.55, -1.62}, utilities::PI_2, 373};

        Point * intersection = cristal.includeRay(ray);
        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(1.55, 5.1415648484));
        delete intersection;
    }

    SECTION("Droite horizontale : pas d'intersection")
    {
        Crystal cristal{Point{3., 3.}, 2.5862714475, -72};
        Ray ray{Point{-1.62, 5.84}, 0., 373};

        Point * intersection = cristal.includeRay(ray);
        REQUIRE(intersection == 0);
    }

    SECTION("Droite horizontale : pas d'intersection")
    {
        Crystal cristal{Point{3., 3.}, 2.5862714475, -72};
        Ray ray{Point{-1.62, 3.84}, 0., 373};

        Point * intersection = cristal.includeRay(ray);
        REQUIRE(intersection != 0);

        REQUIRE(*intersection == Point(5.4460580533, 3.84));
        delete intersection;
    }
}
