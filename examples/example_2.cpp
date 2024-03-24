#include "plugin/plugin.hpp"

class MyPluginData {
 public:
  int count = 0;
};

extern "C" void *pluginInitialize() {
  MyPluginData *data = new MyPluginData();
  printf("Hello from plugin\n");
  return data;
}
extern "C" void pluginDeinitialize(void *pluginData [[maybe_unused]]) {
  MyPluginData *data = static_cast<MyPluginData *>(pluginData);
  printf("Bye from plugin with count: %d", data->count);
  delete data;
}

extern "C" void pluginRun(void *pluginData [[maybe_unused]],
                          message_signals &resampledData [[maybe_unused]]) {
  // Process data here
  MyPluginData *data = static_cast<MyPluginData *>(pluginData);
  data->count++;
  printf("Count: %d\n", data->count);
}
