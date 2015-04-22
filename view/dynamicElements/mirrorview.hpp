#ifndef MIRRORVIEW_HPP
#define MIRRORVIEW_HPP

#include <QGraphicsLineItem>
#include <QKeyEvent>

class Mirror;

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
