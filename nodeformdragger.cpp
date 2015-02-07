#include "nodeformdragger.h"
#include "scriptpaintform.h"

#include <cassert>

#include "nodeform.h"

NodeFormDragger::NodeFormDragger() :
	nodeForm(nullptr),
	snapToGrid(false)
{

}

NodeFormDragger::~NodeFormDragger()
{

}

void NodeFormDragger::beginDrag(NodeForm *nodeForm, QPoint offset)
{
	assert(nodeForm != nullptr);
	assert(this->nodeForm == nullptr);
	this->nodeForm = nodeForm;
	this->offset = offset;
	QCursor cursor(Qt::CursorShape::DragMoveCursor);
	this->nodeForm->setCursor(cursor);
}

void NodeFormDragger::drag(QPoint mousePosition)
{
	assert(nodeForm != nullptr);

	QPoint move = nodeForm->mapToParent(mousePosition - offset);

	if (snapToGrid)
	{
		const int gridCellSize = 20;
		move = QPoint(
			round(static_cast<float>(move.x()) / gridCellSize) * gridCellSize,
			round(static_cast<float>(move.y()) / gridCellSize) * gridCellSize
		);
	}

	nodeForm->move(move);
	nodeForm->setLinksDirty();
	nodeForm->getScriptPaintForm()->repaint();
}

void NodeFormDragger::endDrag()
{
	assert(nodeForm != nullptr);
	QCursor cursor(Qt::CursorShape::ArrowCursor);
	this->nodeForm->setCursor(cursor);
	nodeForm = nullptr;
}

