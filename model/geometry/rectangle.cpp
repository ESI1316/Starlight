#include "model/geometry/rectangle.hpp"

#include "model/geometry/line.hpp"
#include "model/geometry/utilities.hpp"
#include "model/starlightexception.hpp"

Rectangle::Rectangle(double width, double height, const Point & upLeftCorner)
    : width{width}, height{height}, upLeftCorner{upLeftCorner},
      edges{{Line{0., upLeftCorner.getY()}},
            {Line{1./0., 0, upLeftCorner.getX()}},
            {Line{0., upLeftCorner.getY() + height}},
            {Line{1./0., 0, upLeftCorner.getX() + width}}}
{
    if(width < 0. || utilities::equals(width, 0.))
        throw StarlightException("Largeur strictement positive requise");
    if(height < 0. || utilities::equals(height, 0.))
        throw StarlightException("Hauteur strictement positive requise");
}

std::vector<Point> Rectangle::getIntersectionPoints(const Line & line) const
{
    std::vector<Point> intersecs;
    Point * p;

    for (unsigned i = 0; i < this->edges.size() && intersecs.size() < 2 ; i++)
    {
        if ((p = edges.at(i).getIntersectionPoint(line)) && this->isOnBorder(*p))
            intersecs.push_back(*p);
    }

    return intersecs;
}

bool Rectangle::isOnBorder(const Point & point) const
{
    bool commonX = (utilities::equals(point.getX(), this->upLeftCorner.getX())) ||
                    (utilities::equals(point.getX(), this->upLeftCorner.getX() + this->width));
    bool commonY = (utilities::equals(point.getY(), this->upLeftCorner.getY())) ||
                    (utilities::equals(point.getY(), this->upLeftCorner.getY() + this->height));
    bool xInLimits = (point.getX() >= this->upLeftCorner.getX()) &&
            (point.getX() <= (this->upLeftCorner.getX() + this->width));
    bool yInLimits = (point.getY() >= this->upLeftCorner.getY()) &&
            (point.getY() <= (this->upLeftCorner.getY() + this->height));

    return (commonX && yInLimits) || (commonY && xInLimits);
}

std::vector<Line> Rectangle::getEdges() const
{
    return this->edges;
}

double Rectangle::getWidth() const
{
    return this->width;
}

double Rectangle::getHeight() const
{
    return this->height;
}

Point Rectangle::getUpLeftCorner() const
{
    return this->upLeftCorner;
}

bool Rectangle::operator ==(const Rectangle & rectangle) const
{
    return utilities::equals(this->width, rectangle.width)
            && utilities::equals(this->height, rectangle.height)
            && this->upLeftCorner == rectangle.upLeftCorner;
}

bool Rectangle::operator !=(const Rectangle & rectangle) const
{
    return !(*this == rectangle);
}

Rectangle & Rectangle::operator =(const Rectangle & rectangle)
{
    this->width = rectangle.width;
    this->height = rectangle.height;
    this->upLeftCorner = rectangle.upLeftCorner;
    this->edges = rectangle.edges;

    return *this;
}

std::ostream & operator<<(std::ostream & out, const Rectangle & rectangle)
{
    out << rectangle.getWidth() << " : largeur" << std::endl
        << "------" << std::endl
        << "|    |" << std::endl
        << "|    | " << rectangle.getHeight() << " : hauteur" << std::endl
        << "------" << std::endl
        << "Coin supérieur gauche : " << rectangle.getUpLeftCorner();

    return out;
}
