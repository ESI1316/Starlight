#ifndef VIEWUTILITIES_HPP
#define VIEWUTILITIES_HPP

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QColor>
#include <QPointF>

#include "model/geometry/ellipse.hpp"
#include "model/geometry/line.hpp"
#include "model/geometry/rectangle.hpp"
#include "model/geometry/utilities.hpp"
#include "model/geometry/point.hpp"

namespace viewUtilities
{
    QPointF toQPoint(const Point & point);

    QGraphicsLineItem * getLine(const Point &, const Point &, const QColor &, int);

    QGraphicsRectItem * getRect(const Rectangle &, const QColor &, int);

    QGraphicsEllipseItem * getEllipse(const Ellipse &, const QColor &, int);
}

#endif // VIEWUTILITIES_HPP

