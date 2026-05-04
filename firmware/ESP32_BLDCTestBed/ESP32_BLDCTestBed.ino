#include <Arduino.h>
#include "../telemetry_parser/telemetry_parser.h"
#include "../hx711_loadcell/hx711_loadcell.h"
#include "../throttle_calibration/throttle_calibration.h"

// Pin assignments - verify with the wiring table before use.
constexpr int PIN_THROTTLE_DAC = 25;   // ESP32 DAC1, 0.0-3.3 V
constexpr int PIN_HX711_DT     = 32;
constexpr int PIN_HX711_SCK    = 33;
constexpr int PIN_ESTOP        = 27;

HardwareSerial ESCSerial(2); // RX/TX pins are configured in setup.
TelemetryFrame telemetry;
HX711Torque torque_sensor(PIN_HX711_DT, PIN_HX711_SCK);
ThrottleCalibrator throttle(PIN_THROTTLE_DAC);

void setup() {
  Serial.begin(115200);
  ESCSerial.begin(9600, SERIAL_8N1, 16, 17); // RX=16, TX=17; adjust as needed.
  pinMode(PIN_ESTOP, INPUT_PULLUP);

  throttle.begin();
  throttle.setPercent(0);
  torque_sensor.begin();
  torque_sensor.setCalibrationFactor(2.184e-5f); // N m per count, update after calibration.

  Serial.println("BLDC Test Bed firmware started");
  Serial.println("time_ms,voltage_V,current_A,rpm,esc_temp_C,torque_Nm,throttle_percent,estop");
}

void loop() {
  const bool estop_active = (digitalRead(PIN_ESTOP) == LOW);
  if (estop_active) {
    throttle.setPercent(0);
  }

  while (ESCSerial.available()) {
    uint8_t b = ESCSerial.read();
    if (parseTelemetryByte(b, telemetry)) {
      float torque_Nm = torque_sensor.readTorqueNm();
      Serial.print(millis()); Serial.print(',');
      Serial.print(telemetry.voltage_V, 2); Serial.print(',');
      Serial.print(telemetry.current_A, 2); Serial.print(',');
      Serial.print(telemetry.rpm); Serial.print(',');
      Serial.print(telemetry.esc_temp_C, 1); Serial.print(',');
      Serial.print(torque_Nm, 3); Serial.print(',');
      Serial.print(throttle.getPercent(), 1); Serial.print(',');
      Serial.println(estop_active ? 1 : 0);
    }
  }
}
