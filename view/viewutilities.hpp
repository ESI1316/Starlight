#ifndef VIEWUTILITIES_HPP
#define VIEWUTILITIES_HPP

#include <QPainter>
#include <QColor>
#include <QPoint>

class Ellipse;
class Line;
class Point;
class Rectangle;

namespace viewUtilities
{
    /*!
     * \brief viewutilities::toQPoint
     * \param point
     * \return
     */
    QPoint toQPoint(const Point & point);

    /*!
     * \brief drawLine
     * \param start
     * \param end
     * \param painter
     * \param color
     * \param width
     */
    void drawLine(const Point &, const Point &, QPainter &, const QColor &, int);

    /*!
     * \brief drawEllipse
     * \param ellipse
     * \param painter
     * \param color
     * \param width
     */
    void drawEllipse(const Ellipse &, QPainter &, const QColor &, int);

    /*!
     * \brief viewUtilities::drawRectangle
     * \param rectangle
     * \param painter
     * \param color
     * \param width
     * \param filled
     */
    void drawRectangle(const Rectangle &, QPainter &, const QColor &, int, bool);
}

#endif // VIEWUTILITIES_HPP

