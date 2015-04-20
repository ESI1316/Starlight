#ifndef MIRRORVIEW_HPP
#define MIRRORVIEW_HPP

#include <QWidget>

#include "model/elements/mirror.hpp"

class MirrorView : QWidget
{
    Q_OBJECT

    Mirror * mirror;

public:

    MirrorView(Mirror * mirror, QWidget * parent = 0);
    ~MirrorView();

protected:

};

#endif // MIRRORVIEW_HPP
