#ifndef MIRRORVIEW_HPP
#define MIRRORVIEW_HPP

#include <QGraphicsView>

#include "model/elements/mirror.hpp"

class mirrorView : QGraphicsView
{
    Mirror * mirror;

public:

    mirrorView(Mirror *mirror, QWidget * parent);
    ~mirrorView();
};

#endif // MIRRORVIEW_HPP
