#include "mirrorview.hpp"

#include <QLineF>
#include <QCursor>

#include "view/viewutilities.hpp"
#include "model/elements/mirror.hpp"
#include "model/geometry/point.hpp"

MirrorView::MirrorView(Mirror * mirror)
    : QGraphicsLineItem(QLineF{viewUtilities::toQPoint(mirror->getStart()),
                        viewUtilities::toQPoint(mirror->getEnd())}),
      mirror{mirror}

{
    this->setPen(QPen{QColor{204, 204, 255}, 2.});
    QGraphicsLineItem::setCursor(QCursor(Qt::PointingHandCursor));
    this->setFlag(QGraphicsItem::ItemIsMovable);
    this->setAcceptedMouseButtons(false);
    this->setFlag(GraphicsItemFlag::ItemIsFocusable);
}

MirrorView::~MirrorView() {}

void MirrorView::keyPressEvent(QKeyEvent *event)
{
    Point start{mirror->getStart()}, end{mirror->getEnd()};

    switch (event->key())
    {
    case Qt::Key_Left : this->mirror->rotate(1.);
        this->setLine(start.getX(), start.getY(), end.getX(), end.getY());
        break;

    case Qt::Key_Right : this->mirror->rotate(-1.);
        this->setLine(start.getX(), start.getY(), end.getX(), end.getY());
        break;

    case Qt::Key_Z: this->mirror->translate(0., -2.);
        this->setLine(start.getX(), start.getY(), end.getX(), end.getY());
        break;

    case Qt::Key_S: this->mirror->translate(0., 2.);
        this->setLine(start.getX(), start.getY(), end.getX(), end.getY());
        break;

    case Qt::Key_D: this->mirror->translate(2., 0.);
        this->setLine(start.getX(), start.getY(), end.getX(), end.getY());
        break;

    case Qt::Key_Q: this->mirror->translate(-2., 0.);
        this->setLine(start.getX(), start.getY(), end.getX(), end.getY());
        break;
    }
}
