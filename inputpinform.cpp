#include "inputpinform.h"
#include "mainwindow.h"
#include "nodeform.h"
#include "outputpinform.h"
#include "scriptpaintform.h"

InputPinForm::InputPinForm(QWidget* parent) : PinForm(parent),
	link(nullptr)
{

}

InputPinForm::~InputPinForm()
{

}

void InputPinForm::mousePressEvent(QMouseEvent* event)
{
	if (getNodeForm()->getNodeCall() == INVALID_NODE_CALL)
		return;

	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();
	QPoint position = mapTo(scriptPaintForm, event->pos());
	if (link)
	{
		scriptPaintForm->setCurrentNodeLinkBeginPin(link->getBeginPin());
		scriptPaintForm->setCurrentNodeLinkEndPosition(position);
		getMainWindow()->removeLink(link);
		link = nullptr;
	}
	else
	{
		scriptPaintForm->setCurrentNodeLinkBeginPosition(position);
		scriptPaintForm->setCurrentNodeLinkEndPin(this);
	}
	scriptPaintForm->setIsDraggingLink(true);
	scriptPaintForm->repaint();
}

void InputPinForm::mouseMoveEvent(QMouseEvent* event)
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();

	if (scriptPaintForm->isCurrentNodeLinkBeginPinConnected())
		moveMouseFromBeginPin(event);

	else
		moveMouseFromEndPin(event);
}

void InputPinForm::mouseReleaseEvent(QMouseEvent* event)
{
	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();

	if (scriptPaintForm->isCurrentNodeLinkBeginPinConnected())
		releaseMouseFromBeginPin(event);

	else
		releaseMouseFromEndPin(event);
}

void InputPinForm::setLinkDirty()
{
	if (link)
		link->setDirty();
}

void InputPinForm::plugLink(NodeLink* link)
{
	setLink(link);
}

void InputPinForm::unplugLink(NodeLink* link)
{
	assert(this->link == nullptr || this->link == link);
	removeLink();
}

