/*
#include "test/catch.hpp"
#include "model/geometry/utilities.hpp"
#include "model/geometry/point.hpp"

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

    REQUIRE(utilities::equals(utilities::INF, 2./0.));
    REQUIRE_FALSE(utilities::equals(utilities::INF, 1.));
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
    REQUIRE(utilities::equals(utilities::tan(3.33328), -std::tan(3.33328)));
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
    REQUIRE(utilities::equals(utilities::absoluteAngle(-2.), 2.));
    REQUIRE(utilities::equals(utilities::absoluteAngle(4.), (2 * utilities::PI) - 4.));
    REQUIRE(utilities::equals(utilities::absoluteAngle(0.), 0.));
    REQUIRE(utilities::equals(utilities::absoluteAngle(7.), (7. - (2 * utilities::PI))));
    REQUIRE(utilities::equals(utilities::absoluteAngle(-7.), (7. - (2 * utilities::PI))));
}

TEST_CASE("Angle en degrés")
{
    REQUIRE(utilities::equals(utilities::angleAsDegree(0.), 0.));
    REQUIRE(utilities::equals(utilities::angleAsDegree(utilities::PI_2), 90.));
    REQUIRE(utilities::equals(utilities::angleAsDegree(utilities::PI), 180.));
    REQUIRE(utilities::equals(utilities::angleAsDegree(3 * utilities::PI_2), 270.));
    REQUIRE(utilities::equals(utilities::angleAsDegree(2 * utilities::PI), 360.));
    REQUIRE(utilities::equals(utilities::angleAsDegree(-0.), 0.));
    REQUIRE(utilities::equals(utilities::angleAsDegree(-utilities::PI_2), -90.));
    REQUIRE(utilities::equals(utilities::angleAsDegree(-utilities::PI), -180.));
    REQUIRE(utilities::equals(utilities::angleAsDegree(-(3 * utilities::PI_2)), -270.));
    REQUIRE(utilities::equals(utilities::angleAsDegree(-(2 * utilities::PI)), -360.));

    REQUIRE(utilities::equals(utilities::angleAsDegree(5 * utilities::PI_2), 450.));
    REQUIRE(utilities::equals(utilities::angleAsDegree(-5 * utilities::PI_2), -450.));
}

TEST_CASE("Angle en degré [0, 360[")
{
    REQUIRE(utilities::equals(utilities::angleAsDegree0to360(0.), 0.));
    REQUIRE(utilities::equals(utilities::angleAsDegree0to360(utilities::PI_2), 90.));
    REQUIRE(utilities::equals(utilities::angleAsDegree0to360(utilities::PI), 180.));
    REQUIRE(utilities::equals(utilities::angleAsDegree0to360(3 * utilities::PI_2), 270.));
    REQUIRE(utilities::equals(utilities::angleAsDegree0to360(2 * utilities::PI), 0.));
    REQUIRE(utilities::equals(utilities::angleAsDegree0to360(-0.), 0.));
    REQUIRE(utilities::equals(utilities::angleAsDegree0to360(-utilities::PI_2), 270.));
    REQUIRE(utilities::equals(utilities::angleAsDegree0to360(-utilities::PI), 180.));
    REQUIRE(utilities::equals(utilities::angleAsDegree0to360(-(3 * utilities::PI_2)), 90.));
    REQUIRE(utilities::equals(utilities::angleAsDegree0to360(-(2 * utilities::PI)), 0.));

    REQUIRE(utilities::equals(utilities::angleAsDegree0to360(5 * utilities::PI_2), 90.));
    REQUIRE(utilities::equals(utilities::angleAsDegree0to360(-5 * utilities::PI_2), 270.));
}

TEST_CASE("Coefficiant angulaire avec deux points")
{
    REQUIRE(utilities::equals(utilities::slopeFromPoints(Point(1., 1.), Point(2., 2.)),
                              1.));
    REQUIRE(utilities::equals(utilities::slopeFromPoints(Point(4.4288912019, 0.9901542708),
                                                         Point(5.7910970369, 2.4594998906)),
                              1.0786516854));
    REQUIRE(std::isinf(utilities::slopeFromPoints(Point(-1.4025742268, 5.1686058772),
                                                         Point(-1.4025742268, 2.6584737766))
                              ));
    REQUIRE(utilities::equals(utilities::slopeFromPoints(Point(0.6789987347, 4.6176012697),
                                                         Point(3.5105501895, 4.6176012697)),
                              0.));
}

TEST_CASE("Entre 0 et 2PI")
{
    REQUIRE(utilities::inZeroTwoPi(0.) == 0.);
    REQUIRE(utilities::inZeroTwoPi(utilities::PI_2) == utilities::PI_2);
}
*/
