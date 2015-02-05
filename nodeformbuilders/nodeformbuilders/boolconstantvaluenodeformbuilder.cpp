#include "boolconstantvaluenodeformbuilder.h"

NodeForm* BoolConstantValueNodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
	nodeForm->addBoolField();
	addPins(nodeForm, node);
	return nodeForm;
}
