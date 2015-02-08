#include "floatconstantvaluenodeformbuilder.h"
#include "../../nodescript/src/nodescript.h"
#include "../../floatfieldform.h"

NodeForm* FloatConstantValueNodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
	nodeForm->addField<FloatFieldForm>("Value");
	addPins(nodeForm, node);
	return nodeForm;
}

void FloatConstantValueNodeFormBuilder::prepareRuntime(NodeForm* nodeForm, NodeRuntime* nodeRuntime) const
{
	FloatFieldForm* floatFieldForm = nodeForm->getField<FloatFieldForm>("Value");
	float floatValue = static_cast<float>(floatFieldForm->getValue());
	node::ConstantValueNodeRuntime<float>* floatConstantValueNodeRuntime = static_cast<node::ConstantValueNodeRuntime<float>*>(nodeRuntime);
	floatConstantValueNodeRuntime->setValue(floatValue);
}
