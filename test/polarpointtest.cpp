#include "../test/catch.hpp"
#include "../model/point.hpp"
#include "../model/polarPoint.hpp"
#include "../model/utilities.hpp"

TEST_CASE("Construction de points polaires", "PolarPoint")
{
    PolarPoint p;
    PolarPoint q{0., 2.2};
    PolarPoint r{q};

    REQUIRE(p.getAzimut() == 0.);
    REQUIRE(q.getAzimut() == 2.2);
    REQUIRE(r.getAzimut() == q.getAzimut());
    REQUIRE(p.getRadius() == 0.);
    REQUIRE(q.getRadius() == 0.);
    REQUIRE(r.getRadius() == 0.);

    PolarPoint t{0, 0};
    REQUIRE(t.getAzimutAsDegrees() > -0.0001);
    REQUIRE(t.getAzimutAsDegrees() < 0.0001);

    Point ps;
    PolarPoint s{-2, -2};
    REQUIRE(s.getAzimutAsDegrees() > 245.3000);
    REQUIRE(s.getAzimutAsDegrees() < 245.6000);
}

TEST_CASE("Méthodes")
{


}

TEST_CASE("Construction d'un point cartésien en polaire")
{
    Point p{1., 1.};

    SECTION("Conversion bounds")
    {
        PolarPoint pp(p);

        REQUIRE(pp.getRadius() >= 1.4141);
        REQUIRE(pp.getRadius() <= 1.4143);
        REQUIRE(pp.getAzimut() >= 0.7852);
        REQUIRE(pp.getAzimut() <= 0.7855);
    }
}

TEST_CASE("Conversion de points polaires en cartésien", "PolarPoint")
{
    PolarPoint pp(1.4142, 0.7853);

    REQUIRE(pp.getRadius() >= 1.4141);
    REQUIRE(pp.getRadius() <= 1.4143);
    REQUIRE(pp.getAzimut() >= 0.7852);
    REQUIRE(pp.getAzimut() <= 0.7855);

    SECTION("Conversion bounds")
    {
        Point p = pp.toCartesian();

        REQUIRE(p == Point(1., 1.));
    }
}

TEST_CASE("Méthodes de points polaires")
{

    SECTION("isCenter")
    {
        PolarPoint pp{0., 0.};

        REQUIRE(pp.isCenter());
        REQUIRE(PolarPoint::CARTESIAN_PLAN_ORIGIN.isCenter());
    }
    SECTION("AzimutAsDegre")
    {
        PolarPoint pp{2., 2 * utilities::_M_PI}; // 2 PI radian
        REQUIRE((pp.getAzimutAsDegrees() - 0.) < 0.1);

        pp = PolarPoint{2., 4 * utilities::_M_PI_2}; // Same as 2 PI
        REQUIRE((pp.getAzimutAsDegrees() - 0.) < 0.1);

        pp = PolarPoint{2., utilities::_M_PI / 3}; // PI/3 radian
        REQUIRE((pp.getAzimutAsDegrees() - 60.) < 0.1);

        pp = PolarPoint{2., utilities::_M_PI_2}; // PI/2 radian
        REQUIRE((pp.getAzimutAsDegrees() - 90.) < 0.1);

        pp = PolarPoint{2., 2 * utilities::_M_PI / 3}; // 2 * PI/3 radian
        REQUIRE((pp.getAzimutAsDegrees() - 120.) < 0.1);

        pp = PolarPoint{2., 8 * utilities::_M_PI / 3}; // same as 2 * PI/3 radian
        REQUIRE((pp.getAzimutAsDegrees() - 120.) < 0.1);

        pp = PolarPoint{2., utilities::_M_PI}; // PI radian
        REQUIRE((pp.getAzimutAsDegrees() - 180.) < 0.1);

        pp = PolarPoint{2., -utilities::_M_PI}; //
        REQUIRE((pp.getAzimutAsDegrees() - 180.) < 0.1);

        pp = PolarPoint{2., 3 * utilities::_M_PI_2}; // 3 * PI/2 radian
        REQUIRE((pp.getAzimutAsDegrees() - 270.) < 0.1);
    }

    SECTION("Rotation")
    {
        PolarPoint pp{3., utilities::_M_PI};

        pp.rotate(utilities::_M_PI);
        REQUIRE(pp == PolarPoint(pp.getRadius(), 2 * utilities::_M_PI));

        pp.rotate(utilities::_M_PI);
        REQUIRE(pp == PolarPoint(pp.getRadius(), 3 * utilities::_M_PI));

        pp.rotate(1.4235);
        REQUIRE(pp == PolarPoint(pp.getRadius(), 3 * utilities::_M_PI + 1.4235));

        pp.rotate(-2.3289999);
        REQUIRE(pp == PolarPoint(pp.getRadius(), 3 * utilities::_M_PI + 1.4235 -2.3289999));
    }

    SECTION("Rotation")
    {
        PolarPoint point{2., utilities::_M_PI / 2};
        Point pointCartesien = point.toCartesian();

        PolarPoint centrePoint{3., utilities::_M_PI / 2};
        Point centerPointCartesien = centrePoint.toCartesian();
    }
}
