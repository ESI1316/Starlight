#include "model/lens.hpp"

#include "model/level.hpp"
#include "model/starlightexception.hpp"
#include "model/ray.hpp"
#include "model/point.hpp"

Lens::Lens(const Point & upLeftCorner, const int width, const int height,
           const int wlMin, const int wlMax)
    : Element(), upLeftCorner{upLeftCorner}, wlMin{wlMin}, wlMax{wlMax},
      Ellipse(width, height, Point{this->upLeftCorner.getX() + (width / 2.),
                                   this->upLeftCorner.getY() - (height / 2.)})
{
    if(wlMin < Ray::WL_MIN)
        throw StarlightException("Longueur d'onde minimale trop petite.");
    if(wlMax > Ray::WL_MAX)
        throw StarlightException("Longueur d'onde maximale trop grande");
    if(wlMax < wlMin)
        throw StarlightException("Longueur d'onde minimale > maximale");
}

const Point & Lens::getPosition() const
{
    return this->upLeftCorner;
}

int Lens::getMinWaveLength() const
{
    return this->wlMin;
}

int Lens::getMaxWaveLength() const
{
    return this->wlMax;
}

void Lens::reactToRay(Ray & ray)
{
    if(ray.getWaveLength() >= this->getMinWaveLength()
            && ray.getWaveLength() <= this->getMaxWaveLength())
        this->getLevel()->computeRay(ray);
}

Point * Lens::includeRay(const Ray & ray) const
{
    Point * intersec = 0;
    std::vector<Point> p = this->getIntersectionPoints(ray);

    if (p.size() > 0)
    {
        intersec =
            ray.getStart().distanceFrom(p[0]) > ray.getStart().distanceFrom(p[1]) ?
                new Point{p[0]} : new Point{p[1]};
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
    out << "Lens -- Position : " <<lens.getPosition()
        << " , width : " << std::sqrt(lens.getXRadius())
        << " , height : " << std::sqrt(lens.getYRadius())
        << " , Freq. Min. : " << lens.getMinWaveLength()
        << " , Freq. Max. : " << lens.getMaxWaveLength();

    return out;
}
