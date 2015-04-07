#include "../test/catch.hpp"
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

        REQUIRE(utilities::equals(pp.getRadius(), 1.41421356));
        REQUIRE(utilities::equals(pp.getAzimut(), 0.785398163));
    }
}

TEST_CASE("Conversion de points polaires en cartésien", "PolarPoint")
{
    PolarPoint pp(1.41421356, 0.785398163);

    REQUIRE(utilities::equals(pp.getRadius(), 1.41421356));
    REQUIRE(utilities::equals(pp.getAzimut(), 0.785398163));

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
        PolarPoint pp{2., 2 * utilities::PI}; // 2 PI radian
        REQUIRE((pp.getAzimutAsDegrees() - 0.) < 0.1);

        pp = PolarPoint{2., 4 * utilities::PI_2}; // Same as 2 PI
        REQUIRE((pp.getAzimutAsDegrees() - 0.) < 0.1);

        pp = PolarPoint{2., utilities::PI / 3}; // PI/3 radian
        REQUIRE((pp.getAzimutAsDegrees() - 60.) < 0.1);

        pp = PolarPoint{2., utilities::PI_2}; // PI/2 radian
        REQUIRE((pp.getAzimutAsDegrees() - 90.) < 0.1);

        pp = PolarPoint{2., 2 * utilities::PI / 3}; // 2 * PI/3 radian
        REQUIRE((pp.getAzimutAsDegrees() - 120.) < 0.1);

        pp = PolarPoint{2., 8 * utilities::PI / 3}; // same as 2 * PI/3 radian
        REQUIRE((pp.getAzimutAsDegrees() - 120.) < 0.1);

        pp = PolarPoint{2., utilities::PI}; // PI radian
        REQUIRE((pp.getAzimutAsDegrees() - 180.) < 0.1);

        pp = PolarPoint{2., -utilities::PI}; //
        REQUIRE((pp.getAzimutAsDegrees() - 180.) < 0.1);

        pp = PolarPoint{2., 3 * utilities::PI_2}; // 3 * PI/2 radian
        REQUIRE((pp.getAzimutAsDegrees() - 270.) < 0.1);
    }

    SECTION("Rotation autour de l'origine")
    {
        PolarPoint pp{3., utilities::PI};

        pp.rotate(utilities::PI);
        REQUIRE(pp == PolarPoint(pp.getRadius(), 2 * utilities::PI));

        pp.rotate(utilities::PI);
        REQUIRE(pp == PolarPoint(pp.getRadius(), 3 * utilities::PI));

        pp.rotate(1.4235);
        REQUIRE(pp == PolarPoint(pp.getRadius(), 3 * utilities::PI + 1.4235));

        pp.rotate(-2.3289999);
        REQUIRE(pp == PolarPoint(pp.getRadius(), 3 * utilities::PI + 1.4235 -2.3289999));
    }

    SECTION("Rotation autour d'un point par PI")
    {
        PolarPoint point{2., utilities::PI / 2};
        PolarPoint centrePoint{3., utilities::PI / 2};

        point.rotateAround(centrePoint, utilities::PI);
        REQUIRE(utilities::equals(point.getRadius(), 4.));
        REQUIRE(utilities::equals(point.getAzimut(), utilities::PI_2));
    }

    SECTION("Rotation autour d'un point")
    {
        PolarPoint point{4.23, 1.1827};
        Point pointCartesien = point.toCartesian();
        REQUIRE(pointCartesien == Point(1.60074622, 3.91541971));

        PolarPoint centrePoint{0.32, 0.32};
        Point centrePointCartesien = centrePoint.toCartesian();
        REQUIRE(centrePointCartesien == Point(0.303755334, 0.100661299));

        SECTION("translation des points")
        {
            pointCartesien.setX(pointCartesien.getX() - centrePointCartesien.getX());
            pointCartesien.setY(pointCartesien.getY() - centrePointCartesien.getY());
            REQUIRE(pointCartesien == Point(1.296990886, 3.814758411));
        }

        PolarPoint translate{pointCartesien};
        translate.rotate(-0.14);
        pointCartesien = translate.toCartesian();

        SECTION("Détranslation du point")
        {
            pointCartesien.setX(pointCartesien.getX() + centrePointCartesien.getX());
            pointCartesien.setY(pointCartesien.getY() + centrePointCartesien.getY());
            /* OK PRECISION */
            // REQUIRE(pointCartesien == Point(2.435213484, 3.754399179));
        }
    }
}
