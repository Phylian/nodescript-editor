#include "intconstantvaluenodeformbuilder.h"

NodeForm* IntConstantValueNodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
	nodeForm->addIntField();
	addPins(nodeForm, node);
	return nodeForm;
}
