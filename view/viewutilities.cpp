#include "view/viewutilities.hpp"

#include <QRect>
#include <QLine>
#include <QPen>

/*!
 * \brief toQPoint
 * \param point
 * \return
 */
QPoint viewUtilities::toQPoint(const Point & point)
{
    return QPoint{(int) point.getX(), (int) point.getY()};
}


void drawEllipse(const Ellipse ellipse, QPainter & painter, const QColor & color,
                 int width)
{
    QPen pen(color);
    Point upLeftCorner = ellipse.getUpLeftCorner();
    QRect rect((int) upLeftCorner.getX(), (int) upLeftCorner.getY(),
               (int) ellipse.getWidth(), (int) ellipse.getHeight());

    pen.setWidth(width);
    painter.setPen(pen);

    painter.drawEllipse(rect);
}

void drawLine(const Point & start, const Point & end, QPainter & painter,
              const QColor & color, int width)
{
    QPen pen(color);

    pen.setWidth(width);
    painter.setPen(pen);

    painter.drawLine(viewUtilities::toQPoint(start), viewUtilities::toQPoint(end));
}
