#include "mainwindow.hpp"
#include <QApplication>
#include "model/level.hpp"
#include "model/geometryUtilities.hpp"

int main(int argc, char *argv[])
{
 /*   QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

    Level *l = levelFactory::getLevelFromFile("ressources/level.lvl");

    return 0;
    */
/*
    double b, c;

    geometryUtilities::secondDegreeEquationSolver(0.5, 0, -2, &b, &c);

    std::cout << b << std::endl;
    std::cout << c << std::endl;

  */
    Point a, b;
    geometryUtilities::intersecPointsLineCircle(1, 2, Point{1, 2}, 2, &a, &b);

    std::cout << "(" << a.getX()  << " , " << a.getY() << ")" << std::endl;
    std::cout << "(" << b.getX()  << " , " << b.getY() << ")" << std::endl;


}
