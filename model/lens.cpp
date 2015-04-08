#include "model/lens.hpp"
#include "model/level.hpp"
#include "model/starlightexception.hpp"

Lens::Lens(const Point & upLeftCorner, const int width, const int height, const int wlMin, const int wlMax)
    : Element(), upLeftCorner{upLeftCorner}, wlMin{wlMin}, wlMax{wlMax}
{
    if(wlMin < Ray::WL_MIN)
        throw StarlightException("Longueur d'onde minimale non nulle req.");
    if(wlMax < Ray::WL_MAX)
        throw StarlightException("Longueur d'onde maximale non nulle req.");
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
    throw StarlightException("Not implemented yet");
}

bool Lens::operator==(const Lens & lens) const
{
    return this->wlMin == lens.wlMin
            && this->wlMax == lens.wlMax
            //&& Ellipse::operator ==(lens)
            && Element::operator ==(lens);
}


bool Lens::operator!=(const Lens & lens) const
{
    return !(*this == lens);
}

std::ostream & operator<<(std::ostream & out, const Lens & lens)
{
    out << "Lens -- Position : " <<lens.getPosition()
        //<< " , width : " << lens.getWidth()
        //<< " , height : " << lens.getHeight()
        << " , Freq. Min. : " <<lens.getMinWaveLength()
        << " , Freq. Max. : " <<lens.getMaxWaveLength();

    return out;
}
