#ifndef NODEFORMBUILDER_H
#define NODEFORMBUILDER_H

#include "../nodescript/src/nodescript.h"
#include "../nodeform.h"

class NodeFormBuilder
{
public:
	virtual ~NodeFormBuilder() {}

	virtual NodeForm* buildNodeForm(Node* node) const;
	void resetSize(NodeForm* nodeForm) const;

	virtual const char* getNodeName() const { return "Any Node"; }

protected:
	NodeForm* buildEmptyNodeForm(Node* node) const;
	virtual void addPins(NodeForm* nodeForm, Node* node) const;
};

template <class NodeType>
class NodeFormBuilderTemplate : public NodeFormBuilder
{
protected:
	typedef NodeFormBuilder Super;
public:
	const char* getNodeName() const override { return NodeType::nodeName(); }
};

#endif // NODEFORMBUILDER_H
