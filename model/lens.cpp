#include "lens.hpp"
#include "level.hpp"
#include "starlightexception.hpp"

Lens::Lens(const Point & position, const int width, const int height, const int wlMin, const int wlMax)
    : Element(),
      position {position},
      width{this->valideWidth(width)},
      height{this->valideHeight(height)},
      wlMin{this->valideWlMin(wlMin, wlMax)},
      wlMax{this->valideWlMax(wlMax, wlMin)}
{
}

const int & Lens::valideWidth(const int & width) const
{
    if(width <= 0)
        throw StarlightException("Largeur positive requise");

    return width;
}

const int & Lens::valideHeight(const int & height) const
{
    if(height <= 0)
        throw StarlightException("Hauteur positive requise");

    return height;
}

const int & Lens::valideWlMin(const int & wlMin, const int & wlMax) const
{
    if(wlMin < 0)
        throw StarlightException("Longueur d'onde minimale non nulle req.");
    if(wlMax < wlMin)
        throw StarlightException("Longueur d'onde minimale > maximale");

    return wlMin;
}

const int & Lens::valideWlMax(const int & wlMax, const int & wlMin) const
{
    if(wlMax < 0)
        throw StarlightException("Longueur d'onde maximale non nulle req.");
    if(wlMax < wlMin)
        throw StarlightException("Longueur d'onde minimale > maximale");

    return wlMax;
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
    throw StarlightException("Not implemented yet");
}
bool Lens::includePoint(Point & point)
{
    throw StarlightException("Not implemented yet");
}

Lens & Lens::operator =(const Lens & lens)
{
    this->position = lens.position;
    this->width = lens.width;
    this->height = lens.height;
    this->wlMin = lens.wlMin;
    this->wlMax = lens.wlMax;

    return *this;
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
