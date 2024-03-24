#include "plugin.hpp"

extern "C" void *pluginInitialize() {
  printf("Hello from plugin\n");
  return nullptr;
}
extern "C" void pluginDeinitialize(void *pluginData [[maybe_unused]]) {
  printf("Bye from plugin\n");
}

extern "C" void pluginRun(void *pluginData [[maybe_unused]],
                          message_signals &resampledData [[maybe_unused]]) {
  // Process data here
}