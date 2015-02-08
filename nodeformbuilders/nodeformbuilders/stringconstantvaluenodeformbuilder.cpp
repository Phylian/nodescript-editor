#include "stringconstantvaluenodeformbuilder.h"
#include "../../nodescript/src/nodescript.h"
#include "../../stringfieldform.h"

NodeForm* StringConstantValueNodeFormBuilder::buildNodeForm(Node* node) const
{
	NodeForm* nodeForm = buildEmptyNodeForm(node);
	nodeForm->addField<StringFieldForm>("Value");
	addPins(nodeForm, node);
	return nodeForm;
}

void StringConstantValueNodeFormBuilder::prepareRuntime(NodeForm* nodeForm, NodeRuntime* nodeRuntime) const
{
	StringFieldForm* stringFieldForm = nodeForm->getField<StringFieldForm>("Value");
	std::string stringValue = stringFieldForm->getValue();
	node::StringConstantValueNodeRuntime* stringConstantValueNodeRuntime = static_cast<node::StringConstantValueNodeRuntime*>(nodeRuntime);
	stringConstantValueNodeRuntime->setValue(stringValue);
}
