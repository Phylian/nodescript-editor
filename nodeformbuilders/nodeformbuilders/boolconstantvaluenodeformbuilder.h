#ifndef BOOLCONSTANTVALUENODEFORMBUILDER_H
#define BOOLCONSTANTVALUENODEFORMBUILDER_H

#include "../nodeformbuilder.h"

class BoolConstantValueNodeFormBuilder : public NodeFormBuilderTemplate<node::BoolConstantValueNode>
{
public:
	NodeForm* buildNodeForm(Node* node) const override;
};

#endif // BOOLCONSTANTVALUENODEFORMBUILDER_H
