#pragma once
#include <Arduino.h>

struct TelemetryFrame {
  float voltage_V = 0.0f;
  float current_A = 0.0f;
  uint16_t rpm = 0;
  float esc_temp_C = 0.0f;
  float external_temp_C = 0.0f;
};

bool parseTelemetryByte(uint8_t byte_in, TelemetryFrame &out);
