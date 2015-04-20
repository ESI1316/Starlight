#ifndef MIRRORVIEW_HPP
#define MIRRORVIEW_HPP

#include <QWidget>

#include "model/elements/mirror.hpp"

class MirrorView : QWidget
{
    Mirror * mirror;

public:

    MirrorView(Mirror *mirror, QWidget * parent);
    ~MirrorView();

protected:

    void paintEvent(QPaintEvent *);

};

#endif // MIRRORVIEW_HPP
