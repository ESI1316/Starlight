#include "model/geometry/line.hpp"

#include "model/point.hpp"
#include "model/geometry/utilities.hpp"

Line::Line(double slope, double indepTerm, double xValue)
    : slope{slope}, indepTerm{indepTerm}, xValue{xValue} {}

Point * Line::getIntersectionPoint(const Line & line) const
{
    Point * intersec = 0;

    if (!utilities::equals(this->getSlope(), line.getSlope()))
    {
        double x, y;

        if (this->isVertical())
        {
            x = this->xValue;
            y = line.slope * x + line.indepTerm;
        }
        else if (line.isVertical())
        {
            x = line.xValue;
            y = this->slope * x + this->indepTerm;
        }
        else
        {
            x = (this->indepTerm - line.indepTerm) / (line.slope - this->slope);
            y = this->slope * x + this->indepTerm;
        }

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

double Line::findX(const double y) const
{
    return this->isVertical() ?
                this->indepTerm : (y - this->getIndepTerm()) / this->slope;
}

double Line::findY(const double x) const
{
    return (this->isVertical()) ? x : this->slope * x + this->indepTerm;
}

bool Line::isVertical() const
{
    return std::isinf(this->slope);
}

bool Line::operator ==(const Line & line) const
{
    bool equals = false;

    if (this->isVertical() && line.isVertical())
        equals = utilities::equals(this->xValue, line.xValue);
    else
        equals = utilities::equals(this->slope, line.slope)
                && utilities::equals(this->indepTerm, line.indepTerm);

    return equals;
}

bool Line::operator !=(const Line & line) const
{
    return !(*this == line);
}

std::ostream & operator<<(std::ostream & out, const Line & line)
{
    out << "Equation de la droite ≡ ";

    if(line.isVertical())
        out << "x = " << line.getXValue();
    else
        out << "y = " << line.getSlope() << "x + "<< line.getIndepTerm();

    return out;
}
