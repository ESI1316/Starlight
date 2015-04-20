#include "view/viewutilities.hpp"

#include <QLineF>
#include <QPen>
#include <QRectF>

QPointF viewUtilities::toQPoint(const Point & point)
{
    return QPointF{point.getX(), point.getY()};
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
    Point upLeftCorner{rectangle.getUpLeftCorner()};
    QGraphicsRectItem * rect = new QGraphicsRectItem { QRectF{upLeftCorner.getX(),
            upLeftCorner.getY(), rectangle.getWidth(), rectangle.getHeight()}};

    QPen pen{color};

    pen.setWidth(width);
    rect->setPen(pen);

    return rect;
}


QGraphicsEllipseItem * viewUtilities::getEllipse(const Ellipse & ellipse,
                                                const QColor & color, int width)
{
    Point upLeftCorner{ellipse.getUpLeftCorner()};
    QGraphicsEllipseItem * ell = new QGraphicsEllipseItem{QRectF{upLeftCorner.getX(),
            upLeftCorner.getY(), ellipse.getWidth(), ellipse.getHeight()}};

    QPen pen{color};

    pen.setWidth(width);
    ell->setPen(pen);

    return ell;
}
