#include "test/catch.hpp"
#include "model/geometry/rectangle.hpp"
#include "model/geometry/line.hpp"
#include "model/geometry/utilities.hpp"
#include "model/exception/starlightexception.hpp"

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

TEST_CASE("Sur le bord du rectangle")
{
    Rectangle rectangle{139.22, 219.344, Point{55., 18.4}};

    REQUIRE_FALSE(rectangle.isOnBorder(Point(55., 18.3)));
    REQUIRE(rectangle.isOnBorder(Point(55., 18.4)));
    REQUIRE(rectangle.isOnBorder(Point(55., 19.4)));
    REQUIRE(rectangle.isOnBorder(Point(55., 219.9)));
    REQUIRE(rectangle.isOnBorder(Point(55., 219.344 + 18.4)));
    REQUIRE_FALSE(rectangle.isOnBorder(Point(55., 219.344 + 18.5)));

    REQUIRE_FALSE(rectangle.isOnBorder(Point(54.9, 18.4)));
    REQUIRE(rectangle.isOnBorder(Point(55., 18.4)));
    REQUIRE(rectangle.isOnBorder(Point(148., 18.4)));
    REQUIRE(rectangle.isOnBorder(Point(182.2, 18.4)));
    REQUIRE(rectangle.isOnBorder(Point(139.22 + 55, 18.4)));
    REQUIRE_FALSE(rectangle.isOnBorder(Point(139.23 + 55, 18.4)));

    REQUIRE_FALSE(rectangle.isOnBorder(Point(54.9, 219.344 + 18.4)));
    REQUIRE(rectangle.isOnBorder(Point(56., 219.344 + 18.4)));
    REQUIRE(rectangle.isOnBorder(Point(56., 219.344 + 18.4)));
    REQUIRE(rectangle.isOnBorder(Point(72.4, 219.344 + 18.4)));
    REQUIRE(rectangle.isOnBorder(Point(139.22 + 55, 219.344 + 18.4)));
    REQUIRE_FALSE(rectangle.isOnBorder(Point(139.22 + 55.1, 219.344 + 18.4)));

    REQUIRE_FALSE(rectangle.isOnBorder(Point(139.22 + 55, 18.3)));
    REQUIRE(rectangle.isOnBorder(Point(139.22 + 55, 18.5)));
    REQUIRE(rectangle.isOnBorder(Point(139.22 + 55, 19.5)));
    REQUIRE(rectangle.isOnBorder(Point(139.22 + 55, 20.5)));
    REQUIRE(rectangle.isOnBorder(Point(139.22 + 55, 219.344 + 18.4)));
    REQUIRE_FALSE(rectangle.isOnBorder(Point(139.22 + 55, 219.344 + 18.5)));

    REQUIRE_FALSE(rectangle.isOnBorder(Point(60, 20)));
    REQUIRE_FALSE(rectangle.isOnBorder(Point(55 + 109.22, 18.4 + 200.00)));
}

TEST_CASE("Intersection Rectangle droite quelconque")
{
    Rectangle rectangle{4.424, 4.424, Point{2., 2.}};
    REQUIRE(rectangle.isOnBorder(Point(2, 2.982605698)));
    REQUIRE(rectangle.isOnBorder(Point(6.424, 4.1673806268)));

    Line line{0.2678062678, 2.4469931624};

    std::vector<Point> intersections;
    REQUIRE(intersections.size() == 0);
    intersections = rectangle.getIntersectionPoints(line);
    REQUIRE(intersections.size() == 2);
    REQUIRE(intersections.at(0) == Point(2, 2.982605698));
    REQUIRE(intersections.at(1) == Point(6.424, 4.1673806268));
}

TEST_CASE("Intersection Rectangle droite horizontale")
{
    Rectangle rectangle{4.424, 4.424, Point{2., 2.}};
    REQUIRE(rectangle.isOnBorder(Point(2, 5.382)));
    REQUIRE(rectangle.isOnBorder(Point(6.424, 5.382)));

    Line line{0., 5.382};
    std::vector<Point> intersections;
    REQUIRE(intersections.size() == 0);
    intersections = rectangle.getIntersectionPoints(line);
    REQUIRE(intersections.size() == 2);
    REQUIRE(intersections.at(0) == Point(2, 5.382));
    REQUIRE(intersections.at(1) == Point(6.424, 5.382));
}

TEST_CASE("Intersection Rectangle droite verticale")
{
    Rectangle rectangle{4.424, 4.424, Point{2., 2.}};
    REQUIRE(rectangle.isOnBorder(Point(3.8104, 6.424)));
    REQUIRE(rectangle.isOnBorder(Point(3.8104, 2)));

    Line line{1./0., 0., 3.8104};
    std::vector<Point> intersections;
    REQUIRE(intersections.size() == 0);
    intersections = rectangle.getIntersectionPoints(line);
    REQUIRE(intersections.size() == 2);
    REQUIRE(intersections.at(0) == Point(3.8104, 2));
    REQUIRE(intersections.at(1) == Point(3.8104, 6.424));
}

TEST_CASE("Droites confondues avec les cotés")
{
    Rectangle rectangle{4.424, 4.424, Point{2., 2.}};
    std::vector<Line> borders = rectangle.getEdges();

    std::vector<Point> bottom = rectangle.getIntersectionPoints(borders.at(0));
    std::vector<Point> left = rectangle.getIntersectionPoints(borders.at(1));
    std::vector<Point> top = rectangle.getIntersectionPoints(borders.at(2));
    std::vector<Point> right = rectangle.getIntersectionPoints(borders.at(3));

    REQUIRE(top.at(0) == Point(2, 6.424));
    REQUIRE(top.at(1) == Point(6.424, 6.424));

    REQUIRE(left.at(0) == Point(2., 2.));
    REQUIRE(left.at(1) == Point(2, 6.424));

    REQUIRE(bottom.at(0) == Point(2., 2.));
    REQUIRE(bottom.at(1) == Point(6.424, 2));

    REQUIRE(right.at(0) == Point(6.424, 2));
    REQUIRE(right.at(1) == Point(6.424, 6.424));
}

