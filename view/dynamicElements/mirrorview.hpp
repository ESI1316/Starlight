#ifndef MIRRORVIEW_HPP
#define MIRRORVIEW_HPP

#include <QGraphicsLineItem>
#include <QRectF>

#include "model/elements/mirror.hpp"

class MirrorView : public QGraphicsLineItem
{
    Mirror * mirror;
    QRectF boundRect;

public:

    MirrorView(Mirror * mirror);
    ~MirrorView();

protected:

    QVariant itemChange(GraphicsItemChange, const QVariant &);

};

#endif // MIRRORVIEW_HPP
