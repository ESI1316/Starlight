#include "lens.hpp"
#include "level.hpp"
#include "starlightexception.hpp"

Lens::Lens(const Point & position, const int width, const int height, const int wlMin, const int wlMax)
    : Element(),
      position {position},
      width{width},
      height{height},
      wlMin{wlMin},
      wlMax{wlMax}
{
    if(width <= 0)
        throw StarlightException("Largeur positive requise");
    if(height <= 0)
        throw StarlightException("Hauteur positive requise");
    if(wlMin < 0)
        throw StarlightException("Longueur d'onde minimale non nulle req.");
    if(wlMax < 0)
        throw StarlightException("Longueur d'onde maximale non nulle req.");
    if(wlMax < wlMin)
        throw StarlightException("Longueur d'onde minimale > maximale");
}

const Point & Lens::getPosition() const
{
    return this->position;
}

int Lens::getWidth() const
{
    return this->width;
}

int Lens::getHeight() const
{
    return this->height;
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
bool Lens::includeRay(const Ray & ray) const
{
    throw StarlightException("Not implemented yet");
}

std::ostream & operator<<(std::ostream & out, const Lens & lens)
{
    out << "Lens -- Position : " <<lens.getPosition()
        << " , width : " <<lens.getWidth()
        << " , height : " <<lens.getHeight()
        << " , Freq. Min. : " <<lens.getMinWaveLength()
        << " , Freq. Max. : " <<lens.getMaxWaveLength();

    return out;
}
