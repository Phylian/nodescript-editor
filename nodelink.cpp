#include "nodelink.h"
#include "scriptpaintform.h"
#include "outputpinform.h"
#include "inputpinform.h"

NodeLink::NodeLink(ScriptPaintForm* scriptPaintForm) :
	scriptPaintForm(scriptPaintForm),
	beginPin(nullptr),
	endPin(nullptr),
	dirty(true)
{

}

NodeLink::NodeLink(const NodeLink& nodeLink) :
	scriptPaintForm(nodeLink.scriptPaintForm),
	beginPin(nodeLink.beginPin),
	endPin(nodeLink.endPin),
	dirty(true)
{

}

void NodeLink::paint(QPainter& painter)
{
	updatePath();

	if (beginPin)
	{
		painter.setPen(beginPin->palette().background().color());
	}
	else if (endPin)
	{
		painter.setPen(endPin->palette().background().color());
	}
	else
		assert(false);

	painter.drawPath(path);
}

void NodeLink::connectToBeginPin()
{
	assert(beginPin);
	beginPin->addLink(this);
}

void NodeLink::connectToEndPin()
{
	assert(endPin);
	endPin->setLink(this);
}

void NodeLink::updatePath()
{
	if (dirty)
	{
		updateBeginPosition();
		updateEndPosition();

		path = QPainterPath();
		path.moveTo(beginPosition);

		int dx1, dx2;
		if (endPosition.x() > beginPosition.x())
		{
			dx1 = beginPosition.x() + (endPosition.x() - beginPosition.x()) * 0.6;
			dx2 = beginPosition.x() + (endPosition.x() - beginPosition.x()) * 0.4;
		}
		else
		{
			dx1 = beginPosition.x() + beginPosition.x() - endPosition.x();
			dx2 = endPosition.x() - beginPosition.x() + endPosition.x();
		}

		path.cubicTo(
			dx1, beginPosition.y(),
			dx2, endPosition.y(),
			endPosition.x(), endPosition.y()
		);

		dirty = false;
	}
}

void NodeLink::updateBeginPosition()
{
	if (beginPin)
	{
		QPoint point(beginPin->width() - 1, beginPin->height() / 2);
		beginPosition = beginPin->mapTo(scriptPaintForm, point);
	}
}

void NodeLink::updateEndPosition()
{
	if (endPin)
	{
		QPoint point(1, endPin->height() / 2);
		endPosition = endPin->mapTo(scriptPaintForm, point);
	}
}
