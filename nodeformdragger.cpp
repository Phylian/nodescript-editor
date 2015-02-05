#include "nodeformdragger.h"

#include <cassert>

#include "nodeform.h"

NodeFormDragger::NodeFormDragger() :
    nodeForm(nullptr)
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
    nodeForm->move(nodeForm->mapToParent(mousePosition - offset));
}

void NodeFormDragger::endDrag()
{
    assert(nodeForm != nullptr);
    QCursor cursor(Qt::CursorShape::ArrowCursor);
    this->nodeForm->setCursor(cursor);
    nodeForm = nullptr;
}

