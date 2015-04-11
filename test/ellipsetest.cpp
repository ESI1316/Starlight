#include "test/catch.hpp"

#include "model/geometry/ellipse.hpp"
#include "model/geometry/line.hpp"
#include "model/starlightexception.hpp"

TEST_CASE("Constructeur d'ellipse")
{
    REQUIRE_NOTHROW(Ellipse(0.96, 2.8091279786, Point(5.22, 3.)));
    REQUIRE_THROWS_AS(Ellipse(-0.96, 2.8091279786, Point(5.22, 3.)), StarlightException);
    REQUIRE_THROWS_AS(Ellipse(0.96, -2.8091279786, Point(5.22, 3.)), StarlightException);
    REQUIRE_THROWS_AS(Ellipse(0., -2.8091279786, Point(5.22, 3.)), StarlightException);
}

TEST_CASE("Accesseurs d'ellipse")
{
    Ellipse ellipse{2.8091279786 / 2., 1.92 / 2., Point{2., 2.}};
    REQUIRE(ellipse.getCenter() == Point(2., 2.));
    REQUIRE(utilities::equals(ellipse.getXRadius(), pow(2.8091279786 / 2., 2)));
    REQUIRE(utilities::equals(ellipse.getYRadius(), pow(1.92 / 2., 2)));
}

TEST_CASE("Operateurs d'ellipse")
{
    Ellipse ellipse{0.96, 2.8091279786, Point{5.22, 3.}};
    Ellipse ellip{0.96, 2.8091279786, Point{5.22, 3.}};
    Ellipse ell{0.26, 2.8091279786, Point{5.22, 3.}};
    Ellipse e{0.26, 2.8091279786, Point{185.22, 23.}};

    REQUIRE(ellipse == ellip);
    REQUIRE(ellipse != ell);
    REQUIRE(!(ellipse == ell));
    REQUIRE(e != ell);
}

TEST_CASE("Intersection Cercle - droite quelconque")
{
    Ellipse ellipse{2., 2., Point{2., 2.}};
    Line line{0.1661237785, 1.1469953742};
    std::vector<Point> intersections = ellipse.getIntersectionPoints(line);

    REQUIRE_FALSE(intersections.empty());
    REQUIRE(intersections.at(0) == Point(0.177420274, 1.1764691005));
    REQUIRE(intersections.at(1) == Point(3.9909533641, 1.8099876269));
}

TEST_CASE("Get points d'intersection")
{
    Ellipse ellipse{30., 15., Point{6., 6.}};
    Line line{0.4648121218, -3.0278181727};
    std::vector<Point> intersections = ellipse.getIntersectionPoints(line);

    REQUIRE_FALSE(intersections.empty());
    REQUIRE(intersections.at(0) == Point(-8.7055673231, -7.0742713918));
    REQUIRE(intersections.at(1) == Point(33.1503073662, 12.3808465332));
}

TEST_CASE("Get points d'intersection - Droite horizontale")
{
    Ellipse ellipse{30., 15., Point{6., 6.}};
    Line line{0, 14.6315900304};
    std::vector<Point> intersections = ellipse.getIntersectionPoints(line);

    REQUIRE_FALSE(intersections.empty());
    REQUIRE(intersections.at(0) == Point(-18.5353339938, 14.6315900304));
    REQUIRE(intersections.at(1) == Point(30.5353339938, 14.6315900304));
}

TEST_CASE("Get points d'intersection - Droite verticale")
{
    Ellipse ellipse{30., 15., Point{6., 6.}};
    Line line{1./0., 0., 21.8523956411};
    std::vector<Point> intersections = ellipse.getIntersectionPoints(line);

    REQUIRE_FALSE(intersections.empty());
    REQUIRE(intersections.at(0) == Point(21.8523956411, -6.7348100932));
    REQUIRE(intersections.at(1) == Point(21.8523956411, 18.7348100932));
}

TEST_CASE("Pas d'intersection")
{
    Ellipse ellipse{30., 15., Point{6., 6.}};

    SECTION("quelconque")
    {
        Line line{0.6112412178, -23.9357930877};
        std::vector<Point> intersections = ellipse.getIntersectionPoints(line);

        REQUIRE(intersections.empty());
    }

    SECTION("horizontales")
    {
        Line line{0., -13.7384156087};
        std::vector<Point> intersections = ellipse.getIntersectionPoints(line);

        REQUIRE(intersections.empty());
    }

    SECTION("Verticales")
    {
        Line line{1./0., 0., 48.4261720081};
        std::vector<Point> intersections = ellipse.getIntersectionPoints(line);

        REQUIRE(intersections.empty());
    }
}

TEST_CASE("Droites tangeantes à l'ellipse")
{
    Ellipse ellipse{30., 15., Point{6., 6.}};
    // (x + 6)² / 30² + (y + 6)² / 15² = 1

    SECTION("quelconque")
    {
        Line line{-0.5128962807, 30.5658940414};
        std::vector<Point> intersections = ellipse.getIntersectionPoints(line);

        REQUIRE_FALSE(intersections.empty());
    }

    SECTION("Verticale")
    {
        Line line{1./0., 0., -24.};
        std::vector<Point> intersections = ellipse.getIntersectionPoints(line);

        REQUIRE_FALSE(intersections.empty());
    }

    SECTION("Horizontale")
    {
        Line line{0., 21.};
        // y = 21
        std::vector<Point> intersections = ellipse.getIntersectionPoints(line);

        REQUIRE_FALSE(intersections.empty());
    }
}
