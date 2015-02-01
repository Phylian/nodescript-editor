#-------------------------------------------------
#
# Project created by QtCreator 2015-01-27T22:44:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    nodeform.cpp \
    inputvaluepinform.cpp \
    inputimpulsepinform.cpp \
    outputvaluepinform.cpp \
    outputimpulsepinform.cpp \
    nodedragger.cpp \
    nodescript/src/functionalnode.cpp \
    nodescript/src/functionalnoderuntime.cpp \
    nodescript/src/node.cpp \
    nodescript/src/noderuntime.cpp \
    nodescript/src/pin.cpp \
    nodescript/src/pinimpulse.cpp \
    nodescript/src/pintypes.cpp \
    nodescript/src/pinvalue.cpp \
    nodescript/src/script.cpp \
    nodescript/src/scriptengine.cpp \
    nodescript/src/scriptruntime.cpp \
    nodescript/src/nodes/initnode.cpp \
    nodescript/src/nodes/testnode.cpp \
    nodescript/src/nodes/math/addnode.cpp

HEADERS  += mainwindow.h \
    nodeform.h \
    inputvaluepinform.h \
    inputimpulsepinform.h \
    outputvaluepinform.h \
    outputimpulsepinform.h \
    nodedragger.h \
    nodescript/src/debug.h \
    nodescript/src/functionalnode.h \
    nodescript/src/functionalnoderuntime.h \
    nodescript/src/node.h \
    nodescript/src/nodecall.h \
    nodescript/src/noderuntime.h \
    nodescript/src/nodescript.h \
    nodescript/src/pin.h \
    nodescript/src/pinarchetype.h \
    nodescript/src/pinimpulse.h \
    nodescript/src/pintypes.h \
    nodescript/src/pinvalue.h \
    nodescript/src/script.h \
    nodescript/src/scriptengine.h \
    nodescript/src/scriptruntime.h \
    nodescript/src/nodes/castnode.h \
    nodescript/src/nodes/constantvaluenode.h \
    nodescript/src/nodes/initnode.h \
    nodescript/src/nodes/testnode.h \
    nodescript/src/nodes/math/addnode.h

FORMS    += mainwindow.ui \
    nodeform.ui \
    inputvaluepinform.ui \
    inputimpulsepinform.ui \
    outputvaluepinform.ui \
    outputimpulsepinform.ui

CONFIG += c++11

DEFINES += NODESCRIPT_INTROSPECTION=

DISTFILES +=
