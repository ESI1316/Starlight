#ifndef MIRRORVIEW_HPP
#define MIRRORVIEW_HPP

#include <QGraphicsLineItem>
#include <QKeyEvent>
#include <QRectF>

#include "model/elements/mirror.hpp"

class MirrorView : public QGraphicsLineItem
{
    Mirror * mirror;

public:

    MirrorView(Mirror * mirror);
    ~MirrorView();

protected:

    void keyPressEvent(QKeyEvent * event);
};

#endif // MIRRORVIEW_HPP
