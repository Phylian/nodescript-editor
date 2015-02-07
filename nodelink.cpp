#include "nodelink.h"
#include "scriptpaintform.h"
#include "outputpinform.h"
#include "inputpinform.h"

NodeLink::NodeLink(ScriptPaintForm* scriptPaintForm) :
	scriptPaintForm(scriptPaintForm),
	beginPin(nullptr),
	endPin(nullptr)
{

}

void NodeLink::paint(QPainter& painter)
{
	updatePath();
	painter.drawPath(path);
}

void NodeLink::updatePath()
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
}

void NodeLink::updateBeginPosition()
{
	if (beginPin != nullptr)
	{
		QPoint point(7, 4);
		beginPosition = beginPin->mapTo(scriptPaintForm, point);
	}
}

void NodeLink::updateEndPosition()
{
	if (endPin != nullptr)
	{
		QPoint point(1, 4);
		endPosition = endPin->mapTo(scriptPaintForm, point);
	}
}
