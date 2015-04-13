#include "test/catch.hpp"
#include "model/nuke.hpp"
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

TEST_CASE("ReactToRay(Ray)")
{
    Nuke duke(Nuke(Point(4., 3.), 10.));
    // je sais pas comment créer un ray :(
    // Ray ray(point de depart, angle de tir, wavelenght)
    // tu créer une droite sur geogebra, tu utilises l'outils pour trouver l'angle (en radian)
    // de l'intersection avec l'axe des x
}

TEST_CASE("includeRay(const Ray &)")
{

}
