#-------------------------------------------------
#
# Project created by QtCreator 2015-03-14T15:12:33
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic-errors

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Starlight
TEMPLATE = app

SOURCES += main.cpp\
    view/windows/mainwindow.cpp \
    view/windows/levelview.cpp \
    view/windows/mainmenu.cpp \
    view/viewutilities.cpp \
    view/dynamicElements/mirrorview.cpp \
    view/dynamicElements/clickableColorSquare.cpp \
    model/elements/crystal.cpp \
    model/elements/dest.cpp \
    model/elements/lens.cpp \
    model/elements/level.cpp \
    model/elements/mirror.cpp \
    model/elements/nuke.cpp \
    model/elements/ray.cpp \
    model/elements/source.cpp \
    model/elements/wall.cpp \
    model/elements/levelFactory.cpp \
    model/exception/starlightexception.cpp \
    model/elements/element.cpp \
    test/elements/levelfactorytest.cpp \
    test/elements/crystaltest.cpp \
    model/geometry/point.cpp \
    model/geometry/utilities.cpp \
    model/geometry/rectangle.cpp \
    model/geometry/line.cpp \
    model/geometry/ellipse.cpp \
    test/geometry/pointtest.cpp \
    test/geometry/ellipsetest.cpp \
    test/geometry/utilitiestest.cpp \
    test/geometry/rectangletest.cpp \
    test/geometry/linetest.cpp \
    test/elements/mirrortest.cpp \
    test/elements/raytest.cpp \
    test/elements/nuketest.cpp \
    test/elements/walltest.cpp \
    test/elements/sourcetest.cpp \
    test/elements/desttest.cpp \
    test/elements/leveltest.cpp \
    test/elements/lenstest.cpp

HEADERS  += view/windows/mainwindow.hpp \
    view/windows/levelview.hpp \
    view/windows/mainmenu.hpp \
    view/dynamicElements/clickableColorSquare.hpp \
    view/dynamicElements/mirrorview.hpp \
    view/viewutilities.hpp \
    model/exception/starlightexception.hpp \
    model/elements/element.hpp \
    model/elements/crystal.hpp \
    model/elements/dest.hpp \
    model/elements/lens.hpp \
    model/elements/level.hpp \
    model/elements/levelFactory.hpp \
    model/elements/mirror.hpp \
    model/elements/nuke.hpp \
    model/elements/ray.hpp \
    model/elements/source.hpp \
    model/elements/wall.hpp \
    model/elements/utilities.hpp \
    model/geometry/point.hpp \
    model/geometry/utilities.hpp \
    model/geometry/rectangle.hpp \
    model/geometry/line.hpp \
    model/geometry/ellipse.hpp \
    test/catch.hpp

DISTFILES += \
    ressources/level.lvl \
    ressources/MW.lvl \
    ressources/W.lvl \
    ressources/N.lvl \
    ressources/ML_STOP.lvl \
    ressources/LW.lvl \
    ressources/L_STOP.lvl
