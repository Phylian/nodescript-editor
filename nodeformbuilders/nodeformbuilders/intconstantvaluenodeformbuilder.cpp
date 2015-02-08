#include "intconstantvaluenodeformbuilder.h"
#include "../../nodescript/src/nodescript.h"
#include "../../intfieldform.h"

NodeForm* IntConstantValueNodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
	nodeForm->addField<IntFieldForm>("Value");
	addPins(nodeForm, node);
	return nodeForm;
}

void IntConstantValueNodeFormBuilder::prepareRuntime(NodeForm* nodeForm, NodeRuntime* nodeRuntime) const
{
	IntFieldForm* intFieldForm = nodeForm->getField<IntFieldForm>("Value");
	int intValue = static_cast<int>(intFieldForm->getValue());
	node::ConstantValueNodeRuntime<int>* intConstantValueNodeRuntime = static_cast<node::ConstantValueNodeRuntime<int>*>(nodeRuntime);
	intConstantValueNodeRuntime->setValue(intValue);
}
