#include "floatconstantvaluenodeformbuilder.h"

NodeForm*FloatConstantValueNodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
	nodeForm->addFloatField();
	addPins(nodeForm, node);
	return nodeForm;
}
