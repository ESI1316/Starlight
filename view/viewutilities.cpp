#include "view/viewutilities.hpp"

#include <cmath>
#include <QRect>
#include <QLine>
#include <QPen>

void drawEllipse(const Ellipse ellipse, QPainter & painter, const QColor & color,
                 int width)
{/*
    QPen pen(color);
    QRect rect(viewUtilities::toQPoint(ellipse.getUpLeftCorner),
               ellipse.getWidth, ellipse.getHeight());

    pen.setWidth(width);
    painter.setPen(pen);

    painter.drawRect(rect); */
}

void viewUtilities::drawLine(const Point & start, const Point & end,
                             QPainter & painter, const QColor & color, int width)
{
    QPen pen(color);

    pen.setWidth(width);
    painter.setPen(pen);

    painter.drawLine(viewUtilities::toQPoint(start), viewUtilities::toQPoint(end));
}

QPointF viewUtilities::toQPoint(const Point & point)
{
    return QPointF{point.getX(), point.getY()};
}
