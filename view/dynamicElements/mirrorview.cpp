#include "mirrorview.hpp"

#include "view/viewutilities.hpp"
#include <QLineF>
#include <QCursor>


MirrorView::MirrorView(Mirror * mirror)
    : QGraphicsLineItem(QLineF{viewUtilities::toQPoint(mirror->getStart()),
                        viewUtilities::toQPoint(mirror->getEnd())}),
      mirror{mirror}, boundRect{}

{
    QPen pen{QColor{204, 204, 255}};

    pen.setWidth(2);

    this->setPen(pen);
    QGraphicsLineItem::setCursor(QCursor(Qt::PointingHandCursor));
    this->setFlag(QGraphicsItem::ItemIsMovable);
}

MirrorView::~MirrorView() {}

QVariant MirrorView::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange && this->scene())
    {
            QPointF newPos = value.toPointF();
            QRectF rect{};

            if (!rect.contains(newPos))
            {
                newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
                newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));

                return newPos;
            }
     }
        return QGraphicsLineItem::itemChange(change, value);
}

