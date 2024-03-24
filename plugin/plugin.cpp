#include "plugin.hpp"

extern "C" void *pluginInitialize() {
  printf("Hello from plugin\n");
  return nullptr;
}
extern "C" void pluginRun(void *pluginData [[maybe_unused]],
                          message_signals &resampledData [[maybe_unused]]) {
  resampledData["power"] = resampledData["INV_L_RCV.iq_actual"] *
                               resampledData["INV_L_RCV.n_actual_filt"] +
                           resampledData["INV_R_RCV.iq_actual"] *
                               resampledData["INV_R_RCV.n_actual_filt"];
  resampledData["power_kW"] = resampledData["power"] / 1000.0;
}
extern "C" void pluginDeinitialize(void *pluginData [[maybe_unused]]) {
  printf("Bye from plugin\n");
}
