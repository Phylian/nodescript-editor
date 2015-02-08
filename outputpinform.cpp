#include "outputpinform.h"
#include "scriptpaintform.h"
#include "nodeform.h"
#include "inputpinform.h"
#include "mainwindow.h"
#include <QMouseEvent>
#include <algorithm>
#include <iostream>

OutputPinForm::OutputPinForm(QWidget *parent) : PinForm(parent)
{

}

OutputPinForm::~OutputPinForm()
{

}

void OutputPinForm::mousePressEvent(QMouseEvent* event)
{
	if (getNodeForm()->getNodeCall() == INVALID_NODE_CALL)
		return;

	ScriptPaintForm* scriptPaintForm = getScriptPaintForm();

	scriptPaintForm->setIsDraggingLink(true);
	scriptPaintForm->setCurrentNodeLinkBeginPin(this);
	scriptPaintForm->setCurrentNodeLinkEndPosition(mapTo(scriptPaintForm, event->pos()));
	scriptPaintForm->repaint();
}

void OutputPinForm::mouseMoveEvent(QMouseEvent* event)
{
	moveMouseFromBeginPin(event);
}

void OutputPinForm::mouseReleaseEvent(QMouseEvent* event)
{
	releaseMouseFromBeginPin(event);
}

void OutputPinForm::addLink(NodeLink* link)
{
	assert(std::find(links.begin(), links.end(), link) == links.end());
	links.push_back(link);
}

void OutputPinForm::removeLink(NodeLink* link)
{
	std::vector<NodeLink*>::iterator it = std::find(links.begin(), links.end(), link);
	assert(it != links.end());
	links.erase(it);
}

void OutputPinForm::setLinksDirty()
{
	for (NodeLink* link : links)
		link->setDirty();
}

void OutputPinForm::plugLink(NodeLink* link)
{
	addLink(link);
}

void OutputPinForm::unplugLink(NodeLink* link)
{
	removeLink(link);
}


