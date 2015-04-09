#include "../test/catch.hpp"
#include "./model/line.hpp"

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
        Line line{1./0., 0, 3};
        REQUIRE(line.isVertical());
    }

    SECTION("y = -2.3")
    {
        Line line{0., -2.3};
        REQUIRE_FALSE(line.isVertical());
        REQUIRE(utilities::equals(line.getSlope(), 0.));
        REQUIRE(utilities::equals(line.getIndepTerm(), -2.3));
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
        Line line{1./0., 0, 3};
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

        intersection = 0;

        intersection = b.getIntersectionPoint(a);
        REQUIRE(*intersection == Point(0., 18.2));
    }

    SECTION("Droites non confondue mais proches")
    {
        Line a{-3., 18.2};
        Line b{-2.9, 18.2};
        Point * intersection = 0;

        intersection = a.getIntersectionPoint(b);
        REQUIRE(*intersection == Point(0., 18.2));

        intersection = 0;

        intersection = b.getIntersectionPoint(a);
        REQUIRE(*intersection == Point(0., 18.2));
    }

    SECTION("Une droite verticale et une quelconque")
    {
        Line a{1./0., 2, 3};
        Line b{2., 0.};
        Point * intersection = 0;

        intersection = a.getIntersectionPoint(b);
        REQUIRE(*intersection == Point(3., 6.));
    }
    SECTION("Une droite quelconque et une droite verticale")
    {
        Line a{2., 0.};
        Line b{1./0., 2, 3};
        Point * intersection = 0;

        intersection = a.getIntersectionPoint(b);
        REQUIRE(*intersection == Point(3., 6.));
    }
}
