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
    nodescript/src/nodes/math/addnode.cpp \
    nodeformbuilders/nodeformbuilders.cpp \
    nodeformbuilders/nodeformbuilder.cpp \
    nodeformbuilders/nodeformbuilders/intconstantvaluenodeformbuilder.cpp \
    intfieldform.cpp \
    stringfieldform.cpp \
    nodeformbuilders/nodeformbuilders/stringconstantvaluenodeformbuilder.cpp \
    nodeformbuilders/nodeformbuilders/longconstantvaluenodeformbuilder.cpp \
    nodeformbuilders/nodeformbuilders/boolconstantvaluenodeformbuilder.cpp \
    nodeformbuilders/nodeformbuilders/floatconstantvaluenodeformbuilder.cpp \
    nodeformbuilders/nodeformbuilders/doubleconstantvaluenodeformbuilder.cpp \
    boolfieldform.cpp \
    floatfieldform.cpp \
    nodeformdragger.cpp \
    scriptpaintform.cpp \
    nodelink.cpp \
    inputpinform.cpp \
    outputpinform.cpp \
    constantvaluefieldform.cpp \
    outputpinlineform.cpp \
    inputpinlineform.cpp \
    pinform.cpp \
    essentia-nodes/essentianodes.cpp \
    essentia-nodes/nodes/monoloadernode.cpp \
    essentia-nodes/nodes/beattrackermultifeaturenode.cpp \
    nodeformselection.cpp

HEADERS  += mainwindow.h \
    nodeform.h \
    inputvaluepinform.h \
    inputimpulsepinform.h \
    outputvaluepinform.h \
    outputimpulsepinform.h \
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
    nodescript/src/nodes/math/addnode.h \
    nodeformbuilders/nodeformbuilders.h \
    nodeformbuilders/nodeformbuilder.h \
    nodeformbuilders/nodeformbuilders/intconstantvaluenodeformbuilder.h \
    intfieldform.h \
    stringfieldform.h \
    nodeformbuilders/nodeformbuilders/stringconstantvaluenodeformbuilder.h \
    nodeformbuilders/nodeformbuilders/longconstantvaluenodeformbuilder.h \
    nodeformbuilders/nodeformbuilders/boolconstantvaluenodeformbuilder.h \
    nodeformbuilders/nodeformbuilders/floatconstantvaluenodeformbuilder.h \
    nodeformbuilders/nodeformbuilders/doubleconstantvaluenodeformbuilder.h \
    boolfieldform.h \
    floatfieldform.h \
    nodeformdragger.h \
    scriptpaintform.h \
    nodelink.h \
    inputpinform.h \
    outputpinform.h \
    constantvaluefieldform.h \
    outputpinlineform.h \
    inputpinlineform.h \
    pinform.h \
    essentia-nodes/essentianodes.h \
    essentia-nodes/nodes/monoloadernode.h \
    essentia-nodes/nodes/beattrackermultifeaturenode.h \
    nodeformselection.h

FORMS    += mainwindow.ui \
    nodeform.ui \
    inputvaluepinform.ui \
    inputimpulsepinform.ui \
    outputvaluepinform.ui \
    outputimpulsepinform.ui \
    intfieldform.ui \
    stringfieldform.ui \
    boolfieldform.ui \
    floatfieldform.ui

CONFIG += c++11

DEFINES += NODESCRIPT_INTROSPECTION=1 \
    NODESCRIPT_VERBOSE=1 \
    NODESCRIPT_DEBUG=1

LIBS += -lessentia \
    -lavcodec \
    -lavformat \
    -lavutil \
    -lyaml \
    -lfftw3f \
    -ltag \
    -lsamplerate

DISTFILES +=

