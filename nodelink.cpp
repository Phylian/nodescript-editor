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

void NodeLink::operator=(const NodeLink& nodeLink)
{
	scriptPaintForm = nodeLink.scriptPaintForm;
	beginPin = nodeLink.beginPin;
	endPin = nodeLink.endPin;
	dirty = true;
}

void NodeLink::paint(QPainter& painter)
{
	updatePath();

	QPen pen;
	pen.setWidth(4);
	if (beginPin)
	{
		pen.setColor(beginPin->palette().background().color());
	}
	else if (endPin)
	{
		pen.setColor(endPin->palette().background().color());
	}
	else
		assert(false);

	painter.setPen(pen);
	painter.drawPath(path);
}

void NodeLink::connectToBeginPin()
{
	assert(beginPin);
	beginPin->addLink(this);
}

void NodeLink::disconnectFromBeginPin()
{
	if (beginPin)
		beginPin->removeLink(this);
}

void NodeLink::connectToEndPin()
{
	assert(endPin);
	endPin->setLink(this);
}

void NodeLink::disconnectFromEndPin()
{
	if (endPin)
		endPin->removeLink();
}

PinIndex NodeLink::getBeginPinIndex() const
{
	if (beginPin)
		return beginPin->getPinIndex();

	else
		return INVALID_PIN_INDEX;
}

PinIndex NodeLink::getEndPinIndex() const
{
	if (endPin)
		return endPin->getPinIndex();

	else
		return INVALID_PIN_INDEX;
}

NodeCall NodeLink::getBeginPinNodeCall() const
{
	if (beginPin)
		return beginPin->getNodeCall();

	else
		return INVALID_NODE_CALL;
}

NodeCall NodeLink::getEndPinNodeCall() const
{
	if (endPin)
		return endPin->getNodeCall();

	else
		return INVALID_NODE_CALL;
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
