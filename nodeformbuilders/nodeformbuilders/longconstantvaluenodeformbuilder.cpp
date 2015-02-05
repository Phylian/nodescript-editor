#include "longconstantvaluenodeformbuilder.h"

NodeForm* LongConstantValueNodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
	nodeForm->addIntField();
	addPins(nodeForm, node);
	return nodeForm;
}
