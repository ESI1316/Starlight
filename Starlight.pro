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
    model/polarPoint.cpp \
    model/levelFactory.cpp \
    test/polarpointtest.cpp \
    model/starlightexception.cpp \
    test/levelfactorytest.cpp \
    model/element.cpp \
    test/pointtest.cpp \
    model/utilities.cpp \
    test/crystaltest.cpp \
    model/line.cpp \
    model/rectangle.cpp \
    model/ellipse.cpp

HEADERS  += mainwindow.hpp \
    test/catch.hpp \
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
    model/polarPoint.hpp \
    model/ray.hpp \
    model/source.hpp \
    model/wall.hpp \
    model/utilities.hpp \
    model/line.h \
    model/rectangle.h \
    model/ellipse.h

FORMS    += mainwindow.ui

DISTFILES += \
    ressources/level.lvl \
    test/cinclude2dot.pl \
    test/include_hierarchy.dot
