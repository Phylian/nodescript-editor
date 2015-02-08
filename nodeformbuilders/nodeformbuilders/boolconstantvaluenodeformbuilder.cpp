#include "boolconstantvaluenodeformbuilder.h"
#include "../../nodescript/src/nodescript.h"
#include "../../boolfieldform.h"

NodeForm* BoolConstantValueNodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
	nodeForm->addField<BoolFieldForm>("Value");
	addPins(nodeForm, node);
	return nodeForm;
}

void BoolConstantValueNodeFormBuilder::prepareRuntime(NodeForm* nodeForm, NodeRuntime* nodeRuntime) const
{
	BoolFieldForm* boolFieldForm = nodeForm->getField<BoolFieldForm>("Value");
	bool boolValue = boolFieldForm->getValue();
	node::ConstantValueNodeRuntime<bool>* boolConstantValueNodeRuntime = static_cast<node::ConstantValueNodeRuntime<bool>*>(nodeRuntime);
	boolConstantValueNodeRuntime->setValue(boolValue);
}
