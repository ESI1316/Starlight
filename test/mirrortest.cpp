#include "test/catch.hpp"
#include "model/geometry/utilities.hpp"
#include "model/ray.hpp"
#include "model/mirror.hpp"
#include "model/point.hpp"

TEST_CASE("Reflexion de mirroir")
{
    Mirror mirroir{Point{4.6350324277, 6.0423035858}, 50, 80, 5.1882683952,
                   Point{1.,1.}, Point{221., 2221.}, utilities::PI, utilities::PI * 2};

    Ray ray{Point{3.8690993528, 1.9060097494}, 1.0492334171, 500};

    Point point{5.3967177826, 4.5644066284};
    double mirror = utilities::absoluteAngle(mirroir.getAngle());
    double source = utilities::absoluteAngle(std::atan(ray.getSlope()));
    double alpha = utilities::PI - mirror - source;

    Ray newRay(point, (source + alpha + alpha), ray.getWaveLength());

    REQUIRE(utilities::equals(newRay.getSlope(), -0.0977844768));
    REQUIRE(utilities::equals(newRay.getIndepTerm(), 5.0921218532));
}

TEST_CASE("Reflexion de mirroir deux")
{
    Mirror mirroir{Point{1.7607403534, 6.592301552}, 50, 80, 5.6513040756,
                   Point{1.,1.}, Point{221., 2221.}, utilities::PI, utilities::PI * 2};

    Ray ray{Point{1.499676861, 2.0584973355}, 0.5303315945, 500};

    Point point{5.0835944758, 4.1599723344};
    double mirror = utilities::absoluteAngle(mirroir.getAngle());
    double source = utilities::absoluteAngle(std::atan(ray.getSlope()));
    double alpha = utilities::PI - mirror - source;

    Ray newRay(point, (source + alpha + alpha), ray.getWaveLength());

    REQUIRE(utilities::equals(newRay.getSlope(), 4.403644668));
    REQUIRE(utilities::equals(newRay.getIndepTerm(), -18.2263713732));
}
