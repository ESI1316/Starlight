#include "test/catch.hpp"
#include "model/geometry/rectangle.hpp"
#include "model/geometry/line.hpp"
#include "model/starlightexception.hpp"

TEST_CASE("Constructors")
{
    REQUIRE_THROWS_AS(Rectangle(0., 219., Point(0.,0.)), StarlightException);
    REQUIRE_THROWS_AS(Rectangle(139., 0., Point(0.,0.)), StarlightException);
    REQUIRE_THROWS_AS(Rectangle(139., -18.20, Point(0.,0.)), StarlightException);
    REQUIRE_THROWS_AS(Rectangle(-139., 218.20, Point(0.,0.)), StarlightException);

    Rectangle rectangle{139., 219., Point{0.,0.}};

}

TEST_CASE("Get Edge")
{

    Rectangle rectangle{139., 219., Point{2.,0.}};
    std::vector<Line> cotes = rectangle.getEdges();
    REQUIRE(cotes.at(0) == Line(0., 0.));
    REQUIRE(cotes.at(1) == Line(1./0., 0, 2.));
    REQUIRE(cotes.at(2) == Line(0., 0. + 219.));
    REQUIRE(cotes.at(3) == Line(1./0., 0, 2. + 139));
}
