#-------------------------------------------------
#
# Project created by QtCreator 2015-03-14T15:12:33
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++0x -pedantic-errors

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Starlight
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    model/crystal.cpp \
    model/dest.cpp \
    model/lens.cpp \
    model/level.cpp \
    model/mirror.cpp \
    model/nuke.cpp \
    model/point.cpp \
    model/ray.cpp \
    model/source.cpp \
    model/wall.cpp \
    model/levelFactory.cpp \
    model/starlightexception.cpp \
    model/element.cpp \
    test/levelfactorytest.cpp \
    test/pointtest.cpp \
    test/crystaltest.cpp \
    test/rectangletest.cpp \
    test/linetest.cpp \
    model/geometry/utilities.cpp \
    model/geometry/rectangle.cpp \
    model/geometry/line.cpp \
    model/geometry/ellipse.cpp \
    test/ellipsetest.cpp \
    test/utilitiestest.cpp \
    test/mirrortest.cpp

HEADERS  += mainwindow.hpp \
    model/starlightexception.hpp \
    model/element.hpp \
    model/crystal.hpp \
    model/dest.hpp \
    model/lens.hpp \
    model/level.hpp \
    model/levelFactory.hpp \
    model/mirror.hpp \
    model/nuke.hpp \
    model/point.hpp \
    model/ray.hpp \
    model/source.hpp \
    model/wall.hpp \
    model/utilities.hpp \
    test/catch.hpp \
    model/geometry/utilities.hpp \
    model/geometry/rectangle.hpp \
    model/geometry/line.hpp \
    model/geometry/ellipse.hpp

FORMS    += mainwindow.ui

DISTFILES += \
    ressources/level.lvl \
    test/cinclude2dot.pl \
    test/include_hierarchy.dot
