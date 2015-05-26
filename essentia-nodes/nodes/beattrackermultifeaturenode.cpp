#include "beattrackermultifeaturenode.h"

namespace node
{
namespace essentia
{

BeatTrackerMultiFeatureNode::BeatTrackerMultiFeatureNode()
{
	inValuePin<MinTempoParamPin>();
	inValuePin<MaxTempoParamPin>();

	inValuePin<SignalInputPin>();

	outValuePin<TicksOutputPin>();
	outValuePin<ConfidenceOutputPin>();
}

void BeatTrackerMultiFeatureNode::execute(NodeRuntime* runtime) const
{
	float minTempo;
	float maxTempo;
	readPin<MinTempoParamPin>(runtime, minTempo);
	readPin<MaxTempoParamPin>(runtime, maxTempo);

	std::cout << "minTempo=" << minTempo << ";maxTempo=" << maxTempo << std::endl;

	es::AlgorithmFactory& factory = es::AlgorithmFactory::instance();
	es::Algorithm* beattracker = factory.create("BeatTrackerMultiFeature",
											"minTempo", minTempo,
											"maxTempo", maxTempo);

	EssentiaStreamData signal;
	readPin<SignalInputPin>(runtime, signal);

	*signal >> beattracker->input("signal");

	writePin<TicksOutputPin     >(runtime, &beattracker->output("ticks"));
	writePin<ConfidenceOutputPin>(runtime, &beattracker->output("confidence"));
}

#if defined(NODESCRIPT_DEBUG) || defined(NODESCRIPT_INTROSPECTION)
const char* BeatTrackerMultiFeatureNode::getPinName(PinIndex pinIndex) const
{
	switch (pinIndex)
	{
		case MinTempoParamPin::Index:    return "Min Tempo"; break;
		case MaxTempoParamPin::Index:    return "Max Tempo"; break;
		case SignalInputPin::Index:      return "Signal"; break;
		case TicksOutputPin::Index:      return "Ticks"; break;
		case ConfidenceOutputPin::Index: return "Confidence"; break;
		default: return Super::getPinName(pinIndex); break;
	}
}
#endif

} // essentia
} // node


