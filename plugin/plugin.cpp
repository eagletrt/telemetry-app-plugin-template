#include "plugin.hpp"

void *pluginInitialize() {
  printf("Hello from plugin\n");
  printf("pluginInitialize\n");
  return nullptr;
}
void pluginRun(void *pluginData [[maybe_unused]],
               message_signals &resampledData [[maybe_unused]]) {
  printf("pluginRun\n");
}
void pluginDeinitialize(void *pluginData [[maybe_unused]]) {
  printf("pluginDeinitialize\n");
}
