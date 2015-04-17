#include "test/catch.hpp"

#include "model/elements/lens.hpp"
#include "model/elements/ray.hpp"
#include "model/exception/starlightexception.hpp"
#include "model/geometry/utilities.hpp"

TEST_CASE("Lentille : constructeurs")
{

    REQUIRE_NOTHROW(Lens(Point(4, 5), 7, 4, 400, 500));
    REQUIRE_NOTHROW(Lens(Point(184, 22.5), 8, 4, 410, 500));
    REQUIRE_THROWS_AS(Lens(Point(184, 22.5), 8, 4, 300, 500), StarlightException);
    REQUIRE_THROWS_AS(Lens(Point(184, 22.5), 8, 4, 410, 405), StarlightException);
    REQUIRE_THROWS_AS(Lens(Point(184, 22.5), 0, 4, 410, 415), StarlightException);
    REQUIRE_THROWS_AS(Lens(Point(184, 22.5), 3, -1, 410, 415), StarlightException);
    REQUIRE_THROWS_AS(Lens(Point(184, 22.5), 8, 4, 400, 1500), StarlightException);
}

TEST_CASE("Lentille : accesseurs")
{
    Lens lens{Point{4, 5}, 7, 4, 400, 500};
    REQUIRE(lens.getCenter() == Point(7.5, 7));
    REQUIRE(lens.getPosition() == Point(4., 5.));
    REQUIRE(lens.getMinWaveLength() == 400);
    REQUIRE(lens.getMaxWaveLength() == 500);
}

TEST_CASE("Lentille : react to ray")
{
    Lens lens{Point{4, 5}, 7, 4, 400, 500};

    SECTION("OK")
    {
        Ray ray(Point(2,2), -0.5880026035, 450);
        Point * intersection{lens.includeRay(ray)};
        REQUIRE(intersection != nullptr);
        delete intersection;
        REQUIRE(ray.getWaveLength() >= lens.getMinWaveLength());
        REQUIRE(ray.getWaveLength() <= lens.getMaxWaveLength());
    }

    SECTION("NOK")
    {
        Ray ray(Point(2,2), -0.5880026035, 370);
        Point * intersection{lens.includeRay(ray)};
        REQUIRE(intersection != nullptr);
        delete intersection;
        REQUIRE_FALSE(ray.getWaveLength() >= lens.getMinWaveLength());
    }
}
