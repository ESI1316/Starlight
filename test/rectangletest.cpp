#include "test/catch.hpp"
#include "model/geometry/rectangle.hpp"
#include "model/geometry/line.hpp"
#include "model/starlightexception.hpp"

TEST_CASE("Rectangle Constructors")
{
    REQUIRE_THROWS_AS(Rectangle(0., 219., Point(0.,0.)), StarlightException);
    REQUIRE_THROWS_AS(Rectangle(139., 0., Point(0.,0.)), StarlightException);
    REQUIRE_THROWS_AS(Rectangle(139., -18.20, Point(0.,0.)), StarlightException);
    REQUIRE_THROWS_AS(Rectangle(-139., 218.20, Point(0.,0.)), StarlightException);

    Rectangle rectangle{139., 219., Point{0.,0.}};

}

TEST_CASE("Rectangle Cotés")
{
    Rectangle rectangle{139., 219., Point{2.,0.}};
    std::vector<Line> cotes = rectangle.getEdges();
    REQUIRE(cotes.at(0) == Line(0., 0.));
    REQUIRE(cotes.at(1) == Line(1./0., 0, 2.));
    REQUIRE(cotes.at(2) == Line(0., 219.));
    REQUIRE(cotes.at(3) == Line(1./0., 0, 141.));
}

TEST_CASE("Rectangle Accesseurs")
{
    Rectangle rectangle{139., 219., Point{2.,0.}};

    REQUIRE(utilities::equals(rectangle.getWidth(), 139.));
    REQUIRE(utilities::equals(rectangle.getHeight(), 219.));
    REQUIRE(rectangle.getUpLeftCorner() == Point(2., 0.));
}

TEST_CASE("Rectangle operateurs")
{
    Rectangle rectangle{139.22, 219.344, Point{55., 18.4}};
    Rectangle rectan{139.22, 219.344, Point{55., 18.4}};
    Rectangle rect{139.22, 29.344, Point{55., 18.4}};
    Rectangle re{39.22, 29., Point{5., 18.4}};

    REQUIRE(rectangle == rectan);
    REQUIRE(rectangle != rect);
    REQUIRE(rectangle != re);

    REQUIRE(rectan == rectangle);
    REQUIRE(rectan != rect);
    REQUIRE(rectan != re);

    REQUIRE(rect != rectangle);
    REQUIRE(rect != rectan);
    REQUIRE(rect != re);
}
