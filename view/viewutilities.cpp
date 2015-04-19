#include "view/viewutilities.hpp"

#include <QRect>
#include <QLine>
#include <QPen>

#include "model/geometry/ellipse.hpp"
#include "model/geometry/line.hpp"
#include "model/geometry/utilities.hpp"
#include "model/geometry/point.hpp"

QPoint viewUtilities::toQPoint(const Point & point)
{
    return QPoint{utilities::round(point.getX()), utilities::round(point.getY())};
}


void viewUtilities::drawEllipse(const Ellipse & ellipse, QPainter & painter,
                                const QColor & color, int width)
{
    QPen pen(color);
    Point upLeftCorner{ellipse.getUpLeftCorner()};
    QRect rect{utilities::round(upLeftCorner.getX()), utilities::round(upLeftCorner.getY()),
               utilities::round(ellipse.getWidth()), utilities::round(ellipse.getHeight())};

    pen.setWidth(width);
    painter.setPen(pen);

    painter.drawEllipse(rect);
}

void viewUtilities::drawLine(const Point & start, const Point & end,
                             QPainter & painter, const QColor & color, int width)
{
    QPen pen(color);

    pen.setWidth(width);
    painter.setPen(pen);

    painter.drawLine(viewUtilities::toQPoint(start), viewUtilities::toQPoint(end));
}
