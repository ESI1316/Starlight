#ifndef VIEWUTILITIES_HPP
#define VIEWUTILITIES_HPP

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QColor>
#include <QPointF>
#include <QRectF>

#include "model/elements/ray.hpp"

class Ellipse;
class Rectangle;
class Point;

namespace viewUtilities
{
    QPointF toQPoint(const Point & point);

    QRectF toQRectF(const Rectangle &);

    QRectF toQRectF(const Ellipse &);

    QGraphicsLineItem * getLine(const Point &, const Point &, const QColor &, int);

    QGraphicsRectItem * getRect(const Rectangle &, const QColor &, int);

    QGraphicsEllipseItem * getEllipse(const Ellipse &, const QColor &, int);

    /*!
     * \brief waveLengthToColor
     * \return
     * \see http://www.physics.sfasu.edu/astro/color/spectra.html
     */
    QColor waveLengthToColor(const Ray & ray, const double gamma = 0.8);
}

#endif // VIEWUTILITIES_HPP

