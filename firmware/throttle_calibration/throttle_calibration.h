#pragma once
#include <Arduino.h>

class ThrottleCalibrator {
public:
  explicit ThrottleCalibrator(int dac_pin);
  void begin();
  void setPercent(float percent);
  float getPercent() const;
private:
  int _pin;
  float _percent = 0.0f;
};
