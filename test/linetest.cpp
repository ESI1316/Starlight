#include "test/catch.hpp"

#include "model/geometry/line.hpp"
#include "model/geometry/utilities.hpp"
#include "model/point.hpp"

TEST_CASE("Constructeur")
{
    SECTION("y = 2x + 3")
    {
        Line line{2., 3.};

        REQUIRE(utilities::equals(line.getSlope(), 2.));
        REQUIRE(utilities::equals(line.getIndepTerm(), 3.));
        REQUIRE_FALSE(line.isVertical());
    }

    SECTION("y = -2.18x -99.9")
    {
        Line line{-2.18, -99.9};

        REQUIRE(utilities::equals(line.getSlope(), -2.18));
        REQUIRE(utilities::equals(line.getIndepTerm(), -99.9));
        REQUIRE_FALSE(line.isVertical());
    }

    SECTION("y = 0x + 0.9")
    {
        Line line{0., 0.9};

        REQUIRE(utilities::equals(line.getSlope(), 0.));
        REQUIRE(utilities::equals(line.getIndepTerm(), 0.9));
        REQUIRE_FALSE(line.isVertical());
    }

    SECTION("x = 3")
    {
        Line line{utilities::tan(utilities::PI_2), 0, 3};
        REQUIRE(line.isVertical());
    }

    SECTION("y = -2.3")
    {
        Line line{0., -2.3};
        REQUIRE_FALSE(line.isVertical());
        REQUIRE(utilities::equals(line.getSlope(), 0.));
        REQUIRE(utilities::equals(line.getIndepTerm(), -2.3));
    }

    SECTION("Ligne à partir de deux points : Verticale")
    {
        Line line{Point{3., 2.}, Point{3., 183.}};
        REQUIRE(line.isVertical());
        REQUIRE(utilities::equals(line.getXValue(), 3.));
    }

    SECTION("Ligne à partir de deux points : Horizontale")
    {
        Line line{Point{183., 2.}, Point{3., 2.}};
        REQUIRE_FALSE(line.isVertical());
        REQUIRE(utilities::equals(line.getSlope(), 0.));
        REQUIRE(utilities::equals(line.getIndepTerm(), 2.));
    }
}

TEST_CASE("inclusion d'un point")
{
    SECTION("y = 2x + 3")
    {
        Line line{2., 3.};
        REQUIRE(line.includes(Point{0., 3.}));
        REQUIRE(line.includes(Point{-1., 1.}));
        REQUIRE_FALSE(line.includes(Point{1., 1.}));
    }

    SECTION("y = -2.18x -99.9")
    {
        Line line{-2.18, -99.9};
        REQUIRE(line.includes(Point{0., -99.9}));
        REQUIRE(line.includes(Point{2., -104.26}));
        REQUIRE_FALSE(line.includes(Point{1., 1.}));
    }

    SECTION("y = 0x + 0.9")
    {
        Line line{0., 0.9};
        REQUIRE(line.includes(Point{0., 0.9}));
        REQUIRE(line.includes(Point{1., 0.9}));
        REQUIRE_FALSE(line.includes(Point{1., 1.}));
    }

    SECTION("x = 3")
    {
        Line line{utilities::tan(utilities::PI_2), 0, 3};
        REQUIRE(line.includes(Point{3., 0.9}));
        REQUIRE(line.includes(Point{3., -290.9}));
        REQUIRE_FALSE(line.includes(Point{1., 1.}));
    }

    SECTION("y = -2.3")
    {
        Line line{0., -2.3};
        REQUIRE(line.includes(Point{3., -2.3}));
        REQUIRE(line.includes(Point{-123., -2.3}));
        REQUIRE_FALSE(line.includes(Point{1., 1.}));
    }
}

TEST_CASE("Intersection de droites")
{
    SECTION("Droites paralelles")
    {
        Line a{-3., 18.2};
        Line b{-3., -4.33};
        Point * intersection = 0;

        intersection = a.getIntersectionPoint(b);
        REQUIRE(intersection == 0);
        intersection = b.getIntersectionPoint(a);
        REQUIRE(intersection == 0);
    }

    SECTION("droites confondues")
    {
        Line a{-3., 18.2};
        Line b{-3., 18.2};
        Point * intersection = 0;

        intersection = a.getIntersectionPoint(b);
        REQUIRE(intersection == 0);
        intersection = b.getIntersectionPoint(a);
        REQUIRE(intersection == 0);
    }

    SECTION("droites perpendiculaires")
    {
        Line a{-3., 18.2};
        Line b{3., 18.2};
        Point * intersection = 0;

        intersection = a.getIntersectionPoint(b);
        REQUIRE(*intersection == Point(0., 18.2));
        delete intersection;
        intersection = 0;

        intersection = b.getIntersectionPoint(a);
        REQUIRE(*intersection == Point(0., 18.2));
        delete intersection;
        intersection = 0;
    }

    SECTION("Droites non confondue mais proches")
    {
        Line a{-3., 18.2};
        Line b{-2.9, 18.2};
        Point * intersection = 0;

        intersection = a.getIntersectionPoint(b);
        REQUIRE(*intersection == Point(0., 18.2));
        delete intersection;
        intersection = 0;

        intersection = b.getIntersectionPoint(a);
        REQUIRE(*intersection == Point(0., 18.2));
        delete intersection;
        intersection = 0;
    }

    SECTION("Une droite verticale et une quelconque")
    {
        Line a{utilities::tan(utilities::PI_2), 2, 3};
        Line b{2., 0.};
        Point * intersection = 0;

        intersection = a.getIntersectionPoint(b);
        REQUIRE(*intersection == Point(3., 6.));
        delete intersection;
        intersection = 0;
    }
    SECTION("Une droite quelconque et une droite verticale")
    {
        Line a{2., 0.};
        Line b{utilities::tan(utilities::PI_2), 2, 3};
        Point * intersection = 0;

        intersection = a.getIntersectionPoint(b);
        REQUIRE(*intersection == Point(3., 6.));
        delete intersection;
        intersection = 0;
    }

    SECTION("Droite horizontale et quelconque")
    {
        Line a{0., 8.44};
        Line b{-2.9, 18.2};
        Point * intersection = 0;

        intersection = a.getIntersectionPoint(b);
        REQUIRE(*intersection == Point(3.365517241, 8.44));
        delete intersection;
        intersection = 0;

    }

    SECTION("Droite verticale et horizontale")
    {
        Line a{0., 8.44};
        Line b{utilities::tan(utilities::PI_2),3., 18.2};
        Point * intersection = 0;

        intersection = a.getIntersectionPoint(b);
        REQUIRE(*intersection == Point(18.2, 8.44));
        delete intersection;
        intersection = 0;
    }
}

TEST_CASE("operateurs")
{
        Line a{0., 8.44};
        Line b{0., 8.44};
        Line c{utilities::tan(utilities::PI_2),3., 18.2};


        REQUIRE(a == a);
        REQUIRE(a == b);
        REQUIRE_FALSE(a == c);
        REQUIRE(a != c);
}
