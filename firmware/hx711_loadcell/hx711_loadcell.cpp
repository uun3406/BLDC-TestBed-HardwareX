#include "hx711_loadcell.h"

HX711Torque::HX711Torque(int dt_pin, int sck_pin) : _dt(dt_pin), _sck(sck_pin) {}

void HX711Torque::begin() {
  pinMode(_dt, INPUT);
  pinMode(_sck, OUTPUT);
  digitalWrite(_sck, LOW);
  tare();
}

long HX711Torque::readRaw() {
  while (digitalRead(_dt) == HIGH) { delayMicroseconds(10); }
  unsigned long value = 0;
  for (int i = 0; i < 24; i++) {
    digitalWrite(_sck, HIGH);
    value = (value << 1) | digitalRead(_dt);
    digitalWrite(_sck, LOW);
  }
  // Gain = 128, one extra pulse.
  digitalWrite(_sck, HIGH);
  digitalWrite(_sck, LOW);
  if (value & 0x800000) value |= 0xFF000000;
  return static_cast<long>(value);
}

void HX711Torque::tare() {
  long sum = 0;
  for (int i = 0; i < 10; i++) sum += readRaw();
  _offset = sum / 10;
}

void HX711Torque::setCalibrationFactor(float factor_Nm_per_count) { _factor = factor_Nm_per_count; }

float HX711Torque::readTorqueNm() {
  return (readRaw() - _offset) * _factor;
}
