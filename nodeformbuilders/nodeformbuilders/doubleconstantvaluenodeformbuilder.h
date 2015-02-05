#ifndef DOUBLECONSTANTVALUENODEFORMBUILDER_H
#define DOUBLECONSTANTVALUENODEFORMBUILDER_H

#include "../nodeformbuilder.h"

class DoubleConstantValueNodeFormBuilder : public NodeFormBuilderTemplate<node::DoubleConstantValueNode>
{
public:
	NodeForm* buildNodeForm(Node* node) const override;
};

#endif // DOUBLECONSTANTVALUENODEFORMBUILDER_H
