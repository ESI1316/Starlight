#include "test/catch.hpp"
#include "model/geometry/utilities.hpp"

TEST_CASE("egalité de doubles avec un Epsilon = 10^-7")
{
    REQUIRE(utilities::equals(2., 2.));
    REQUIRE(utilities::equals(2.1, 2.1));
    REQUIRE(utilities::equals(2.22, 2.22));
    REQUIRE(utilities::equals(2.333, 2.333));
    REQUIRE(utilities::equals(2.4444, 2.4444));
    REQUIRE(utilities::equals(2.55555, 2.55555));
    REQUIRE(utilities::equals(2.666666, 2.666666));
    REQUIRE(utilities::equals(2.7777772, 2.7777777));

    REQUIRE_FALSE(utilities::equals(2., 3.));
    REQUIRE_FALSE(utilities::equals(2.1, 2.2));
    REQUIRE_FALSE(utilities::equals(2.32, 2.22));
    REQUIRE_FALSE(utilities::equals(2.353, 2.333));
    REQUIRE_FALSE(utilities::equals(2.4484, 2.4444));
    REQUIRE_FALSE(utilities::equals(2.52555, 2.55555));
    REQUIRE_FALSE(utilities::equals(2.666616, 2.666666));

    REQUIRE(utilities::equals(0.0000001, 0));
    REQUIRE(utilities::equals(-0.0000001, 0));

    REQUIRE(utilities::equals(1./0., 2./0.));
    REQUIRE_FALSE(utilities::equals(1./0., 1.));
}

TEST_CASE("PI/2 + n * PI")
{
    REQUIRE(utilities::isHalfPiPlusNPi(utilities::PI_2));
    REQUIRE(utilities::isHalfPiPlusNPi(3 * utilities::PI_2));
    REQUIRE(utilities::isHalfPiPlusNPi(-utilities::PI_2));

    for(int i = -5; i < 10; i++)
        REQUIRE(utilities::isHalfPiPlusNPi(utilities::PI_2 + (i * utilities::PI)));
}

TEST_CASE("Tangante")
{
    REQUIRE(std::isinf(utilities::tan(utilities::PI_2)));
    REQUIRE(utilities::equals(utilities::tan(3.33328), std::tan(3.33328)));
}

TEST_CASE("Angle absolu")
{
    REQUIRE(utilities::equals(
                utilities::absoluteAngle(utilities::PI),
                utilities::PI));

    REQUIRE(utilities::equals(
                utilities::absoluteAngle(utilities::PI * 2.),
                0.));

    REQUIRE(utilities::equals(
                utilities::absoluteAngle(utilities::PI_2),
                utilities::PI_2));

    REQUIRE(utilities::equals(
                utilities::absoluteAngle(-utilities::PI * 3.),
                utilities::PI));

    REQUIRE(utilities::equals(
                utilities::absoluteAngle((-utilities::PI / 3.) * 7),
                utilities::PI / 3));

    REQUIRE(utilities::equals(
                utilities::absoluteAngle((4. / 3.) * utilities::PI),
                (2. / 3.) * utilities::PI));
}
