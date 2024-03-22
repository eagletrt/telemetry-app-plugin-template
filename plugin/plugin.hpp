#pragma once

#include "buffer.hpp"

extern "C" {
void *pluginInitialize();
void pluginRun(void *pluginData, message_signals &resampledData);
void pluginDeinitialize(void *pluginData);
}
