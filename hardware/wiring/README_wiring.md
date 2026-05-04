# Wiring documentation

This folder contains the wiring diagram, ESC connector pinout reference table, and ESP32 pin mapping for the BLDC motor test bed.

## Files

- `wiring_diagram_clean.png`: cleaned wiring diagram without the embedded connector table.
- `esc_connector_pinout_table.png`: readable ESC connector pinout reference redrawn from the supplied connector image.
- `esp32_pin_mapping.csv`: ESP32 pin assignment table.
- `emergency_stop_and_power_schematic.jpg`: conceptual emergency-stop and power-path schematic.

## Important safety notes

- Install the 30 A fuse in the battery-to-ESC positive path.
- Install the emergency stop in the main interrupt/enable path before operation.
- Verify common ground between ESP32, HX711, and ESC signal reference.
- Confirm that the ESC throttle input receives the intended 0-5 V conditioned signal, not the raw ESP32 DAC output.
- Disconnect motor phases during initial throttle calibration.
