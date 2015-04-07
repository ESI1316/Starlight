#include "../test/catch.hpp"
#include "../model/utilities.hpp"
#include "../model/point.hpp"

TEST_CASE("Construction de points")
{

    Point p{2., 2.};
    REQUIRE(utilities::equals(p.getX(), 2.));
    REQUIRE(utilities::equals(p.getY(), 2.));

    Point pp{p};
    REQUIRE(utilities::equals(pp.getX(), 2.));
    REQUIRE(utilities::equals(pp.getY(), 2.));

    Point ppp(2, 99);
    REQUIRE(utilities::equals(ppp.getX(), 2.));
    REQUIRE(utilities::equals(ppp.getY(), 99.));

    Point pppp{1., 1.};
    REQUIRE(utilities::equals(pppp.getRadius(), 1.41421356));
    REQUIRE(utilities::equals(pppp.getAzimut(), 0.785398163));

    Point ppppp{2., 2.};
    REQUIRE(utilities::equals(ppppp.getRadius(), p.getRadius()));
    REQUIRE(utilities::equals(ppppp.getAzimut(), p.getAzimut()));
}

TEST_CASE("mutateurs de point")
{
    Point pp{2., 2.};
    pp.setX(-18.3);
    REQUIRE(utilities::equals(pp.getX(), -18.3));
    REQUIRE(utilities::equals(pp.getY(), 2.));

    pp.setY(utilities::PI);
    REQUIRE(utilities::equals(pp.getX(), -18.3));
    REQUIRE(utilities::equals(pp.getY(), utilities::PI));

    pp.setLocation(4.28, 8.10);
    REQUIRE(utilities::equals(pp.getX(), 4.28));
    REQUIRE(utilities::equals(pp.getY(), 8.10));

    pp.setLocation(1., 1.);
    REQUIRE(utilities::equals(pp.getRadius(), 1.41421356));
    REQUIRE(utilities::equals(pp.getAzimut(), 0.785398163));
}

TEST_CASE("Autres méthodes de points")
{

    Point a{2., 2.};
    Point b{4., 4.};
    Point c{0., 0.};
    Point d{-4., 18.3};
    Point e{-3.33, -1.8};
    Point f{88.22, -190};

    REQUIRE(utilities::equals(a.distanceFrom(b), b.distanceFrom(a)));
    REQUIRE(utilities::equals(a.distanceFrom(c), c.distanceFrom(a)));
    REQUIRE(utilities::equals(a.distanceFrom(d), d.distanceFrom(a)));

    REQUIRE(utilities::equals(a.distanceFrom(b), std::sqrt(8)));
    REQUIRE(utilities::equals(a.distanceFrom(c), std::sqrt(8)));
    REQUIRE(utilities::equals(a.distanceFrom(d), std::sqrt(301.69)));
    REQUIRE(utilities::equals(a.distanceFrom(e), std::sqrt(42.8489)));
    REQUIRE(utilities::equals(a.distanceFrom(f), std::sqrt(44297.888399999996)));
    REQUIRE(utilities::equals(f.distanceFrom(d), std::sqrt(51893.41840000001)));

    REQUIRE_FALSE(a.isCenter());
    REQUIRE_FALSE(b.isCenter());
    REQUIRE_FALSE(d.isCenter());
    REQUIRE_FALSE(e.isCenter());
    REQUIRE_FALSE(f.isCenter());
    REQUIRE(c.isCenter());
}

TEST_CASE("Azimut en degré")
{
    Point p{1., 1.};
    REQUIRE(utilities::equals(p.getAzimutAsDegrees(), 45.));
    Point pp{0., 1};
    REQUIRE(utilities::equals(pp.getAzimutAsDegrees(), 90.));
    Point ppp{-1., 1};
    REQUIRE(utilities::equals(ppp.getAzimutAsDegrees(), 135.));
    Point pppp{-1, -1};
    REQUIRE(utilities::equals(pppp.getAzimutAsDegrees(), 225.));
    Point ppppp{-0.5, 0.866025404};
    REQUIRE(utilities::equals(ppppp.getAzimutAsDegrees(), 120.));
}

TEST_CASE("Opérateurs de point")
{

    Point a{18., 42.333};
    Point b = a;

    REQUIRE(utilities::equals(a.getX(), b.getX()));
    REQUIRE(utilities::equals(a.getY(), b.getY()));

    Point c{3., 3.4444};
    Point d;
    Point e;

    REQUIRE(d == e);
    REQUIRE(!(c == d));
    REQUIRE((!(c == d)) == (c != d));
    REQUIRE(c != d);
    REQUIRE(!(d != e));
}
