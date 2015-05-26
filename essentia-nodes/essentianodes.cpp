#include "essentianodes.h"

#include "nodes/monoloadernode.h"
#include "nodes/beattrackermultifeaturenode.h"

PIN_TYPE_DECLARE_ID(EssentiaStreamData);
PIN_TYPE_DECLARE_ID(EssentiaAlgorithm);

void registerEssentiaNodes(ScriptEngine& se)
{
	se.registerNode<node::essentia::MonoLoaderNode>();
	se.registerNode<node::essentia::BeatTrackerMultiFeatureNode>();
}
