#ifndef FLOATCONSTANTVALUENODEFORMBUILDER_H
#define FLOATCONSTANTVALUENODEFORMBUILDER_H

#include "../nodeformbuilder.h"

class FloatConstantValueNodeFormBuilder : public NodeFormBuilderTemplate<node::FloatConstantValueNode>
{
public:
	NodeForm* buildNodeForm(Node* node) const override;
	void prepareRuntime(NodeForm* nodeForm, NodeRuntime* nodeRuntime) const override;
};

#endif // FLOATCONSTANTVALUENODEFORMBUILDER_H
