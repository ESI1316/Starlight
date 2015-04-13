#include "test/catch.hpp"
#include "model/dest.hpp"
#include "model/geometry/rectangle.hpp"
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
