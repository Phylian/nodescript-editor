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
#include "mainwindow.h"
#include "outputpinform.h"
#include "inputpinform.h"

NodeForm::NodeForm(Node* node) :
	ui(new Ui::NodeForm),
	nodeFormDragger(nullptr),
	node(node),
	nodeCall(INVALID_NODE_CALL)
{
	ui->setupUi(this);
	ui->label->setText(node->getNodeName());
}

NodeForm::~NodeForm()
{
	delete ui;
}

void NodeForm::addInputValuePin(const char *name, PinIndex pinIndex)
{
	InputValuePinForm* inputValuePinForm = new InputValuePinForm(name, pinIndex);
	ui->inputPinsFrame->layout()->addWidget(inputValuePinForm);
}

void NodeForm::addInputImpulsePin(const char *name, PinIndex pinIndex)
{
	InputImpulsePinForm* inputImpulsePinForm = new InputImpulsePinForm(name, pinIndex);
	ui->inputPinsFrame->layout()->addWidget(inputImpulsePinForm);
}

void NodeForm::addOutputValuePin(const char *name, PinIndex pinIndex)
{
	OutputValuePinForm* outputValuePinForm = new OutputValuePinForm(name, pinIndex);
	ui->outputPinsFrame->layout()->addWidget(outputValuePinForm);
}

void NodeForm::addOutputImpulsePin(const char *name, PinIndex pinIndex)
{
	OutputImpulsePinForm* outputImpulsePinForm = new OutputImpulsePinForm(name, pinIndex);
	ui->outputPinsFrame->layout()->addWidget(outputImpulsePinForm);
}

OutputPinForm* NodeForm::getOutputPinForm(PinIndex pinIndex) const
{
	OutputPinForm* outputPinForm = nullptr;
	for (QObject* child : ui->outputPinsFrame->children())
	{
		if (OutputPinLineForm* outputPinLineForm = dynamic_cast<OutputPinLineForm*>(child))
		{
			OutputPinForm* pinForm = outputPinLineForm->getOutputPinForm();
			if (pinForm->getPinIndex() == pinIndex)
			{
				outputPinForm = pinForm;
				break;
			}
		}
	}
	return outputPinForm;
}

InputPinForm* NodeForm::getInputPinForm(PinIndex pinIndex) const
{
	InputPinForm* inputPinForm = nullptr;
	for (QObject* child : ui->inputPinsFrame->children())
	{
		if (InputPinLineForm* inputPinLineForm = dynamic_cast<InputPinLineForm*>(child))
		{
			InputPinForm* pinForm = inputPinLineForm->getInputPinForm();
			if (pinForm->getPinIndex() == pinIndex)
			{
				inputPinForm = pinForm;
				break;
			}
		}
	}
	return inputPinForm;
}

void NodeForm::addFieldToFieldsFrame(QWidget* fieldForm)
{
	ui->fieldsFrame->layout()->addWidget(fieldForm);
}

const QObjectList& NodeForm::getFieldsFromFieldsFrame() const
{
	return ui->fieldsFrame->children();
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

void NodeForm::mouseDoubleClickEvent(QMouseEvent* event)
{
	if (nodeCall == INVALID_NODE_CALL)
	{
		MainWindow* mainWindow = dynamic_cast<MainWindow*>(window());
		assert(mainWindow);
		NodeForm* nodeForm = mainWindow->buildNodeFormFromNode(node);
		mainWindow->addNodeFormInstance(nodeForm);
	}
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
	ScriptPaintForm* scriptPaintForm = dynamic_cast<ScriptPaintForm*>(parent());
	assert(scriptPaintForm);
	return scriptPaintForm;
}

void NodeForm::setLinksDirty()
{
	for (QObject* child : ui->inputPinsFrame->children())
	{
		if (InputValuePinForm* inputValuePinForm = dynamic_cast<InputValuePinForm*>(child))
		{
			inputValuePinForm->setLinkDirty();
		}
		else if (InputImpulsePinForm* inputImpulsePinForm = dynamic_cast<InputImpulsePinForm*>(child))
		{
			inputImpulsePinForm->setLinkDirty();
		}
	}

	for (QObject* child : ui->outputPinsFrame->children())
	{
		if (OutputValuePinForm* outputValuePinForm = dynamic_cast<OutputValuePinForm*>(child))
		{
			outputValuePinForm->setLinksDirty();
		}
		else if (OutputImpulsePinForm* outputImpulsePinForm = dynamic_cast<OutputImpulsePinForm*>(child))
		{
			outputImpulsePinForm->setLinksDirty();
		}
	}
}

void NodeForm::disableFields()
{
	for (QObject* child : ui->fieldsFrame->children())
	{
		if (ConstantValueFieldForm* constantValueFieldForm = dynamic_cast<ConstantValueFieldForm*>(child))
			constantValueFieldForm->disableField();
	}
}

