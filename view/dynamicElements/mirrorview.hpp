#ifndef MIRRORVIEW_HPP
#define MIRRORVIEW_HPP

#include <QGraphicsLineItem>

#include "model/elements/mirror.hpp"

class MirrorView : public QGraphicsLineItem
{
    Mirror * mirror;

public:

    MirrorView(Mirror * mirror);
    ~MirrorView();
};

#endif // MIRRORVIEW_HPP
