#include "model/line.hpp"

Line::Line(double slope, double indepTerm, double xValue)
    : slope{slope}, indepTerm{indepTerm}, xValue{xValue} {}

Point * Line::getIntersectionPoint(const Line & line) const
{
    Point * intersec = 0;

    if (!utilities::equals(this->getSlope(), line.getSlope()))
    {
        double x, y;
        x = this->isVertical() ? this->xValue
                               : (this->indepTerm - line.indepTerm) /
                                 (line.slope - this->slope);

        y = this->isVertical() ? line.slope * x + line.indepTerm
                               : this->slope * x + this->indepTerm;

        intersec = new Point{x, y};
    }

    return intersec;
}

bool Line::includes(const Point & point) const
{
    return this->isVertical() ?
                utilities::equals(point.getX(), this->xValue)
              : utilities::equals(point.getY(), ((this->slope * point.getX()) + this->indepTerm));
}

double Line::getSlope() const
{
    return this->slope;
}

double Line::getIndepTerm() const
{
    return this->indepTerm;
}

double Line::getXValue() const
{
    return this->xValue;
}

bool Line::isVertical() const
{
    return std::isinf(this->slope);
}

bool Line::operator ==(const Line & line) const
{
    return utilities::equals(this->slope, line.slope)
            && utilities::equals(this->indepTerm, line.indepTerm)
            && utilities::equals(this->xValue, line.xValue);
}

bool Line::operator !=(const Line & line) const
{
    return !(*this == line);
}
std::ostream & operator<<(std::ostream & out, const Line & line)
{
    out << "Equation de la droite ≡ ";

    if(line.isVertical())
    {
        out << "x = " << line.getXValue();
    }
    else
    {
        out << "y = "
            << line.getSlope() << "x + "
            << line.getIndepTerm();
    }

    return out;
}
