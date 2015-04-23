#include "sourceview.hpp"

#include <QCursor>
#include <QtMultimedia/QSound>

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
    this->brush.setColor(!this->source->isOn()
                         ? QSound::play(":/fire/sounds/fire.wav"), Qt::yellow
                         : (QSound::play(":/off/sounds/off.wav"), Qt::white));
    this->setBrush(this->brush);
    this->source->setOn(!this->source->isOn());
}

void SourceView::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    this->switchSource();
    QGraphicsRectItem::mousePressEvent(event);
}

