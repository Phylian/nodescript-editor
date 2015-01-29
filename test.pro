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
    nodedragger.cpp

HEADERS  += mainwindow.h \
    nodeform.h \
    inputvaluepinform.h \
    inputimpulsepinform.h \
    outputvaluepinform.h \
    outputimpulsepinform.h \
    nodedragger.h

FORMS    += mainwindow.ui \
    nodeform.ui \
    inputvaluepinform.ui \
    inputimpulsepinform.ui \
    outputvaluepinform.ui \
    outputimpulsepinform.ui
