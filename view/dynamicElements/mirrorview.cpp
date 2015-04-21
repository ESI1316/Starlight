#include "mirrorview.hpp"

#include "view/viewutilities.hpp"

class Point;

MirrorView::MirrorView(Mirror * mirror)
    : QGraphicsLineItem(), mirror{mirror} {}

MirrorView::~MirrorView() {}

