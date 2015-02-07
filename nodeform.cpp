#include "nodeform.h"
#include "ui_nodeform.h"

#include <QMouseEvent>

#include "nodeformdragger.h"
#include "scriptpaintform.h"

#include "inputvaluepinform.h"
#include "inputimpulsepinform.h"
#include "outputvaluepinform.h"
#include "outputimpulsepinform.h"
#include "boolfieldform.h"
#include "intfieldform.h"
#include "floatfieldform.h"
#include "stringfieldform.h"

NodeForm::NodeForm(Node* node) :
	ui(new Ui::NodeForm),
	nodeFormDragger(nullptr),
	node(node)
{
	ui->setupUi(this);
	ui->label->setText(node->getNodeName());
}

NodeForm::~NodeForm()
{
	delete ui;
}

void NodeForm::addInputValuePin(const char *name)
{
	InputValuePinForm* inputValuePinForm = new InputValuePinForm(name);
	ui->inputPinsFrame->layout()->addWidget(inputValuePinForm);
}

void NodeForm::addInputImpulsePin(const char *name)
{
	InputImpulsePinForm* inputImpulsePinForm = new InputImpulsePinForm(name);
	ui->inputPinsFrame->layout()->addWidget(inputImpulsePinForm);
}

void NodeForm::addOutputValuePin(const char *name)
{
	OutputValuePinForm* outputValuePinForm = new OutputValuePinForm(name);
	ui->outputPinsFrame->layout()->addWidget(outputValuePinForm);
}

void NodeForm::addOutputImpulsePin(const char *name)
{
	OutputImpulsePinForm* outputImpulsePinForm = new OutputImpulsePinForm(name);
	ui->outputPinsFrame->layout()->addWidget(outputImpulsePinForm);
}

void NodeForm::addBoolField(const char* name)
{
	BoolFieldForm* boolFieldForm = new BoolFieldForm(name);
	ui->fieldsFrame->layout()->addWidget(boolFieldForm);
}

void NodeForm::addIntField(const char* name)
{
	IntFieldForm* intFieldForm = new IntFieldForm(name);
	ui->fieldsFrame->layout()->addWidget(intFieldForm);
}

void NodeForm::addFloatField(const char* name)
{
	FloatFieldForm* floatFieldForm = new FloatFieldForm(name);
	ui->fieldsFrame->layout()->addWidget(floatFieldForm);
}

void NodeForm::addStringField(const char* name)
{
	StringFieldForm* stringFieldForm = new StringFieldForm(name);
	ui->fieldsFrame->layout()->addWidget(stringFieldForm);
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

void NodeForm::fillBlanks()
{
	QFrame* inputPinsFiller = new QFrame();
	inputPinsFiller->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
	ui->inputPinsFrame->layout()->addWidget(inputPinsFiller);
	QFrame* outputPinsFiller = new QFrame();
	outputPinsFiller->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
	ui->outputPinsFrame->layout()->addWidget(outputPinsFiller);
}

ScriptPaintForm* NodeForm::getScriptPaintForm()
{
	return dynamic_cast<ScriptPaintForm*>(parent());
}

