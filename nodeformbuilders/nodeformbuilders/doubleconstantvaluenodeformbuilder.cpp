#include "doubleconstantvaluenodeformbuilder.h"

NodeForm*DoubleConstantValueNodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
	nodeForm->addFloatField();
	addPins(nodeForm, node);
	return nodeForm;
}
