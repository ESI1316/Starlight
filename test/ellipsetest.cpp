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

TEST_CASE("Get points d'intersection")
{
    Ellipse ellipse{2.8091279786 / 2., 1.92 / 2., Point{2., 2.}};
    Line line{0.2682926829, 0.9697560976};
    std::vector<Point> intersections = ellipse.getIntersectionPoints(line);

    REQUIRE_FALSE(intersections.empty());
    REQUIRE(intersections.at(0) == Point(0.68087158, 1.1524289605));
    REQUIRE(intersections.at(1) == Point(4.7223754929, 2.2367348883));
}
