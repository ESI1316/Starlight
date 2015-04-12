#include "test/catch.hpp"
#include <iostream>
#include "model/geometry/utilities.hpp"
#include "model/ray.hpp"
#include "model/mirror.hpp"
#include "model/point.hpp"

TEST_CASE("Reflexion de mirroir angle quelconque")
{
    Mirror mirroir{Point{4.6350324277, 6.0423035858}, 50, 80, 5.1882683952,
                   Point{1.,1.}, Point{221., 2221.}, utilities::PI, utilities::PI * 2};

    Ray ray{Point{3.8690993528, 1.9060097494}, 1.0492334171, 500};

    Point point{5.3967177826, 4.5644066284};
    double mirror = utilities::absoluteAngle(mirroir.getAngle());
    if (utilities::equals(mirror, 0.))
        mirror = 0.;

    double source = utilities::absoluteAngle(std::atan(ray.getSlope()));
    if (utilities::equals(source, 0.))
        source = 0.;

    double alpha = (utilities::PI - mirror - source);
    if (utilities::equals(alpha, 0.))
        alpha = 0.;

    Ray newRay(point, (source + alpha + alpha), ray.getWaveLength());

    REQUIRE(utilities::equals(newRay.getSlope(), -0.0977844768));
    REQUIRE(utilities::equals(newRay.getIndepTerm(), 5.0921218532));
}

TEST_CASE("Reflexion de mirroir angle quelconque deux")
{
    Mirror mirroir{Point{1.7607403534, 6.592301552}, 50, 80, 5.6513040756,
                   Point{1.,1.}, Point{221., 2221.}, utilities::PI, utilities::PI * 2};

    Ray ray{Point{1.499676861, 2.0584973355}, 0.5303315945, 500};

    Point point{5.0835944758, 4.1599723344};
    double mirror = utilities::absoluteAngle(mirroir.getAngle());
    if (utilities::equals(mirror, 0.))
        mirror = 0.;

    double source = utilities::absoluteAngle(std::atan(ray.getSlope()));
    if (utilities::equals(source, 0.))
        source = 0.;

    double alpha = (utilities::PI - mirror - source);
    if (utilities::equals(alpha, 0.))
        alpha = 0.;

    Ray newRay(point, (source + alpha + alpha), ray.getWaveLength());

    REQUIRE(utilities::equals(newRay.getSlope(), 4.403644668));
    REQUIRE(utilities::equals(newRay.getIndepTerm(), -18.2263713732));
}

TEST_CASE("Reflexion sur mirroir vertical et angle de tir 0°")
{
    Mirror mirroir{Point{6.7091129602, 5.7891302282}, 50, 80, (3. * utilities::PI) / 2.,
                   Point{1.,1.}, Point{221., 2221.}, utilities::PI, utilities::PI * 2};

    Ray ray{Point{0.687119753, 2.0988911382}, 0., 500};

    Point point{6.7091129602, 2.0988911382};
    double mirror = utilities::absoluteAngle(mirroir.getAngle());
    if (utilities::equals(mirror, 0.))
        mirror = 0.;

    double source = utilities::absoluteAngle(std::atan(ray.getSlope()));
    if (utilities::equals(source, 0.))
        source = 0.;

    double alpha = (utilities::PI - mirror - source);
    if (utilities::equals(alpha, 0.))
        alpha = 0.;

    Ray newRay(point, (source + alpha + alpha), ray.getWaveLength());

    REQUIRE(utilities::equals(newRay.getSlope(), 0.));
    REQUIRE(utilities::equals(newRay.getIndepTerm(),  2.0988911382));
}

