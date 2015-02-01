#include "nodeform.h"
#include "ui_nodeform.h"

#include <QMouseEvent>

#include "inputvaluepinform.h"
#include "inputimpulsepinform.h"
#include "outputvaluepinform.h"
#include "outputimpulsepinform.h"
#include "nodedragger.h"

NodeForm::NodeForm(QWidget *parent, const char* nodeName, NodeDragger& nodeDragger) :
    QWidget(parent),
    ui(new Ui::NodeForm),
    nodeDragger(nodeDragger)
{
    ui->setupUi(this);
    ui->label->setText(nodeName);
}

NodeForm::~NodeForm()
{
    delete ui;
}

void NodeForm::addInputValuePin(const char *name)
{
    InputValuePinForm* inputValuePinForm = new InputValuePinForm(name);
    ui->pinsFrame->layout()->addWidget(inputValuePinForm);
}

void NodeForm::addInputImpulsePin(const char *name)
{
    InputImpulsePinForm* inputImpulsePinForm = new InputImpulsePinForm(name);
    ui->pinsFrame->layout()->addWidget(inputImpulsePinForm);
}

void NodeForm::addOutputValuePin(const char *name)
{
    OutputValuePinForm* outputValuePinForm = new OutputValuePinForm(name);
    ui->pinsFrame->layout()->addWidget(outputValuePinForm);
}

void NodeForm::addOutputImpulsePin(const char *name)
{
    OutputImpulsePinForm* outputImpulsePinForm = new OutputImpulsePinForm(name);
    ui->pinsFrame->layout()->addWidget(outputImpulsePinForm);
}

void NodeForm::mousePressEvent(QMouseEvent *event)
{
    nodeDragger.beginDrag(this, event->pos());
}

void NodeForm::mouseReleaseEvent(QMouseEvent *event)
{
    nodeDragger.endDrag();
}

void NodeForm::mouseMoveEvent(QMouseEvent *event)
{
    nodeDragger.drag(event->pos());
}

