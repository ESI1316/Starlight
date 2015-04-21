#ifndef MIRRORVIEW_HPP
#define MIRRORVIEW_HPP

#include <QGraphicsLineItem>

#include "model/elements/mirror.hpp"

class MirrorView : QWidget
{
    Mirror * mirror;

public:

    MirrorView(Mirror * mirror);
    ~MirrorView();

protected:

};

#endif // MIRRORVIEW_HPP
