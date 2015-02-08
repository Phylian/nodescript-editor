#include "inputpinform.h"
#include "mainwindow.h"
#include "outputpinform.h"
#include "pinform.h"
#include "scriptpaintform.h"

PinForm::PinForm(QWidget* parent) : QFrame(parent),
	pinIndex(INVALID_PIN_INDEX)
{

}

PinForm::~PinForm()
{

}

void PinForm::moveMouseFromBeginPin(QMouseEvent* event)
{
	if (getNodeForm()->getNodeCall() == INVALID_NODE_CALL)
		return;

	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();

	scriptPaintForm->setCurrentNodeLinkEndPosition(mapTo(scriptPaintForm, event->pos()));
	if (InputPinForm* inputPinForm = getInputPinFormUnderCursor(event))
	{
		Script* script = getScript();
		NodeCall nodeCall1 = getNodeForm()->getNodeCall();
		NodeCall nodeCall2 = inputPinForm->getNodeForm()->getNodeCall();
		if (script->isLinkValid(nodeCall1, pinIndex, nodeCall2, inputPinForm->getPinIndex()))
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

void PinForm::moveMouseFromEndPin(QMouseEvent* event)
{
	if (getNodeForm()->getNodeCall() == INVALID_NODE_CALL)
		return;

	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();
	QPoint position = mapTo(scriptPaintForm, event->pos());

	if (scriptPaintForm->isCurrentNodeLinkBeginPinConnected())
		scriptPaintForm->setCurrentNodeLinkEndPosition(position);

	else
		scriptPaintForm->setCurrentNodeLinkBeginPosition(position);

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

void PinForm::releaseMouseFromBeginPin(QMouseEvent* event)
{
	if (getNodeForm()->getNodeCall() == INVALID_NODE_CALL)
		return;

	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();

	if (InputPinForm* inputPinForm = getInputPinFormUnderCursor(event))
	{
		Script* script = getScript();
		NodeCall nodeCall1 = getNodeForm()->getNodeCall();
		NodeCall nodeCall2 = inputPinForm->getNodeForm()->getNodeCall();
		PinIndex inputPinIndex = inputPinForm->getPinIndex();
		if (script->isLinkValid(nodeCall1, pinIndex, nodeCall2, inputPinIndex))
		{
			scriptPaintForm->setIsDraggingLink(false);
			getMainWindow()->addLink(nodeCall1, pinIndex, nodeCall2, inputPinIndex);
		}
		else
			abortLinkDragging();
	}
	else
		abortLinkDragging();

	scriptPaintForm->repaint();
}

void PinForm::releaseMouseFromEndPin(QMouseEvent* event)
{
	if (getNodeForm()->getNodeCall() == INVALID_NODE_CALL)
		return;

	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();

	if (OutputPinForm* outputPinForm = getOutputPinFormUnderCursor(event))
	{
		Script* script = getScript();
		NodeCall nodeCall1 = outputPinForm->getNodeForm()->getNodeCall();
		NodeCall nodeCall2 = getNodeForm()->getNodeCall();
		if (script->isLinkValid(nodeCall1, outputPinForm->getPinIndex(), nodeCall2, pinIndex))
		{
			scriptPaintForm->setIsDraggingLink(false);
			getMainWindow()->addLink(nodeCall1, outputPinForm->getPinIndex(), nodeCall2, pinIndex);
		}
		else
			abortLinkDragging();
	}
	else
		abortLinkDragging();

	scriptPaintForm->repaint();
}

InputPinForm* PinForm::getInputPinFormUnderCursor(QMouseEvent* event) const
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();
	QWidget* widget = scriptPaintForm->childAt(mapTo(scriptPaintForm, event->pos()));
	return dynamic_cast<InputPinForm*>(widget);
}

OutputPinForm* PinForm::getOutputPinFormUnderCursor(QMouseEvent* event) const
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();
	QWidget* widget = scriptPaintForm->childAt(mapTo(scriptPaintForm, event->pos()));
	return dynamic_cast<OutputPinForm*>(widget);
}

void PinForm::abortLinkDragging()
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();
	scriptPaintForm->setIsDraggingLink(false);
	QCursor cursor(Qt::CursorShape::ArrowCursor);
	setCursor(cursor);
}

MainWindow* PinForm::getMainWindow() const
{
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(window());
	assert(mainWindow);
	return mainWindow;
}

ScriptPaintForm* PinForm::getScriptPaintForm() const
{
	return getNodeForm()->getScriptPaintForm();
}

NodeForm* PinForm::getNodeForm() const
{
	NodeForm* nodeForm = dynamic_cast<NodeForm*>(parent()->parent()->parent()->parent());
	assert(nodeForm);
	return nodeForm;
}

Script* PinForm::getScript() const
{
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(window());
	assert(mainWindow);
	return mainWindow->getScript();
}

NodeCall PinForm::getNodeCall() const
{
	return getNodeForm()->getNodeCall();
}

