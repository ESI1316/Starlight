#include "sourceView.hpp"

#include "view/viewutilities.hpp"

SourceView::SourceView(Source * source)
    : QGraphicsRectItem(viewUtilities::toQRectF(*source)), source{source}
{
    QPen pen{Qt::black};

    pen.setWidth(4);

    this->setPen(pen);
    this->setBrush(QBrush{Qt::white});
    this->setCursor(Qt::PointingHandCursor);
}

SourceView::~SourceView() {}

void SourceView::switchSource()
{
    this->source->setOn(!this->source->isOn());
    this->setBrush(QBrush{this->source->isOn() ? Qt::yellow : Qt::white});
}

void SourceView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->switchSource();
    QGraphicsRectItem::mousePressEvent(event);
}

