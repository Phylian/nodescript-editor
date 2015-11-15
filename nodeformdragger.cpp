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

void NodeFormDragger::beginDrag(NodeForm* nodeForm, QPoint offset)
{
	assert(nodeForm != nullptr);
	assert(this->nodeForm == nullptr);
	this->nodeForm = nodeForm;
	this->offset = offset;
	nodeForm->setCursor(Qt::CursorShape::DragMoveCursor);
}

void NodeFormDragger::drag(QPoint mousePosition)
{
	if (nodeForm != nullptr)
	{
		QPoint position = nodeForm->mapToParent(mousePosition - offset);
		if (snapToGrid)
		{
			const int gridCellSize = 20;
			position = QPoint(
						round(static_cast<float>(position.x()) / gridCellSize) * gridCellSize,
						round(static_cast<float>(position.y()) / gridCellSize) * gridCellSize
						);
		}
		nodeForm->move(position);
		nodeForm->setLinksDirty();
		nodeForm->getScriptPaintForm()->repaint();
	}
}

void NodeFormDragger::endDrag()
{
	if (nodeForm != nullptr)
	{
		nodeForm->setCursor(Qt::CursorShape::ArrowCursor);
		nodeForm = nullptr;
	}
}

