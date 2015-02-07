#include "outputpinform.h"
#include "scriptpaintform.h"
#include "nodeform.h"
#include "inputpinform.h"
#include <QMouseEvent>
#include <iostream>

OutputPinForm::OutputPinForm(QWidget *parent) : QFrame(parent)
{

}

OutputPinForm::~OutputPinForm()
{

}

void OutputPinForm::mousePressEvent(QMouseEvent* event)
{
	getScriptPaintForm()->setIsDraggingLink(true);
	getScriptPaintForm()->setCurrentNodeLinkBeginPin(this);
	getScriptPaintForm()->setCurrentNodeLinkEndPosition(mapTo(getScriptPaintForm(), event->pos()));
	getScriptPaintForm()->repaint();
}

void OutputPinForm::mouseMoveEvent(QMouseEvent* event)
{
	getScriptPaintForm()->setCurrentNodeLinkEndPosition(mapTo(getScriptPaintForm(), event->pos()));
	getScriptPaintForm()->repaint();
}

void OutputPinForm::mouseReleaseEvent(QMouseEvent* event)
{
	QWidget* widget = getScriptPaintForm()->childAt(mapTo(getScriptPaintForm(), event->pos()));
	if (InputPinForm* inputPinForm = dynamic_cast<InputPinForm*>(widget))
	{
		getScriptPaintForm()->setCurrentNodeLinkEndPin(inputPinForm);
		getScriptPaintForm()->addCurrentNodeLink();
	}
	else
	{
		getScriptPaintForm()->setCurrentNodeLinkBeginPin(nullptr);
		getScriptPaintForm()->setIsDraggingLink(false);
	}
	getScriptPaintForm()->repaint();
}

ScriptPaintForm* OutputPinForm::getScriptPaintForm()
{
	return dynamic_cast<NodeForm*>(parent()->parent()->parent()->parent())->getScriptPaintForm();
}

