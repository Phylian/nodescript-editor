#ifndef NODEFORMBUILDERS_H
#define NODEFORMBUILDERS_H

#include <map>
#include "nodeformbuilder.h"

class NodeFormBuilders
{
public:
    NodeFormBuilders();
    ~NodeFormBuilders();

    const NodeFormBuilder& getNodeFormBuilder(const char* nodeName);

private:
    void registerNodeFormBuilders();
    void registerNodeFormBuilder(NodeFormBuilder* nodeFormBuilder);

    const NodeFormBuilder defaultNodeFormBuilder;
    std::map<const char*, const NodeFormBuilder*> nodeFormBuildersByNodeName;
};

#endif // NODEFORMBUILDERS_H
