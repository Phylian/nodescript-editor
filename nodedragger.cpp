#include "nodedragger.h"

#include <cassert>

#include "nodeform.h"

NodeDragger::NodeDragger() :
    nodeForm(NULL)
{

}

NodeDragger::~NodeDragger()
{

}

void NodeDragger::beginDrag(NodeForm *nodeForm, QPoint offset)
{
    this->nodeForm = nodeForm;
    this->offset = offset;
}

void NodeDragger::drag(QPoint mousePosition)
{
    assert(nodeForm != NULL);
    nodeForm->move(nodeForm->mapToParent(mousePosition - offset));
}

void NodeDragger::endDrag()
{
    nodeForm = NULL;
}

