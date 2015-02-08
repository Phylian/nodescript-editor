#ifndef STRINGCONSTANTVALUENODEFORMBUILDER_H
#define STRINGCONSTANTVALUENODEFORMBUILDER_H

#include "../nodeformbuilder.h"

class StringConstantValueNodeFormBuilder : public NodeFormBuilderTemplate<node::StringConstantValueNode>
{
public:
	NodeForm* buildNodeForm(Node* node) const override;
	void prepareRuntime(NodeForm* nodeForm, NodeRuntime* nodeRuntime) const override;
};

#endif // STRINGCONSTANTVALUENODEFORMBUILDER_H
