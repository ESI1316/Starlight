#include "mirrorview.hpp"

#include "view/viewutilities.hpp"
#include <QLineF>


MirrorView::MirrorView(Mirror * mirror)
    : QGraphicsLineItem(QLineF{viewUtilities::toQPoint(mirror->getStart()),
                        viewUtilities::toQPoint(mirror->getEnd())}), mirror{mirror}
{
    QPen pen{QColor{204, 204, 255}};

    pen.setWidth(2);

    this->setPen(pen);

     //this->setCursor(Qt::PointingHandCursor);
}

MirrorView::~MirrorView() {}

