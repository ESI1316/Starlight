#include "mirrorview.hpp"

#include "view/viewutilities.hpp"

MirrorView::mirrorView(Mirror * mirror, QWidget *parent)
    : QWidget(parent), mirror{mirror} {}

MirrorView::~MirrorView() {}

void MirrorView::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    //viewUtilities::drawLine(, , painter, Qt::blue, 2);
}
