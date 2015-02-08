#include "doubleconstantvaluenodeformbuilder.h"
#include "../../nodescript/src/nodescript.h"
#include "../../floatfieldform.h"

NodeForm* DoubleConstantValueNodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
	nodeForm->addField<FloatFieldForm>("Value");
	addPins(nodeForm, node);
	return nodeForm;
}

void DoubleConstantValueNodeFormBuilder::prepareRuntime(NodeForm* nodeForm, NodeRuntime* nodeRuntime) const
{
	FloatFieldForm* floatFieldForm = nodeForm->getField<FloatFieldForm>("Value");
	double doubleValue = floatFieldForm->getValue();
	node::ConstantValueNodeRuntime<double>* doubleConstantValueNodeRuntime = static_cast<node::ConstantValueNodeRuntime<double>*>(nodeRuntime);
	doubleConstantValueNodeRuntime->setValue(doubleValue);
}
