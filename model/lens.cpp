#include "model/lens.hpp"
#include "model/level.hpp"
#include "model/starlightexception.hpp"

Lens::Lens(const Point & position, const int width, const int height, const int wlMin, const int wlMax)
    : Element(), position {position}, width{width}, height{height},
      wlMin{wlMin}, wlMax{wlMax}
{
    if(width <= 0)
        throw StarlightException("Largeur strictement positive requise");
    if(height <= 0)
        throw StarlightException("Hauteur strictement positive requise");
    if(wlMin < Ray::WL_MIN)
        throw StarlightException("Longueur d'onde minimale non nulle req.");
    if(wlMax < Ray::WL_MAX)
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

/* DEBUG DEBUG
    SI RAYON NE PASSE PASSE, ON SET LE END
*/
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

bool Lens::operator==(const Lens & lens) const
{
    return this->position == lens.position
            && this->width == lens.width
            && this->height == lens.height
            && this->wlMin == lens.wlMin
            && this->wlMax == lens.wlMax
            && Element::operator ==(lens);
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
