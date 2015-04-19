#ifndef VIEWUTILITIES
#define VIEWUTILITIES

#include <QPainter>
#include <QColor>
#include <QPointF>

#include "model/geometry/ellipse.hpp"
#include "model/geometry/line.hpp"

namespace viewUtilities
{
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
    void drawEllipse(const Ellipse, QPainter &, const QColor &, int);

    /*!
     * \brief viewutilities::toQPoint
     * \param point
     * \return
     */
    QPointF toQPoint(const Point & point);
}

#endif // VIEWUTILITIES

