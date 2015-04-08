#include "model/rectangle.hpp"

Rectangle::Rectangle(int width, int height, const Point & upLeftCorner)
    : width{width}, height{height}, upLeftCorner{upLeftCorner}, edges{4}
{
    edges.push_back(Line{0., upLeftCorner.getY()});
    edges.push_back(Line{1./0., 0, upLeftCorner.getX()});
    edges.push_back(Line{0., upLeftCorner.getY() + height});
    edges.push_back(Line{1./0., 0, upLeftCorner.getX() + width});
}

std::vector<Point> Rectangle::getIntersectionPoints(const Line & line) const
{
    std::vector<Point> intersecs{};
    Point * p;

    for (int i=0; i < this->edges.size() && intersecs.size() <=2 ; i++)
    {
        if ((p = edges[i].getIntersection(line)) && this->isOnBorder(*p))
            intersecs.push_back(*p);
    }

    return intersecs;
}

bool Rectangle::isOnBorder(const Point & point) const
{
    bool commonX = (point.getX() == this->upLeftCorner.getX()) ||
                   (point.getX() == (this->upLeftCorner.getX() + this->width));
    bool commonY = (point.getY() == this->upLeftCorner.getY()) ||
                   (point.getY() == (this->upLeftCorner.getY() + this->height));
    bool xInLimits = (point.getX() >= this->upLeftCorner.getX()) &&
                     (point.getX() <= (this->upLeftCorner.getX() + this->width()));
    bool yInLimits = (point.getY() >= this->upLeftCorner.getY()) &&
                     (point.getY() <= (this->upLeftCorner.getY() + this->height));

    return (commonX && yInLimits) || (commonY && xInLimits);
}

std::vector<Line> Rectangle::getEdges() const
{
    return this->edges;
}

int Rectangle::getWidth() const
{
    return this->width;
}

int Rectangle::getHeight() const
{
    return this->height;
}

Point Rectangle::getUpLeftCorner() const
{
    return this->upLeftCorner;
}
