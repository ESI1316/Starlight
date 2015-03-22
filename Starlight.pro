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
    model/levelFactory.cpp

HEADERS  += mainwindow.hpp \
    model/crystal.h \
    model/dest.h \
    model/lens.h \
    model/level.h \
    model/mirror.h \
    model/nuke.h \
    model/point.h \
    model/ray.h \
    model/source.h \
    model/wall.h \
    model/polarPoint.h \
    model/levelFactory.h

FORMS    += mainwindow.ui
