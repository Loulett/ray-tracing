#-------------------------------------------------
#
# Project created by QtCreator 2016-04-16T17:12:40
#
#-------------------------------------------------

QT       += core gui widgets
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ray-tracing
TEMPLATE = app

#QMAKE_CXX = "C:\Program Files\LLVM\bin\clang++.exe"
#QMAKE_CXXFLAGS = $$replace(QMAKE_CXXFLAGS, "-fno-keep-inline-dllexport", "")

QMAKE_CXXFLAGS += -std=gnu++14 -Wall -Wextra -fpermissive
#QMAKE_CXXFLAGS += -Weverything -Reverything -Wno-shadow-field-in-constructor -Wno-missing-prototypes -Wno-global-constructors -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-dollar-in-identifier-extension


SOURCES += main.cpp monitor.cpp point.cpp object.cpp ray.cpp scene.cpp widget.cpp

HEADERS  += monitor.h point.h object.h ray.h scene.h widget.h

FORMS    +=

DISTFILES += input.txt
