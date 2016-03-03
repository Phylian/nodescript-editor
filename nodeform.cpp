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
#include "nodeformselection.h"

QString NodeForm::stylesheet;

NodeForm::NodeForm(Node* node) :
	ui(new Ui::NodeForm),
	node(node),
	nodeCall(INVALID_NODE_CALL),
	selected(false)
{
	ui->setupUi(this);
	ui->nodeLabel->setText(node->getNodeName());

	if (stylesheet.size() == 0)
	{
		stylesheet = styleSheet();
	}
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
	if (NodeFormDragger* dragger = getNodeFormDragger())
	{
		NodeFormSelection& selection = getNodeFormSelection();
		bool ctrlPressed = (QApplication::queryKeyboardModifiers() & Qt::ControlModifier) == Qt::ControlModifier;
		if (!ctrlPressed)
			selection.removeAll();

		if (isSelected())
			selection.remove(this);

		else
			selection.add(this);

		ScriptPaintForm* scriptPaintForm = getScriptPaintForm();
		dragger->beginDrag(mapTo(scriptPaintForm, event->pos()));
	}
}

void NodeForm::mouseReleaseEvent(QMouseEvent* /*event*/)
{
	if (NodeFormDragger* nodeFormDragger = getNodeFormDragger())
	{
		nodeFormDragger->endDrag();
	}
}

void NodeForm::mouseMoveEvent(QMouseEvent *event)
{
	if (NodeFormDragger* nodeFormDragger = getNodeFormDragger())
	{
		ScriptPaintForm* scriptPaintForm = getScriptPaintForm();
		nodeFormDragger->drag(mapTo(scriptPaintForm, event->pos()));
	}
}

void NodeForm::mouseDoubleClickEvent(QMouseEvent* /*event*/)
{
	MainWindow* mainWindow = getMainWindow();
	if (nodeCall == INVALID_NODE_CALL)
	{
		NodeForm* nodeForm = mainWindow->buildNodeFormFromNode(node);
		mainWindow->addNodeFormInstance(nodeForm);
	}
	else
	{
		mainWindow->removeNodeFormInstance(this);
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

ScriptPaintForm* NodeForm::getScriptPaintForm() const
{
	assert(dynamic_cast<ScriptPaintForm*>(parent()));
	return static_cast<ScriptPaintForm*>(parent());
}

MainWindow* NodeForm::getMainWindow() const
{
	assert(dynamic_cast<MainWindow*>(window()));
	return static_cast<MainWindow*>(window());
}

NodeFormDragger* NodeForm::getNodeFormDragger() const
{
	if (nodeCall == INVALID_NODE_CALL)
		return nullptr;

	return &getMainWindow()->getNodeFormDragger();
}

NodeFormSelection& NodeForm::getNodeFormSelection() const
{
	return getMainWindow()->getNodeFormSelection();
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

void NodeForm::setSelected(bool selected)
{
	this->selected = selected;
	if (selected)
	{
		setStyleSheet("#nodeLabel { font-weight: bold; }");
	}
	else
	{
		setStyleSheet("");
	}
}

