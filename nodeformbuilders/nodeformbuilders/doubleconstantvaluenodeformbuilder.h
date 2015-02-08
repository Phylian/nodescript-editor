#ifndef DOUBLECONSTANTVALUENODEFORMBUILDER_H
#define DOUBLECONSTANTVALUENODEFORMBUILDER_H

#include "../nodeformbuilder.h"

class DoubleConstantValueNodeFormBuilder : public NodeFormBuilderTemplate<node::DoubleConstantValueNode>
{
public:
	NodeForm* buildNodeForm(Node* node) const override;
	void prepareRuntime(NodeForm* nodeForm, NodeRuntime* nodeRuntime) const override;
};

#endif // DOUBLECONSTANTVALUENODEFORMBUILDER_H
