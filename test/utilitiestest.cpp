#include "test/catch.hpp"
#include "model/geometry/utilities.hpp"

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
