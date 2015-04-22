#ifndef SOURCEVIEW_HPP
#define SOURCEVIEW_HPP

#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>

class Source;

class SourceView : public QGraphicsRectItem
{
    Source * source;
    QPen pen;
    QBrush brush;

public:

    SourceView(Source *source);
    ~SourceView();

    void switchSource();

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SOURCEVIEW_HPP
