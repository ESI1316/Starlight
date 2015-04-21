#include "model/elements/lens.hpp"

#include "model/elements/level.hpp"
#include "model/exception/starlightexception.hpp"
#include "model/elements/ray.hpp"
#include "model/geometry/point.hpp"

Lens::Lens(const Point & upLeftCorner, const int width, const int height,
           const int wlMin, const int wlMax)
    : Element(),
      Ellipse(width, height, Point{upLeftCorner.getX() + (width / 2.),
                                   upLeftCorner.getY() + (height / 2.)}),
      upLeftCorner{upLeftCorner}, wlMin{wlMin}, wlMax{wlMax}
{
    if(wlMin < Ray::WL_MIN)
        throw StarlightException{"Longueur d'onde minimale trop petite."};
    if(wlMax > Ray::WL_MAX)
        throw StarlightException{"Longueur d'onde maximale trop grande"};
    if(wlMax < wlMin)
        throw StarlightException{"Longueur d'onde minimale > maximale"};
}

void Lens::reactToRay(Ray ray)
{
    if(ray.getWaveLength() >= this->getMinWaveLength()
            && ray.getWaveLength() <= this->getMaxWaveLength())
    {
        if(this->getLevel() != nullptr)
            this->getLevel()->computeRay(Ray{ray.getEnd(),
                                             ray.getAlpha(),
                                             ray.getWaveLength()});
    }
}

Point * Lens::includeRay(const Ray & ray) const
{
    Point * intersec{nullptr};
    std::vector<Point> p{this->getIntersectionPoints(ray)};

    if (!p.empty())
    {
        intersec =
            ray.getStart().distanceFrom(p[0]) > ray.getStart().distanceFrom(p[1]) ?
                new Point{p[0]} : new Point{p[1]};

        if (! ray.isInTrajectory(*intersec))
            delete intersec, intersec = nullptr;
    }

    return intersec;
}

bool Lens::operator==(const Lens & lens) const
{
    return this->wlMin == lens.wlMin
            && this->wlMax == lens.wlMax
            && Ellipse::operator ==(lens);
}


bool Lens::operator!=(const Lens & lens) const
{
    return !(*this == lens);
}

std::ostream & operator<<(std::ostream & out, const Lens & lens)
{
    out << "Lens -- Position : " << lens.getPosition()
        << " , width : " << std::sqrt(lens.getXRadius())
        << " , height : " << std::sqrt(lens.getYRadius())
        << " , Freq. Min. : " << lens.getMinWaveLength()
        << " , Freq. Max. : " << lens.getMaxWaveLength() << std::endl
        << (Ellipse) lens;


    return out;
}
