#ifndef BEATTRACKERMULTIFEATURENODE_H
#define BEATTRACKERMULTIFEATURENODE_H

#include "../essentianodes.h"

namespace node
{
namespace essentia
{

class BeatTrackerMultiFeatureNode : public FunctionalNode
{
	typedef FunctionalNode Super;
public:
	NODE(BeatTrackerMultiFeatureNode, "Essentia BeatTrackerMultiFeature");

	enum : PinIndex
	{
		MinTempoParamPinIndex,
		MaxTempoParamPinIndex,

		SignalInputPinIndex,

		TicksOutputPinIndex,
		ConfidenceOutputPinIndex
	};

	typedef PinInfo<MinTempoParamPinIndex,    float             > MinTempoParamPin;
	typedef PinInfo<MaxTempoParamPinIndex,    float             > MaxTempoParamPin;

	typedef PinInfo<SignalInputPinIndex,      EssentiaStreamData> SignalInputPin;

	typedef PinInfo<TicksOutputPinIndex,      EssentiaStreamData> TicksOutputPin;
	typedef PinInfo<ConfidenceOutputPinIndex, EssentiaStreamData> ConfidenceOutputPin;

public:
	BeatTrackerMultiFeatureNode();

	void execute(NodeRuntime* runtime) const override;
	#if defined(NODESCRIPT_DEBUG) || defined(NODESCRIPT_INTROSPECTION)
	const char* getPinName(PinIndex pinIndex) const override;
	#endif
};

} // essentia
} // node

#endif // BEATTRACKERMULTIFEATURENODE_H
