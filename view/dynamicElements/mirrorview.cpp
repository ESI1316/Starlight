#include "mirrorview.hpp"

mirrorView::mirrorView(Mirror * mirror, QWidget *parent)
    : QGraphicsView(parent), mirror{mirror}
{

}

mirrorView::~mirrorView()
{

}

