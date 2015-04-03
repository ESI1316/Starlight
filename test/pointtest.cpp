#include "../test/catch.hpp"
#include "../model/point.hpp"
#include "../model/utilities.hpp"

TEST_CASE("Construction de points")
{

    Point p{2., 2.};
    REQUIRE(p.getX() == 2.);
    REQUIRE(p.getY() == 2.);

    Point pp{p};
    REQUIRE(pp.getX() == 2.);
    REQUIRE(pp.getY() == 2.);

    Point ppp(2, 99);
    REQUIRE(ppp.getX() == 2.);
    REQUIRE(ppp.getY() == 99.);


}

TEST_CASE("Ascesseurs de point")
{
    Point pp{2., 2.};
    pp.setX(-18.3);
    REQUIRE(pp.getX() == -18.3);
    REQUIRE(pp.getY() == 2.);

    pp.setY(utilities::_M_PI);
    REQUIRE(pp.getX() == -18.3);
    REQUIRE(pp.getY() == utilities::_M_PI);

    pp.setLocation(4.28, 8.10);
    REQUIRE(pp.getX() == 4.28);
    REQUIRE(pp.getY() == 8.10);
}

TEST_CASE("Autres méthodes de points")
{

    Point a{2., 2.};
    Point b{4., 4.};
    Point c{0., 0.};
    Point d{-4., 18.3};
    Point e{-3.33, -1.8};
    Point f{88.22, -190};

    REQUIRE((a.distanceFrom(b) - b.distanceFrom(a)) < 0.1);
    REQUIRE((a.distanceFrom(c) - c.distanceFrom(a)) < 0.1);
    REQUIRE((a.distanceFrom(d) - d.distanceFrom(a)) < 0.1);

    REQUIRE((a.distanceFrom(b) - std::sqrt(8)) < 0.1);
    REQUIRE((a.distanceFrom(c) - std::sqrt(8)) < 0.1);
    REQUIRE((a.distanceFrom(d) - std::sqrt(301.69)) < 0.1);
    REQUIRE((a.distanceFrom(e) - std::sqrt(42.8489)) < 0.1);
    REQUIRE((a.distanceFrom(f) - std::sqrt(44297.888399999996)) < 0.1);
    REQUIRE((f.distanceFrom(d) - std::sqrt(51893.41840000001)) < 0.1);
}

TEST_CASE("Opérateurs de point")
{

    Point a{18., 42.333};
    Point b = a;

    REQUIRE(a.getX() == b.getX());
    REQUIRE(a.getY() == b.getY());

    Point c{3., 3.4444};
    Point d;
    Point e;

    REQUIRE(d == e);
    REQUIRE(!(c == d));
    REQUIRE((!(c == d)) == (c != d));
    REQUIRE(c != d);
    REQUIRE(!(d != e));
}
