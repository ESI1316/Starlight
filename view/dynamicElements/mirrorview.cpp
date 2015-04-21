#include "mirrorview.hpp"

#include "view/viewutilities.hpp"
#include <QLineF>
#include <QCursor>


MirrorView::MirrorView(Mirror * mirror)
    : QGraphicsLineItem(QLineF{viewUtilities::toQPoint(mirror->getStart()),
                        viewUtilities::toQPoint(mirror->getEnd())}), mirror{mirror}
{
    QPen pen{QColor{204, 204, 255}};

    pen.setWidth(2);

    this->setPen(pen);
    QGraphicsLineItem::setCursor(QCursor(Qt::PointingHandCursor));
}

MirrorView::~MirrorView() {}

