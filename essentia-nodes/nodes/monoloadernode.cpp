#include "monoloadernode.h"

namespace node
{
namespace essentia
{

MonoLoaderNode::MonoLoaderNode()
{
	inValuePin<FilenameParamPin>();
	inValuePin<SampleRateParamPin>();
	inValuePin<DownMixParamPin>();

	outValuePin<AudioOutputPin>();
}

void MonoLoaderNode::execute(NodeRuntime* runtime) const
{
	std::string* filename;
	float sampleRate;
	std::string* downmix;
	readPin<FilenameParamPin>(runtime, filename);
	readPin<SampleRateParamPin>(runtime, sampleRate);
	readPin<DownMixParamPin>(runtime, downmix);

	std::cout << "filename=" << *filename << ";sampleRate=" << sampleRate << ";downmix=" << *downmix << std::endl;

	es::AlgorithmFactory& factory = es::AlgorithmFactory::instance();
	es::Algorithm* monoloader = factory.create("MonoLoader",
											   "filename",   *filename,
											   "sampleRate", sampleRate,
											   "downmix",    *downmix);

	writePin<AudioOutputPin>(runtime, &monoloader->output("audio"));
	writePin<AlgorithmPin  >(runtime, monoloader);
}

#if defined(NODESCRIPT_DEBUG) || defined(NODESCRIPT_INTROSPECTION)
const char* MonoLoaderNode::getPinName(PinIndex pinIndex) const
{
	switch (pinIndex)
	{
		case FilenameParamPin::Index:   return "File Name"; break;
		case SampleRateParamPin::Index: return "Sample Rate"; break;
		case DownMixParamPin::Index:    return "Down Mix"; break;
		case AudioOutputPin::Index:     return "Audio"; break;
		default: return Super::getPinName(pinIndex); break;
	}
}
#endif

} // essentia
} // node
