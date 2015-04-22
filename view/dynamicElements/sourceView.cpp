#include "sourceView.hpp"

#include <QCursor>

#include "model/elements/source.hpp"
#include "view/viewutilities.hpp"

SourceView::SourceView(Source * source)
    : QGraphicsRectItem(viewUtilities::toQRectF(*source)), source{source},
      pen{Qt::black, 4}, brush{Qt::white}
{
    this->setPen(this->pen);
    this->setBrush(this->brush);

    this->setCursor(QCursor(Qt::PointingHandCursor));
}

SourceView::~SourceView() {}

void SourceView::switchSource()
{
    this->source->setOn(!this->source->isOn());
    this->brush.setColor(this->source->isOn() ? Qt::yellow : Qt::white);
    this->setBrush(this->brush);
}

void SourceView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->switchSource();
    QGraphicsRectItem::mousePressEvent(event);
}

