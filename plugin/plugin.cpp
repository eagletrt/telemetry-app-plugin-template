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
  resampledData["power"] = resampledData["INV_L_RCV.iq_actual"] *
                               resampledData["INV_L_RCV.n_actual_filt"] +
                           resampledData["INV_R_RCV.iq_actual"] *
                               resampledData["INV_R_RCV.n_actual_filt"];
  resampledData["power_kW"] = resampledData["power"] / 1000.0;
}
extern "C" void pluginDeinitialize(void *pluginData [[maybe_unused]]) {
  printf("pluginDeinitialize\n");
}
