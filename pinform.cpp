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
		if (!inputPinForm->isConnected())
		{
			const NodeLink& link = scriptPaintForm->getCurrentLink();
			Script* script = getScript();
			NodeCall nodeCall1 = link.getBeginPinNodeCall();
			PinIndex outputPinIndex = link.getBeginPinIndex();
			NodeCall nodeCall2 = inputPinForm->getNodeCall();
			PinIndex inputPinIndex = inputPinForm->getPinIndex();

			if (script->isLinkValid(nodeCall1, outputPinIndex, nodeCall2, inputPinIndex))
				setCursor(Qt::CursorShape::ArrowCursor);

			else
				setCursor(Qt::CursorShape::ForbiddenCursor);
		}
		else
			setCursor(Qt::CursorShape::ForbiddenCursor);
	}
	else if (getOutputPinFormUnderCursor(event))
		setCursor(Qt::CursorShape::ForbiddenCursor);

	else
		setCursor(Qt::CursorShape::ArrowCursor);

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
		const NodeLink& link = scriptPaintForm->getCurrentLink();
		Script* script = getScript();
		NodeCall nodeCall1 = outputPinForm->getNodeCall();
		PinIndex outputPinIndex = outputPinForm->getPinIndex();
		NodeCall nodeCall2 = link.getEndPinNodeCall();
		PinIndex inputPinIndex = link.getEndPinIndex();

		if (script->isLinkValid(nodeCall1, outputPinIndex, nodeCall2, inputPinIndex))
			setCursor(Qt::CursorShape::ArrowCursor);

		else
			setCursor(Qt::CursorShape::ForbiddenCursor);
	}
	else if (getInputPinFormUnderCursor(event))
		setCursor(Qt::CursorShape::ForbiddenCursor);

	else
		setCursor(Qt::CursorShape::ArrowCursor);

	scriptPaintForm->repaint();
}

void PinForm::releaseMouseFromBeginPin(QMouseEvent* event)
{
	if (getNodeForm()->getNodeCall() == INVALID_NODE_CALL)
		return;

	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();

	if (InputPinForm* inputPinForm = getInputPinFormUnderCursor(event))
	{
		if (!inputPinForm->isConnected())
		{
			const NodeLink& link = scriptPaintForm->getCurrentLink();
			Script* script = getScript();
			NodeCall nodeCall1 = link.getBeginPinNodeCall();
			PinIndex outputPinIndex = link.getBeginPinIndex();
			NodeCall nodeCall2 = inputPinForm->getNodeCall();
			PinIndex inputPinIndex = inputPinForm->getPinIndex();

			if (script->isLinkValid(nodeCall1, outputPinIndex, nodeCall2, inputPinIndex))
			{
				scriptPaintForm->setIsDraggingLink(false);
				getMainWindow()->addLink(nodeCall1, outputPinIndex, nodeCall2, inputPinIndex);
			}
			else
				abortLinkDragging();
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
		const NodeLink& link = scriptPaintForm->getCurrentLink();
		Script* script = getScript();
		NodeCall nodeCall1 = outputPinForm->getNodeCall();
		PinIndex outputPinIndex = outputPinForm->getPinIndex();
		NodeCall nodeCall2 = link.getEndPinNodeCall();
		PinIndex inputPinIndex = link.getEndPinIndex();

		if (script->isLinkValid(nodeCall1, outputPinIndex, nodeCall2, inputPinIndex))
		{
			scriptPaintForm->setIsDraggingLink(false);
			getMainWindow()->addLink(nodeCall1, outputPinIndex, nodeCall2, inputPinIndex);
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
	setCursor(Qt::CursorShape::ArrowCursor);
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

