#include <algorithm>

#include "nodeformbuilders.h"

#include "nodeformbuilders/nodeformbuilders/boolconstantvaluenodeformbuilder.h"
#include "nodeformbuilders/nodeformbuilders/intconstantvaluenodeformbuilder.h"
#include "nodeformbuilders/nodeformbuilders/longconstantvaluenodeformbuilder.h"
#include "nodeformbuilders/nodeformbuilders/floatconstantvaluenodeformbuilder.h"
#include "nodeformbuilders/nodeformbuilders/doubleconstantvaluenodeformbuilder.h"
#include "nodeformbuilders/nodeformbuilders/stringconstantvaluenodeformbuilder.h"

NodeFormBuilders::NodeFormBuilders()
{
    registerNodeFormBuilders();
}

NodeFormBuilders::~NodeFormBuilders()
{
    for (const std::pair<const char*, const NodeFormBuilder*>& pair : nodeFormBuildersByNodeName)
        delete pair.second;
}

void NodeFormBuilders::registerNodeFormBuilders()
{
	registerNodeFormBuilder(new BoolConstantValueNodeFormBuilder());
	registerNodeFormBuilder(new IntConstantValueNodeFormBuilder());
	registerNodeFormBuilder(new LongConstantValueNodeFormBuilder());
	registerNodeFormBuilder(new FloatConstantValueNodeFormBuilder());
	registerNodeFormBuilder(new DoubleConstantValueNodeFormBuilder());
	registerNodeFormBuilder(new StringConstantValueNodeFormBuilder());
}

void NodeFormBuilders::registerNodeFormBuilder(NodeFormBuilder* nodeFormBuilder)
{
    nodeFormBuildersByNodeName[nodeFormBuilder->getNodeName()] = nodeFormBuilder;
}

const NodeFormBuilder& NodeFormBuilders::getNodeFormBuilder(const char* nodeName)
{
    std::map<const char*, const NodeFormBuilder*>::iterator it = nodeFormBuildersByNodeName.find(nodeName);

    if (it != nodeFormBuildersByNodeName.end())
        return *it->second;

    else
        return defaultNodeFormBuilder;
}

