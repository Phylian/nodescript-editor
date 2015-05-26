#ifndef ESSENTIANODES_H
#define ESSENTIANODES_H

#include "../nodescript/src/nodescript.h"

#include <essentia/essentia.h>
#include <essentia/algorithmfactory.h>

namespace es = ::essentia::streaming;

typedef es::SourceBase* EssentiaStreamData;
typedef es::Algorithm* EssentiaAlgorithm;

PIN_TYPE(EssentiaStreamData);
PIN_TYPE(EssentiaAlgorithm);

void registerEssentiaNodes(ScriptEngine& se);

#endif // ESSENTIANODES_H
