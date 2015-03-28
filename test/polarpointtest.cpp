#include "catch.hpp"
#include "../model/point.hpp"
#include "../model/polarPoint.hpp"

TEST_CASE("Construct some polar points", "PolarPoint")
{
    PolarPoint p;
    PolarPoint q{0., 2.2};
    PolarPoint r{q};

    REQUIRE(p.getAzimut() == 0.);
    REQUIRE(q.getAzimut() == 2.2);
    REQUIRE(r.getAzimut() == q.getAzimut());

    SECTION("exotics polar points")
    {
        Point ps;

        PolarPoint s{-2, -2};
        REQUIRE(s.getAzimutAsDegrees() < -114.4000);
        REQUIRE(s.getAzimutAsDegrees() > -114.7000);

        ps = s.toCartesian();
        REQUIRE(ps.getX() == 1);
        REQUIRE(ps.getY() == 2);

        PolarPoint t{0, 0};
        REQUIRE(t.getAzimutAsDegrees() > -0.0001);
        REQUIRE(t.getAzimutAsDegrees() < 0.0001);

        ps = t.toCartesian();
        REQUIRE(ps.getX() == 0);
        REQUIRE(ps.getY() == 0);
    }
}

TEST_CASE("Converting a cartesian point to a polar one ", "PolarPoint")
{
    Point p(1,1);

    REQUIRE(p.getX() == 1 );
    REQUIRE(p.getY() == 1 );

    SECTION("Conversion bounds")
    {
        PolarPoint pp(p);

        REQUIRE(pp.getRadius() >= 1.4141);
        REQUIRE(pp.getRadius() <= 1.4143);
        REQUIRE(pp.getAzimut() >= 0.7852);
        REQUIRE(pp.getAzimut() <= 0.7855);
    }
}

TEST_CASE("Converting a polar point to a cartesian one ", "PolarPoint")
{
    PolarPoint pp(1.4142, 0.7853);

    REQUIRE(pp.getRadius() >= 1.4141);
    REQUIRE(pp.getRadius() <= 1.4143);
    REQUIRE(pp.getAzimut() >= 0.7852);
    REQUIRE(pp.getAzimut() <= 0.7855);

    SECTION("Conversion bounds")
    {
        Point p = pp.toCartesian();

        REQUIRE(p.getX() == 1);
        REQUIRE(p.getY() == 1);
    }
}
