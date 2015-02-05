#ifndef INTCONSTANTVALUENODEFORMBUILDER_H
#define INTCONSTANTVALUENODEFORMBUILDER_H

#include "../nodeformbuilder.h"

class IntConstantValueNodeFormBuilder : public NodeFormBuilderTemplate<node::IntConstantValueNode>
{
public:
	NodeForm* buildNodeForm(Node* node) const override;
};

#endif // INTCONSTANTVALUENODEFORMBUILDER_H
