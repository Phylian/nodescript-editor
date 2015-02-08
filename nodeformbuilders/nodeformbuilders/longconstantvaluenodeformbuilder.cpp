#include "longconstantvaluenodeformbuilder.h"
#include "../../nodescript/src/nodescript.h"
#include "../../intfieldform.h"

NodeForm* LongConstantValueNodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
	nodeForm->addField<IntFieldForm>("Value");
	addPins(nodeForm, node);
	return nodeForm;
}

void LongConstantValueNodeFormBuilder::prepareRuntime(NodeForm* nodeForm, NodeRuntime* nodeRuntime) const
{
	IntFieldForm* intFieldForm = nodeForm->getField<IntFieldForm>("Value");
	long longValue = intFieldForm->getValue();
	node::ConstantValueNodeRuntime<long>* longConstantValueNodeRuntime = static_cast<node::ConstantValueNodeRuntime<long>*>(nodeRuntime);
	longConstantValueNodeRuntime->setValue(longValue);
}
