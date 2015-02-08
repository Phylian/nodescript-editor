#ifndef LONGCONSTANTVALUENODEFORMBUILDER_H
#define LONGCONSTANTVALUENODEFORMBUILDER_H

#include "../nodeformbuilder.h"

class LongConstantValueNodeFormBuilder : public NodeFormBuilderTemplate<node::LongConstantValueNode>
{
public:
	NodeForm* buildNodeForm(Node* node) const override;
	void prepareRuntime(NodeForm* nodeForm, NodeRuntime* nodeRuntime) const override;
};

#endif // LONGCONSTANTVALUENODEFORMBUILDER_H