TEST_CASE("Reflexion sur mirroir vertical et angle de tir 0° avec"
          "angle en surplus de 2PI")
{
    Mirror mirroir{Point{6.7091129602, 5.7891302282}, 50, 80, -(utilities::PI / 2.),
                   Point{1.,1.}, Point{221., 2221.}, -utilities::PI * 2, utilities::PI * 2};

    Ray ray{Point{0.687119753, 2.0988911382}, 0., 500};

    Point point{6.7091129602, 2.0988911382};
    double mirror = utilities::absoluteAngle(mirroir.getAngle());
    if (utilities::equals(mirror, 0.))
        mirror = 0.;

    double source = utilities::absoluteAngle(std::atan(ray.getSlope()));
    if (utilities::equals(source, 0.))
        source = 0.;

    double alpha = (utilities::PI - mirror - source);
    if (utilities::equals(alpha, 0.))
        alpha = 0.;

    Ray newRay(point, (source + alpha + alpha), ray.getWaveLength());

    REQUIRE(utilities::equals(newRay.getSlope(), 0.));
    REQUIRE(utilities::equals(newRay.getIndepTerm(),  2.0988911382));
}

TEST_CASE("Reflexion sur mirroir horizontale et perpendiculaire au tir")
{
    Mirror mirroir{Point{3.1027244297, 6.9894297822}, 50, 80, 0.,
                   Point{1.,1.}, Point{221., 2221.}, 0., utilities::PI * 2};

    Ray ray{Point{8.0884039814, 1.1190305352}, utilities::PI_2, 500};

    Point point{8.0884039814, 6.9894297822};
    double mirror = utilities::absoluteAngle(mirroir.getAngle());
    if (utilities::equals(mirror, 0.))
        mirror = 0.;

    double source = utilities::absoluteAngle(std::atan(ray.getSlope()));
    if (utilities::equals(source, 0.))
        source = 0.;

    double alpha = (utilities::PI - mirror - source);
    if (utilities::equals(alpha, 0.))
        alpha = 0.;

    Ray newRay(point, (source + alpha + alpha), ray.getWaveLength());

    REQUIRE(newRay.isVertical());
    REQUIRE(utilities::equals(newRay.getXValue(),  8.0884039814));
}

TEST_CASE("Reflexion de mirroir angle quelconque + 2PI")
{
    Mirror mirroir{Point{4.6350324277, 6.0423035858}, 50, 80, 5.1882683952,
                   Point{1.,1.}, Point{221., 2221.}, utilities::PI, utilities::PI * 2};

    Ray ray{Point{3.8690993528, 1.9060097494}, 1.0492334171 + (2* utilities::PI), 500};

    Point point{5.3967177826, 4.5644066284};
    double mirror = utilities::absoluteAngle(mirroir.getAngle());
    if (utilities::equals(mirror, 0.))
        mirror = 0.;

    double source = utilities::absoluteAngle(std::atan(ray.getSlope()));
    if (utilities::equals(source, 0.))
        source = 0.;

    double alpha = (utilities::PI - mirror - source);
    if (utilities::equals(alpha, 0.))
        alpha = 0.;

    Ray newRay(point, (source + alpha + alpha), ray.getWaveLength());

    REQUIRE(utilities::equals(newRay.getSlope(), -0.0977844768));
    REQUIRE(utilities::equals(newRay.getIndepTerm(), 5.0921218532));
}

TEST_CASE("Reflexion de mirroir angle quelconque négatif")
{
    Mirror mirroir{Point{4.6350324277, 6.0423035858}, 50, 80, 5.1882683952,
                   Point{1.,1.}, Point{221., 2221.}, utilities::PI, utilities::PI * 2};

    Ray ray{Point{3.8690993528, 1.9060097494}, -((utilities::PI * 2) - 1.0492334171), 500};

    Point point{5.3967177826, 4.5644066284};
    double mirror = utilities::absoluteAngle(mirroir.getAngle());
    if (utilities::equals(mirror, 0.))
        mirror = 0.;

    double source = utilities::absoluteAngle(std::atan(ray.getSlope()));
    if (utilities::equals(source, 0.))
        source = 0.;

    double alpha = (utilities::PI - mirror - source);
    if (utilities::equals(alpha, 0.))
        alpha = 0.;

    Ray newRay(point, (source + alpha + alpha), ray.getWaveLength());

    REQUIRE(utilities::equals(newRay.getSlope(), -0.0977844768));
    REQUIRE(utilities::equals(newRay.getIndepTerm(), 5.0921218532));
}
