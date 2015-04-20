#include "mirrorview.hpp"

#include "view/viewutilities.hpp"

class Point;

MirrorView::MirrorView(Mirror * mirror, QWidget *parent)
    : QWidget(parent), mirror{mirror} {}

MirrorView::~MirrorView() {}

