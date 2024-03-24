#include "plugin.hpp"

extern "C" void *pluginInitialize() {
  printf("Hello from plugin\n");
  printf("pluginInitialize\n");
  return nullptr;
}
auto shouldAddSamples = [](message_signals &resampledData,
                           const std::string &key) {
  if (resampledData["_timestamp"].size() > resampledData[key].size()) {
    return true;
  } else {
    return resampledData["_timestamp"].offset() != resampledData[key].offset();
  }
};
extern "C" void pluginRun(void *pluginData [[maybe_unused]],
                          message_signals &resampledData [[maybe_unused]]) {
  resampledData.erase("power");

  while (shouldAddSamples(resampledData, "power")) {
    resampledData["power"].push(resampledData["power"].last());
  }
  for (int i = 0; i < resampledData["INV_L_RCV.iq_actual"].size(); i++) {
    resampledData["power"][i] = resampledData["INV_L_RCV.iq_actual"][i] * 100.0;
  }
}
extern "C" void pluginDeinitialize(void *pluginData [[maybe_unused]]) {
  printf("pluginDeinitialize\n");
}
