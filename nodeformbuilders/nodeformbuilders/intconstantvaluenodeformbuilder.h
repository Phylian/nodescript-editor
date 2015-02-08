#ifndef INTCONSTANTVALUENODEFORMBUILDER_H
#define INTCONSTANTVALUENODEFORMBUILDER_H

#include "../nodeformbuilder.h"

class IntConstantValueNodeFormBuilder : public NodeFormBuilderTemplate<node::IntConstantValueNode>
{
public:
	NodeForm* buildNodeForm(Node* node) const override;
	void prepareRuntime(NodeForm* nodeForm, NodeRuntime* nodeRuntime) const override;
};

#endif // INTCONSTANTVALUENODEFORMBUILDER_H
