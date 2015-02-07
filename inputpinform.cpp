#include "inputpinform.h"
#include "mainwindow.h"
#include "nodeform.h"
#include "outputpinform.h"
#include "scriptpaintform.h"

InputPinForm::InputPinForm(QWidget* parent) : QFrame(parent),
	link(nullptr),
	pinIndex(INVALID_PIN_INDEX)
{

}

InputPinForm::~InputPinForm()
{

}

void InputPinForm::mousePressEvent(QMouseEvent* event)
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();

	scriptPaintForm->setIsDraggingLink(true);
	scriptPaintForm->setCurrentNodeLinkEndPin(this);
	scriptPaintForm->setCurrentNodeLinkBeginPosition(mapTo(scriptPaintForm, event->pos()));
	scriptPaintForm->repaint();
}

void InputPinForm::mouseMoveEvent(QMouseEvent* event)
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();

	scriptPaintForm->setCurrentNodeLinkBeginPosition(mapTo(scriptPaintForm, event->pos()));
	if (OutputPinForm* outputPinForm = getOutputPinFormUnderCursor(event))
	{
		Script* script = getScript();
		NodeCall nodeCall1 = outputPinForm->getNodeForm()->getNodeCall();
		NodeCall nodeCall2 = getNodeForm()->getNodeCall();
		if (script->isLinkValid(nodeCall1, outputPinForm->getPinIndex(), nodeCall2, pinIndex))
		{
			QCursor cursor(Qt::CursorShape::ArrowCursor);
			setCursor(cursor);
		}
		else
		{
			QCursor cursor(Qt::CursorShape::ForbiddenCursor);
			setCursor(cursor);
		}
	}
	else
	{
		QCursor cursor(Qt::CursorShape::ArrowCursor);
		setCursor(cursor);
	}

	scriptPaintForm->repaint();
}

void InputPinForm::mouseReleaseEvent(QMouseEvent* event)
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();

	if (OutputPinForm* outputPinForm = getOutputPinFormUnderCursor(event))
	{
		Script* script = getScript();
		NodeCall nodeCall1 = outputPinForm->getNodeForm()->getNodeCall();
		NodeCall nodeCall2 = getNodeForm()->getNodeCall();
		if (script->isLinkValid(nodeCall1, outputPinForm->getPinIndex(), nodeCall2, pinIndex))
		{
			scriptPaintForm->setCurrentNodeLinkBeginPin(outputPinForm);
			link = scriptPaintForm->addCurrentNodeLink();
			link->connectToBeginPin();
		}
		else
			abortLinkDragging();
	}
	else
		abortLinkDragging();

	scriptPaintForm->repaint();
}

OutputPinForm* InputPinForm::getOutputPinFormUnderCursor(QMouseEvent* event) const
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();
	QWidget* widget = scriptPaintForm->childAt(mapTo(scriptPaintForm, event->pos()));
	return dynamic_cast<OutputPinForm*>(widget);
}

void InputPinForm::abortLinkDragging()
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();
	scriptPaintForm->setCurrentNodeLinkBeginPin(nullptr);
	scriptPaintForm->setIsDraggingLink(false);
	QCursor cursor(Qt::CursorShape::ArrowCursor);
	setCursor(cursor);
}

ScriptPaintForm* InputPinForm::getScriptPaintForm() const
{
	return getNodeForm()->getScriptPaintForm();
}

NodeForm*InputPinForm::getNodeForm() const
{
	NodeForm* nodeForm = dynamic_cast<NodeForm*>(parent()->parent()->parent()->parent());
	assert(nodeForm);
	return nodeForm;
}

Script* InputPinForm::getScript() const
{
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(window());
	assert(mainWindow);
	return mainWindow->getScript();
}

void InputPinForm::setLinkDirty()
{
	if (link)
		link->setDirty();
}

