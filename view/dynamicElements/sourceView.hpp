#ifndef SOURCEVIEW_HPP
#define SOURCEVIEW_HPP

#include <QWidget>
#include <QGraphicsRectItem>

#include "model/elements/source.hpp"

class SourceView : public QGraphicsRectItem
{
    Source * source;

public:

    SourceView(Source *source);
    ~SourceView();

    void switchSource();

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SOURCEVIEW_HPP
