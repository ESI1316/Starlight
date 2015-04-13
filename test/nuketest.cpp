#include "test/catch.hpp"
#include "model/nuke.hpp"
#include "model/starlightexception.hpp"

TEST_CASE("construction")
{
    REQUIRE_NOTHROW(Nuke(Point(4., 3.), 7.));
    REQUIRE_THROWS_AS(Nuke(Point(2., 11.), -1000), StarlightException);
}

TEST_CASE("accesseurs et mutateurs")
{
    Nuke duke(Nuke(Point(4., 3.), 10.));

    REQUIRE(duke.getRadius() == 10.);
    REQUIRE(duke.getLocation() == Point(4., 3.));
    REQUIRE(duke.isLightedUp() == false);
    duke.setLightedUp(true);
    REQUIRE(duke.isLightedUp() == true);
}

TEST_CASE("ReactToRay(Ray)")
{
    Nuke duke(Nuke(Point(4., 3.), 10.));
    // je sais pas comment créer un ray :(
}

TEST_CASE("includeRay(const Ray &)")
{

}
