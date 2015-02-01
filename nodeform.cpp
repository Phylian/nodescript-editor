#include "nodeform.h"
#include "ui_nodeform.h"

#include <QMouseEvent>

#include "inputvaluepinform.h"
#include "inputimpulsepinform.h"
#include "outputvaluepinform.h"
#include "outputimpulsepinform.h"
#include "nodedragger.h"

NodeForm::NodeForm(const char* nodeName) :
    ui(new Ui::NodeForm),
    nodeDragger(nullptr)
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
    if (nodeDragger)
        nodeDragger->beginDrag(this, event->pos());
}

void NodeForm::mouseReleaseEvent(QMouseEvent *event)
{
    if (nodeDragger)
        nodeDragger->endDrag();
}

void NodeForm::mouseMoveEvent(QMouseEvent *event)
{
    if (nodeDragger)
        nodeDragger->drag(event->pos());
}

