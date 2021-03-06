#include "model/geometry/rectangle.hpp"

#include "model/geometry/utilities.hpp"
#include "model/exception/starlightexception.hpp"

Rectangle::Rectangle(double width, double height, const Point & upLeftCorner)
    : width{width}, height{height}, upLeftCorner{upLeftCorner},
      edges{{Line{0., upLeftCorner.getY()}},
            {Line{utilities::INF, 0, upLeftCorner.getX()}},
            {Line{0., upLeftCorner.getY() + height}},
            {Line{utilities::INF, 0, upLeftCorner.getX() + width}}}
{
    if(width < 0. || utilities::equals(width, 0.))
        throw StarlightException{"Largeur strictement positive requise"};
    if(height < 0. || utilities::equals(height, 0.))
        throw StarlightException{"Hauteur strictement positive requise"};
}

std::vector<Point> Rectangle::getIntersectionPoints(const Line & line) const
{
    std::vector<Point> intersecs;
    Point * p{nullptr};

    for (auto i = this->edges.begin(); (i != this->edges.end()) && (intersecs.size() < 2) ; i++)
    {
        if ((p = i->getIntersectionPoint(line)) && this->isOnBorder(*p))
            intersecs.push_back(*p);

        if (p != nullptr)
            delete p, p = nullptr;
    }

    return intersecs;
}

bool Rectangle::isOnBorder(const Point & point) const
{
    bool commonX {(utilities::equals(point.getX(), this->upLeftCorner.getX())) ||
                (utilities::equals(point.getX(), this->upLeftCorner.getX() + this->width))};
    bool commonY {(utilities::equals(point.getY(), this->upLeftCorner.getY())) ||
                (utilities::equals(point.getY(), this->upLeftCorner.getY() + this->height))};

    bool xInLimits {(utilities::greaterOrEquals(point.getX(), this->upLeftCorner.getX()))
                && (utilities::lessOrEquals(point.getX(), this->upLeftCorner.getX() + this->width))};
    bool yInLimits {(utilities::greaterOrEquals(point.getY(), this->upLeftCorner.getY()))
                && (utilities::lessOrEquals(point.getY(), this->upLeftCorner.getY() + this->height))};

    return (commonX && yInLimits) || (commonY && xInLimits);
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
    out << "Rectangle --" <<  std::endl
        << "largeur : " << rectangle.getWidth() << std::endl
        << "hauteur : " << rectangle.getHeight() << std::endl
        << "Coin supérieur gauche : " << rectangle.getUpLeftCorner() << std::endl;

    return out;
}
