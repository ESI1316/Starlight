#include "sourceView.hpp"

#include "model/geometry/utilities.hpp"

SourceView::SourceView(Source * source, QWidget * parent)
    : QPushButton(parent), source{source}
{
    Point upLeftCorner{source->getUpLeftCorner()};

    QPushButton::setGeometry(QRect {utilities::round(upLeftCorner.getX()),
                                    utilities::round(upLeftCorner.getY()),
                                    utilities::round(source->getWidth()),
                                    utilities::round(source->getHeight())});

    this->setFocusPolicy(Qt::NoFocus);
    this->setCursor(Qt::PointingHandCursor);
    this->setStyleSheet("background-color:white;");

    QObject::connect(this, SIGNAL(clicked()), this, SLOT(switchSource()));
}

SourceView::~SourceView() {}

void SourceView::switchSource()
{
    bool newOnVal = !this->source->isOn();

    this->setStyleSheet(QString( (std::string("background-color:") +
                                 (newOnVal ? std::string("yellow;")
                                           : std::string("white;"))).c_str()) );
    this->source->setOn(newOnVal);
}

