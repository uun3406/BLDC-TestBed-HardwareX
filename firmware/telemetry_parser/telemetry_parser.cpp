#include "telemetry_parser.h"

static uint8_t buffer[24];
static uint8_t index_pos = 0;

bool parseTelemetryByte(uint8_t byte_in, TelemetryFrame &out) {
  // Expected header based on the observed Votol EM-50 24-byte telemetry frame.
  if (index_pos == 0 && byte_in != 0xC0) return false;
  if (index_pos == 1 && byte_in != 0x14) { index_pos = 0; return false; }
  if (index_pos == 2 && byte_in != 0x0D) { index_pos = 0; return false; }

  buffer[index_pos++] = byte_in;

  if (index_pos < 24) return false;
  index_pos = 0;

  uint16_t raw_voltage = (static_cast<uint16_t>(buffer[5]) << 8) | buffer[6];
  uint16_t raw_current = (static_cast<uint16_t>(buffer[7]) << 8) | buffer[8];
  uint16_t raw_rpm     = (static_cast<uint16_t>(buffer[14]) << 8) | buffer[15];

  out.voltage_V = raw_voltage / 10.0f;
  out.current_A = raw_current / 10.0f;
  out.rpm = raw_rpm;
  out.esc_temp_C = static_cast<float>(buffer[16]);
  out.external_temp_C = static_cast<float>(buffer[17]);
  return true;
}
