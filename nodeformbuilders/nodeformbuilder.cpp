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
	nodeForm->fillBlanks();
	nodeForm->resize(nodeForm->sizeHint());
}

NodeForm* NodeFormBuilder::buildEmptyNodeForm(Node* node) const
{
	return new NodeForm(node);
}

void NodeFormBuilder::addPins(NodeForm* nodeForm, Node* node) const
{
	int numPins = node->getNumPins();
	for (PinIndex pinIndex = 0; pinIndex < numPins; ++pinIndex)
	{
		const char* pinName = node->getPinName(pinIndex);
		switch (node->getPinArchetype(pinIndex))
		{
		case PinArchetype::INPUT_VALUE:
			nodeForm->addInputValuePin(pinName, pinIndex);
			break;
		case PinArchetype::INPUT_IMPULSE:
			nodeForm->addInputImpulsePin(pinName, pinIndex);
			break;
		case PinArchetype::OUTPUT_VALUE:
			nodeForm->addOutputValuePin(pinName, pinIndex);
			break;
		case PinArchetype::OUTPUT_IMPULSE:
			nodeForm->addOutputImpulsePin(pinName, pinIndex);
			break;
		default:
			assert(false);
		}
	}
}
