#pragma once
#include <Arduino.h>

class HX711Torque {
public:
  HX711Torque(int dt_pin, int sck_pin);
  void begin();
  void tare();
  void setCalibrationFactor(float factor_Nm_per_count);
  long readRaw();
  float readTorqueNm();
private:
  int _dt;
  int _sck;
  long _offset = 0;
  float _factor = 1.0f;
};
