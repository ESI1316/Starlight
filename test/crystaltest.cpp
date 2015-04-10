#include "test/catch.hpp"
#include "model/starlightexception.hpp"
#include "model/crystal.hpp"
#include "model/ray.hpp"

TEST_CASE("Constructions de cristals")
{
    REQUIRE_THROWS_AS(Crystal(Point(1., 1.), -2., -181), StarlightException);

    Crystal cristal{Point{0.,0.}, 2., 100};
    REQUIRE(cristal.getCenter() == Point(0., 0.));
    REQUIRE(utilities::equals(cristal.getRadius(), 2.));
    REQUIRE(utilities::equals(cristal.getAmplifier(), 100));

}

TEST_CASE("reaction au rayon")
{
    Crystal cristal{Point{0.,0.}, 2., 100};
    Ray ray{Point{2., 2.}, (utilities::PI / 3), 500};

    cristal.reactToRay(ray);
    REQUIRE(ray.getWaveLength() == 600);
}

TEST_CASE("Intersection cristal et rayon")
{
}
