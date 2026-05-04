# BLDC-TestBed-HardwareX

Open-source BLDC motor characterization test bed utilizing ESC-native telemetry for cost-effective educational laboratories.

This repository supports the HardwareX manuscript:

**An Open-Source BLDC Motor Test Bed Utilizing ESC Telemetry for Cost-Effective Educational Laboratories**  
Manuscript No.: **OHX-D-26-00053**

The platform uses off-the-shelf e-bike components, a Votol EM-50 electronic speed controller (ESC), an ESP32-based control and data acquisition unit, and a floating-caliper torque measurement mechanism based on a low-cost load cell and HX711 amplifier. ESC telemetry is decoded to obtain DC bus voltage, DC bus current, motor speed, and temperature, reducing the need for external electrical instrumentation.

## Repository links

- Zenodo frozen archive: https://doi.org/10.5281/zenodo.18689715
- GitHub repository: https://github.com/uun3406/BLDC-TestBed-HardwareX

## What is included

| Folder | Contents | Purpose |
|---|---|---|
| `firmware/` | ESP32 Arduino firmware, telemetry parser, HX711 load-cell code, throttle calibration routine | Rebuild and adapt the controller firmware |
| `hardware/wiring/` | Wiring diagram, ESC connector pinout table, ESP32 pin mapping | Electrical reproducibility |
| `hardware/mechanical/` | Mechanical dimensions, torque arm dimensions, assembly photos, floating-caliper photos | Mechanical fabrication guidance |
| `hardware/safety/` | Emergency stop diagram, fuse/power path diagram, pre-operation checklist | Safety verification |
| `bom/` | Bill of materials in CSV/XLSX and supplier notes | Component sourcing and cost tracking |
| `data/raw/` | Telemetry, load-cell calibration, torque verification, steady-state, and load-step data | Independent verification |
| `data/processed/` | Processed datasets, uncertainty budget, model-vs-experiment data | Figure/table reproduction |
| `scripts/` | Python scripts for calibration and figure regeneration | Reproducibility of analysis |
| `media/photos/` | Assembly, wiring, calibration, and operation photos | Build clarity |
| `media/videos/` | Video manifest and instructions for demonstration videos | Reader training and reviewer inspection |
| `manuscript_support/` | Revised manuscript, response to reviewers, and manuscript figures | Submission support |

## Minimum reproduction workflow

1. Read the safety notes in `hardware/safety/`.
2. Review the bill of materials in `bom/bill_of_materials.csv` or `bom/bill_of_materials.xlsx`.
3. Assemble the mechanical frame following `hardware/mechanical/README_mechanical.md` and the assembly photos.
4. Wire the ESC, battery, ESP32, HX711, load cell, emergency stop, and fuse path using `hardware/wiring/README_wiring.md`.
5. Upload the ESP32 firmware from `firmware/ESP32_BLDCTestBed/`.
6. Run load-cell zeroing and known-mass torque calibration.
7. Run throttle calibration with motor phases disconnected or the chain lifted.
8. Verify ESC telemetry frames at 9600 baud.
9. Perform steady-state and dynamic load-step tests.
10. Use the scripts in `scripts/` to regenerate processed data and figures.

## Safety warning

This hardware uses a high-energy LiFePO4 battery and a rotating chain drive. Install the chain guard, fuse, and emergency stop before operation. Initial testing and calibration should be performed by qualified personnel using insulated tools and appropriate personal protective equipment.

## License

Hardware design files are released under **CERN Open Hardware Licence Version 2 - Strongly Reciprocal (CERN-OHL-S-2.0)**. Firmware and scripts are released for open-source reuse and research replication; see file headers and `LICENSE`.

## Citation

Please cite the Zenodo DOI and the HardwareX article when available. A `CITATION.cff` file is included.

## Contact

Corresponding author:  
**Prof. Dr. Ir. Faridah, S.T., M.Sc., IPU.**  
Department of Engineering Physics, Universitas Gadjah Mada  
Email: faridah@ugm.ac.id
