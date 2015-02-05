#ifndef LONGCONSTANTVALUENODEFORMBUILDER_H
#define LONGCONSTANTVALUENODEFORMBUILDER_H

#include "../nodeformbuilder.h"

class LongConstantValueNodeFormBuilder : public NodeFormBuilderTemplate<node::LongConstantValueNode>
{
public:
	NodeForm* buildNodeForm(Node* node) const override;
};

#endif // LONGCONSTANTVALUENODEFORMBUILDER_H
