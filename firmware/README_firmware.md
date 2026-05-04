# Firmware

This folder contains modular ESP32 Arduino firmware for the BLDC motor test bed.

## Modules

- `ESP32_BLDCTestBed/`: main Arduino sketch integrating throttle control, ESC telemetry, HX711 torque reading, and serial logging.
- `telemetry_parser/`: Votol EM-50 ESC 24-byte telemetry packet parser.
- `hx711_loadcell/`: load-cell acquisition and torque conversion helpers.
- `throttle_calibration/`: DAC throttle calibration helper and safety routines.

## Build environment

- Board: ESP32 DevKit C or compatible ESP32 board
- Framework: Arduino IDE or PlatformIO
- Serial monitor: 115200 baud
- ESC telemetry: 9600 baud TTL serial
- HX711: DT/SCK pins defined in the sketch

## Safety

Before uploading or running throttle calibration, disconnect motor phases or lift the chain so that the motor cannot drive the load shaft unexpectedly.
