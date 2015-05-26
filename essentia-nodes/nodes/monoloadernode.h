#ifndef MONOLOADERNODE_H
#define MONOLOADERNODE_H

#include "../essentianodes.h"

namespace node
{
namespace essentia
{

class MonoLoaderNode : public FunctionalNode
{
	typedef FunctionalNode Super;
public:
	NODE(MonoLoaderNode, "Essentia MonoLoader");

	enum : PinIndex
	{
		FilenameParamPinIndex,
		SampleRateParamPinIndex,
		DownMixParamPinIndex,

		AudioOutputPinIndex,

		AlgorithmPinIndex
	};

	typedef PinInfo<FilenameParamPinIndex,   std::string*      > FilenameParamPin;
	typedef PinInfo<SampleRateParamPinIndex, float             > SampleRateParamPin;
	typedef PinInfo<DownMixParamPinIndex,    std::string*      > DownMixParamPin;

	typedef PinInfo<AudioOutputPinIndex,     EssentiaStreamData> AudioOutputPin;

	typedef PinInfo<AlgorithmPinIndex,       EssentiaAlgorithm > AlgorithmPin;

public:
	MonoLoaderNode();

	void execute(NodeRuntime* runtime) const override;
	#if defined(NODESCRIPT_DEBUG) || defined(NODESCRIPT_INTROSPECTION)
	const char* getPinName(PinIndex pinIndex) const override;
	#endif
};

} // essentia
} // node

#endif // MONOLOADERNODE_H
