#include "inputpinform.h"
#include "nodeform.h"
#include "outputpinform.h"
#include "scriptpaintform.h"
#include <iostream>

InputPinForm::InputPinForm(QWidget* parent) : QFrame(parent)
{

}

InputPinForm::~InputPinForm()
{

}

void InputPinForm::mousePressEvent(QMouseEvent* event)
{
	getScriptPaintForm()->setIsDraggingLink(true);
	getScriptPaintForm()->setCurrentNodeLinkEndPin(this);
	getScriptPaintForm()->setCurrentNodeLinkBeginPosition(mapTo(getScriptPaintForm(), event->pos()));
	getScriptPaintForm()->repaint();
}

void InputPinForm::mouseMoveEvent(QMouseEvent* event)
{
	getScriptPaintForm()->setCurrentNodeLinkBeginPosition(mapTo(getScriptPaintForm(), event->pos()));
	getScriptPaintForm()->repaint();
}

void InputPinForm::mouseReleaseEvent(QMouseEvent* event)
{
	QWidget* widget = getScriptPaintForm()->childAt(mapTo(getScriptPaintForm(), event->pos()));
	if (OutputPinForm* outputPinForm = dynamic_cast<OutputPinForm*>(widget))
	{
		getScriptPaintForm()->setCurrentNodeLinkBeginPin(outputPinForm);
		getScriptPaintForm()->addCurrentNodeLink();
	}
	else
	{
		getScriptPaintForm()->setCurrentNodeLinkEndPin(nullptr);
		getScriptPaintForm()->setIsDraggingLink(false);
	}
	getScriptPaintForm()->repaint();
}

ScriptPaintForm* InputPinForm::getScriptPaintForm()
{
	return dynamic_cast<NodeForm*>(parent()->parent()->parent()->parent())->getScriptPaintForm();
}

