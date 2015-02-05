#include <cassert>
#include "nodeformbuilder.h"
#include "nodeform.h"
#include "nodescript/src/nodescript.h"

NodeForm* NodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
    addPins(nodeForm, node);
    return nodeForm;
}

void NodeFormBuilder::resetSize(NodeForm* nodeForm) const
{
	nodeForm->resize(nodeForm->sizeHint());
}

NodeForm* NodeFormBuilder::buildEmptyNodeForm(Node* node) const
{
	return new NodeForm(node->getNodeName());
}

void NodeFormBuilder::addPins(NodeForm* nodeForm, Node* node) const
{
    int numPins = node->getNumPins();
    for (int i = 0; i < numPins; ++i)
    {
        const char* pinName = node->getPinName(i);
        switch (node->getPinArchetype(i))
        {
        case PinArchetype::INPUT_VALUE:
            nodeForm->addInputValuePin(pinName);
            break;
        case PinArchetype::INPUT_IMPULSE:
            nodeForm->addInputImpulsePin(pinName);
            break;
        case PinArchetype::OUTPUT_VALUE:
            nodeForm->addOutputValuePin(pinName);
            break;
        case PinArchetype::OUTPUT_IMPULSE:
            nodeForm->addOutputImpulsePin(pinName);
            break;
        default:
            assert(false);
        }
    }
}
