#include "test/catch.hpp"

#include "model/geometry/ellipse.hpp"
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
    Ellipse ellipse{0.96, 2.8091279786, Point{5.22, 3.}};
    REQUIRE(ellipse.getCenter() = Point(5.22, 3.));
    REQUIRE(utilities::equals(ellipse.getXRadius(), 0.96));
    REQUIRE(utilities::equals(ellipse.getYRadius(), 2.8091279786));
}

TEST_CASE("Operateurs d'ellipse")
{
    Ellipse ellipse{0.96, 2.8091279786, Point{5.22, 3.}};
    Ellipse ellip{0.96, 2.8091279786, Point{5.22, 3.}};
    Ellipse ell{0.26, 2.8091279786, Point{5.22, 3.}};
    Ellipse e{0.26, 2.8091279786, Point{185.22, 23.}};

    REQUIRE(ellipse == ellip);
    REQUIRE(ellipse != ell);
    REQUIRE(!ellipse == ell);
    REQUIRE(e != ell);
}

TEST_CASE("Get x de l'intersection")
{

}

TEST_CASE("Get y de l'intersection")
{

}

TEST_CASE("Get points d'intersection")
{

}
