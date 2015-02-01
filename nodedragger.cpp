#include "nodedragger.h"

#include <cassert>

#include "nodeform.h"

NodeDragger::NodeDragger() :
    nodeForm(nullptr)
{

}

NodeDragger::~NodeDragger()
{

}

void NodeDragger::beginDrag(NodeForm *nodeForm, QPoint offset)
{
    assert(nodeForm != nullptr);
    assert(this->nodeForm == nullptr);
    this->nodeForm = nodeForm;
    this->offset = offset;
    QCursor cursor(Qt::CursorShape::DragMoveCursor);
    this->nodeForm->setCursor(cursor);
}

void NodeDragger::drag(QPoint mousePosition)
{
    assert(nodeForm != nullptr);
    nodeForm->move(nodeForm->mapToParent(mousePosition - offset));
}

void NodeDragger::endDrag()
{
    assert(nodeForm != nullptr);
    QCursor cursor(Qt::CursorShape::ArrowCursor);
    this->nodeForm->setCursor(cursor);
    nodeForm = nullptr;
}

