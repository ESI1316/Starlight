#include "main.hpp"

#ifdef RUN_TEST

#include "test/catch.hpp"
#include "model/elements/wall.hpp"
#include "model/geometry/point.hpp"
#include "model/elements/ray.hpp"
#include "model/exception/starlightexception.hpp"
#include "model/geometry/utilities.hpp"

TEST_CASE("Construction d'un wall")
{
    REQUIRE_NOTHROW(Wall(Point(2., 2.), Point(3., 2.)));
    REQUIRE_NOTHROW(Wall(Point(3., 2.), Point(3., 3.)));
    REQUIRE_THROWS_AS(Wall(Point(3., 3.), Point(3., 3.)), StarlightException);
    REQUIRE_THROWS_AS(Wall(Point(113.22, -43.), Point(113.22, -43.)), StarlightException);
}

TEST_CASE("Wall : accesseurs")
{
    Wall wall{Point{3., 2.222}, Point{5.23, 3.}};

    REQUIRE(wall.getStart() == Point(3., 2.222));
    REQUIRE(wall.getEnd() == Point(5.23, 3.));
    REQUIRE_FALSE(wall.isVertical());
    REQUIRE(utilities::equals(wall.getSlope(), 0.3488789238));
    REQUIRE(utilities::equals(wall.getIndepTerm(), 1.1753632287));
}

TEST_CASE("Wall : operateurs")
{
    Wall wall{Point{3., 2.222}, Point{5.23, 3.}};
    Wall wa{Point{3., 2.222}, Point{5.23, 3.}};
    Wall w{Point{-23., 2.222}, Point{5.23, 3.}};

    REQUIRE(wall == wa);
    REQUIRE_FALSE(wall != wa);
    REQUIRE_FALSE(wall == w);
    REQUIRE_FALSE(wa == w);
}

TEST_CASE("Wall : intersection avec un rayon")
{
    Wall wall{Point{3., 2.222}, Point{5.23, 3.}};

    SECTION("Droite quelconque : pas d'intersection")
    {
        Ray ray{Point{2., 1.}, 0.9647701867, 400};
        Point * intersection = wall.includeRay(ray);

        REQUIRE(intersection == 0);
    }

    SECTION("Droite quelconque : intersection")
    {
        Ray ray{Point{2., 1.}, -0.7308006587, 400};
        Point * intersection = wall.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(3.5947954986, 2.4295116134));
        delete intersection;
    }

    SECTION("Droite horizontale : pas d'intersection")
    {
        Ray ray{Point{1.4191947327, 3.4719175286}, 0., 400};
        Point * intersection = wall.includeRay(ray);

        REQUIRE(intersection == 0);
    }
    SECTION("Droite horizontale : intersection")
    {
        Ray ray{Point{1.4191947327, 2.4719175286}, 0., 400};
        Point * intersection = wall.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(3.7163445871, 2.4719175286));
        delete intersection;
    }
    SECTION("Droite verticale : pas d'intersection")
    {
        Ray ray{Point{2., 1.}, -utilities::PI_2, 400};
        Point * intersection = wall.includeRay(ray);

        REQUIRE(intersection == 0);

    }
    SECTION("Droite verticale : intersection")
    {
        Ray ray{Point{4.2685319879, 1.}, -utilities::PI_2, 400};
        Point * intersection = wall.includeRay(ray);

        REQUIRE(intersection != 0);
        REQUIRE(*intersection == Point(4.2685319879, 2.6645640747));
        delete intersection;

    }
}

#endif

