#include "inputpinform.h"
#include "nodeform.h"
#include "scriptpaintform.h"
#include <QPainter>

ScriptPaintForm::ScriptPaintForm(QWidget *parent) : QFrame(parent),
	currentNodeLink(this),
	isDraggingLink(false)
{

}

ScriptPaintForm::~ScriptPaintForm()
{

}

void ScriptPaintForm::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(QColor(127, 140, 141));

	for (NodeLink* nodeLink : links)
	{
		nodeLink->paint(painter);
	}

	if (isDraggingLink)
		currentNodeLink.paint(painter);
}

void ScriptPaintForm::setIsDraggingLink(bool isDraggingLink)
{
	this->isDraggingLink = isDraggingLink;
	if (!isDraggingLink)
	{
		currentNodeLink.setBeginPin(nullptr);
		currentNodeLink.setEndPin(nullptr);
	}
}

void ScriptPaintForm::setCurrentNodeLinkBeginPin(OutputPinForm* beginPin)
{
	currentNodeLink.setBeginPin(beginPin);
}

void ScriptPaintForm::setCurrentNodeLinkBeginPosition(QPoint beginPosition)
{
	currentNodeLink.setBeginPosition(beginPosition);
}

void ScriptPaintForm::setCurrentNodeLinkEndPin(InputPinForm* endPin)
{
	currentNodeLink.setEndPin(endPin);
}

void ScriptPaintForm::setCurrentNodeLinkEndPosition(QPoint endPosition)
{
	currentNodeLink.setEndPosition(endPosition);
}

void ScriptPaintForm::addLink(NodeLink* link)
{
	assert(std::find(links.begin(), links.end(), link) == links.end());
	link->connectToBeginPin();
	link->connectToEndPin();
	links.push_back(link);
}

void ScriptPaintForm::removeLink(NodeLink* link)
{
	std::vector<NodeLink*>::iterator it = std::find(links.begin(), links.end(), link);
	assert(it != links.end());
	link->disconnectFromBeginPin();
	link->disconnectFromEndPin();
	links.erase(it);
}

NodeForm* ScriptPaintForm::getNodeForm(NodeCall nodeCall) const
{
	NodeForm* nodeForm = nullptr;
	for (QObject* child : children())
	{
		if (NodeForm* nodeForm1 = dynamic_cast<NodeForm*>(child))
		{
			if (nodeForm1->getNodeCall() == nodeCall)
			{
				nodeForm = nodeForm1;
				break;
			}
		}
	}
	return nodeForm;
}



