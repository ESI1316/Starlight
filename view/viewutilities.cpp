#include "view/viewutilities.hpp"

#include <QLineF>
#include <QPen>

#include "model/geometry/ellipse.hpp"
#include "model/geometry/rectangle.hpp"
#include "model/geometry/point.hpp"
#include "model/geometry/utilities.hpp"


QPointF viewUtilities::toQPoint(const Point & point)
{
    return QPointF{point.getX(), point.getY()};
}

QRectF viewUtilities::toQRectF(const Rectangle & rectangle)
{
    Point upLeftCorner{rectangle.getUpLeftCorner()};

    return QRectF{upLeftCorner.getX(), upLeftCorner.getY(), rectangle.getWidth(),
                rectangle.getHeight()};
}

QRectF viewUtilities::toQRectF(const Ellipse & ellipse)
{
    Point upLeftCorner{ellipse.getUpLeftCorner()};

    return QRectF{upLeftCorner.getX(),
                upLeftCorner.getY(), ellipse.getWidth(), ellipse.getHeight()};
}

QGraphicsLineItem * viewUtilities::getLine(const Point & start, const Point & end,
                                          const QColor & color, int width)
{
    QGraphicsLineItem * line = new QGraphicsLineItem(QLineF{viewUtilities::toQPoint(start),
                                                     viewUtilities::toQPoint(end)});
    QPen pen{color};

    pen.setWidth(width);
    line->setPen(pen);

    return line;
}

QGraphicsRectItem * viewUtilities::getRect(const Rectangle & rectangle,
                                          const QColor & color, int width)
{
    QGraphicsRectItem * rect = new QGraphicsRectItem{viewUtilities::toQRectF(rectangle)};
    QPen pen{color};

    pen.setWidth(width);
    rect->setPen(pen);

    return rect;
}

QGraphicsEllipseItem * viewUtilities::getEllipse(const Ellipse & ellipse,
                                                const QColor & color, int width)
{
    QGraphicsEllipseItem * ell = new QGraphicsEllipseItem{viewUtilities::toQRectF(ellipse)};
    QPen pen{color};

    pen.setWidth(width);
    ell->setPen(pen);

    return ell;
}

QColor viewUtilities::waveLengthToColor(const Ray & ray)
{
    int wl = ray.getWaveLength();
    double gamma{0.8};
    double red{0.};
    double green{0.};
    double blue{0.};

        if (wl >= 380 && wl <= 440)
    {
            double transparency{0.3 + (0.7 * (wl - 380) / (440 - 380))};
            red = std::pow(((-(wl - 440) / (440 - 380)) * transparency), gamma);
            blue = std::pow((1.0 * transparency), gamma);
    }
        else if (wl >= 440 && wl <= 490)
    {
            green = std::pow(((wl - 440) / (490 - 440)), gamma);
            blue = 1.0;
    }
        else if (wl >= 490 && wl <= 510)
    {
            green = 1.0;
           blue = std::pow((-(wl - 510) / (510 - 490)), gamma);
    }
        else if (wl >= 510 && wl <= 580)
    {
            red = std::pow(((wl - 510) / (580 - 510)), gamma);
            green = 1.0;
    }
        else if (wl >= 580 && wl <= 645)
    {
            red = 1.0;
            green = std::pow((-(wl - 645) / (645 - 580)), gamma);
    }
        else if (wl >= 645 && wl <= 750)
    {
            double transparency{0.3 + (0.7 * (750 - wl) / (750 - 645))};
            red = std::pow((1.0 * transparency), gamma);
    }

    return QColor(red * 255, green * 255, blue * 255);
}
