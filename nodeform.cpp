#include "nodeform.h"
#include "ui_nodeform.h"

#include <QMouseEvent>

#include "nodeformdragger.h"

#include "inputvaluepinform.h"
#include "inputimpulsepinform.h"
#include "outputvaluepinform.h"
#include "outputimpulsepinform.h"
#include "boolfieldform.h"
#include "intfieldform.h"
#include "floatfieldform.h"
#include "stringfieldform.h"

NodeForm::NodeForm(const char* nodeName) :
    ui(new Ui::NodeForm),
    nodeFormDragger(nullptr)
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

void NodeForm::addBoolField(const char* name)
{
	BoolFieldForm* boolFieldForm = new BoolFieldForm(name);
	ui->pinsFrame->layout()->addWidget(boolFieldForm);
}

void NodeForm::addIntField(const char* name)
{
	IntFieldForm* intFieldForm = new IntFieldForm(name);
	ui->pinsFrame->layout()->addWidget(intFieldForm);
}

void NodeForm::addFloatField(const char* name)
{
	FloatFieldForm* floatFieldForm = new FloatFieldForm(name);
	ui->pinsFrame->layout()->addWidget(floatFieldForm);
}

void NodeForm::addStringField(const char* name)
{
	StringFieldForm* stringFieldForm = new StringFieldForm(name);
	ui->pinsFrame->layout()->addWidget(stringFieldForm);
}

void NodeForm::mousePressEvent(QMouseEvent *event)
{
    if (nodeFormDragger)
        nodeFormDragger->beginDrag(this, event->pos());
}

void NodeForm::mouseReleaseEvent(QMouseEvent *event)
{
    if (nodeFormDragger)
        nodeFormDragger->endDrag();
}

void NodeForm::mouseMoveEvent(QMouseEvent *event)
{
    if (nodeFormDragger)
        nodeFormDragger->drag(event->pos());
}

