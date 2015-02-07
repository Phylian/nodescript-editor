#include "outputpinform.h"
#include "scriptpaintform.h"
#include "nodeform.h"
#include "inputpinform.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <algorithm>
#include <iostream>

OutputPinForm::OutputPinForm(QWidget *parent) : QFrame(parent),
	pinIndex(INVALID_PIN_INDEX)
{

}

OutputPinForm::~OutputPinForm()
{

}

void OutputPinForm::mousePressEvent(QMouseEvent* event)
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();

	scriptPaintForm->setIsDraggingLink(true);
	scriptPaintForm->setCurrentNodeLinkBeginPin(this);
	scriptPaintForm->setCurrentNodeLinkEndPosition(mapTo(scriptPaintForm, event->pos()));
	scriptPaintForm->repaint();
}

void OutputPinForm::mouseMoveEvent(QMouseEvent* event)
{
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

void OutputPinForm::mouseReleaseEvent(QMouseEvent* event)
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();

	if (InputPinForm* inputPinForm = getInputPinFormUnderCursor(event))
	{
		Script* script = getScript();
		NodeCall nodeCall1 = getNodeForm()->getNodeCall();
		NodeCall nodeCall2 = inputPinForm->getNodeForm()->getNodeCall();
		PinIndex inputPinIndex = inputPinForm->getPinIndex();
		if (script->isLinkValid(nodeCall1, pinIndex, nodeCall2, inputPinIndex))
		{
			script->addLink(nodeCall1, pinIndex, nodeCall2, inputPinIndex);

			scriptPaintForm->setCurrentNodeLinkEndPin(inputPinForm);
			NodeLink* link = scriptPaintForm->addCurrentNodeLink();
			links.push_back(link);
			link->connectToEndPin();
		}
		else
			abortLinkDragging();
	}
	else
		abortLinkDragging();

	scriptPaintForm->repaint();
}

InputPinForm* OutputPinForm::getInputPinFormUnderCursor(QMouseEvent* event) const
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();
	QWidget* widget = scriptPaintForm->childAt(mapTo(scriptPaintForm, event->pos()));
	return dynamic_cast<InputPinForm*>(widget);
}

void OutputPinForm::abortLinkDragging()
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();
	scriptPaintForm->setCurrentNodeLinkBeginPin(nullptr);
	scriptPaintForm->setIsDraggingLink(false);
	QCursor cursor(Qt::CursorShape::ArrowCursor);
	setCursor(cursor);
}

ScriptPaintForm* OutputPinForm::getScriptPaintForm() const
{
	return getNodeForm()->getScriptPaintForm();
}

NodeForm* OutputPinForm::getNodeForm() const
{
	NodeForm* nodeForm = dynamic_cast<NodeForm*>(parent()->parent()->parent()->parent());
	assert(nodeForm);
	return nodeForm;
}

Script* OutputPinForm::getScript() const
{
	MainWindow* mainWindow = dynamic_cast<MainWindow*>(window());
	assert(mainWindow);
	return mainWindow->getScript();
}

void OutputPinForm::addLink(NodeLink* link)
{
	assert(std::find(links.begin(), links.end(), link) == links.end());
	links.push_back(link);
}

void OutputPinForm::setLinksDirty()
{
	for (NodeLink* link : links)
		link->setDirty();
}

