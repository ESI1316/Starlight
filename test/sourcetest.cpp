#include "test/catch.hpp"

#include "model/source.hpp"
#include "model/point.hpp"
#include "model/starlightexception.hpp"
#include "model/geometry/utilities.hpp"

TEST_CASE("Source : constructeur")
{
    REQUIRE_THROWS_AS(Source(Point(2., 2.), 4, utilities::PI_4, 359), StarlightException);
    REQUIRE_THROWS_AS(Source(Point(2., 2.), 4, utilities::PI_4, 831), StarlightException);
    REQUIRE_THROWS_AS(Source(Point(2., 2.), -1, utilities::PI_4, 831), StarlightException);
    REQUIRE_THROWS_AS(Source(Point(2., 2.), 0, utilities::PI_4, 831), StarlightException);
    REQUIRE_NOTHROW(Source(Point(2., 2.), 4, utilities::PI_4, 700));
}

TEST_CASE("Source : accesseurs")
{
    Source source{Point{2., 2.}, 4, utilities::PI_4, 700};
    Source sour{Point{2., 2.}, 4, utilities::PI_4, 700};
    Source so{Point{3., 2.}, 4, utilities::PI_4, 700};
    Source s{Point{2., 2.}, 4, utilities::PI_2, 700};

    REQUIRE(source.getUpLeftCorner() == Point(2., 2.));
    REQUIRE(utilities::equals(source.getAngle(), utilities::PI_4));
    REQUIRE(source.getEdge() == 4);
    REQUIRE(source.getWaveLength() == 700);
    REQUIRE_FALSE(source.isOn());
    source.setOn(true);
    REQUIRE(source.isOn());

    REQUIRE(source != sour);
    source.setOn(false);
    REQUIRE(source == sour);
    REQUIRE(source != so);
    REQUIRE_FALSE(sour == s);
    REQUIRE(so != s);
}

TEST_CASE("Source : est un rectangle")
{
    Source source{Point{2., 2.}, 4, utilities::PI_4, 700};
    REQUIRE(utilities::equals(source.getWidth(), source.getEdge()));
    REQUIRE(utilities::equals(source.getHeight(), source.getEdge()));
}
