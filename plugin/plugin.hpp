#pragma once

#include "buffer.hpp"

void *pluginInitialize();
void pluginRun(void *pluginData, message_signals &resampledData);
void pluginDeinitialize(void *pluginData);
