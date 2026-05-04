#include "throttle_calibration.h"

ThrottleCalibrator::ThrottleCalibrator(int dac_pin) : _pin(dac_pin) {}

void ThrottleCalibrator::begin() {
  setPercent(0.0f);
}

void ThrottleCalibrator::setPercent(float percent) {
  if (percent < 0.0f) percent = 0.0f;
  if (percent > 100.0f) percent = 100.0f;
  _percent = percent;
  uint8_t dac_value = static_cast<uint8_t>((percent / 100.0f) * 255.0f);
  dacWrite(_pin, dac_value);
}

float ThrottleCalibrator::getPercent() const { return _percent; }
