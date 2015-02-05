#include "stringconstantvaluenodeformbuilder.h"

NodeForm* StringConstantValueNodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
	nodeForm->addStringField();
	addPins(nodeForm, node);
	return nodeForm;
}
