#include "view/viewutilities.hpp"

#include <QLineF>
#include <QPen>

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
