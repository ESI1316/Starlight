#ifndef POLARCOORDINATE_HPP
#define POLARCOORDINATE_HPP
#include<model/point.h>
#include<ostream>
#include<string>

class PolarCoordinate
{
    int radius;
    double beta;

public:
    PolarCoordinate();
    PolarCoordinate(int, double);
    PolarCoordinate(Point &);
    PolarCoordinate(PolarCoordinate &);
    ~PolarCoordinate();

    int getRadius() const;
    double getBeta() const;
    Point toCartesian();
    PolarCoordinate & rotate(double);
    std::string toString() const;

    friend std::ostream & operator<<(std::ostream &, PolarCoordinate &);
};

#endif // POLARCOORDINATE_HPP
