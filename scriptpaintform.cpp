#include "inputpinform.h"
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

NodeLink* ScriptPaintForm::addCurrentNodeLink()
{
	isDraggingLink = false;
	NodeLink* newLink = new NodeLink(currentNodeLink);
	links.push_back(newLink);
	return newLink;
}

