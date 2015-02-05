#ifndef STRINGCONSTANTVALUENODEFORMBUILDER_H
#define STRINGCONSTANTVALUENODEFORMBUILDER_H

#include "../nodeformbuilder.h"

class StringConstantValueNodeFormBuilder : public NodeFormBuilderTemplate<node::StringConstantValueNode>
{
public:
	NodeForm* buildNodeForm(Node* node) const override;
};

#endif // STRINGCONSTANTVALUENODEFORMBUILDER_H
