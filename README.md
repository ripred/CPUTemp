[![Arduino CI](https://github.com/ripred/CPUTemp/actions/workflows/arduino_test_runner.yml/badge.svg)](https://github.com/ripred/CPUTemp/actions/workflows/arduino_test_runner.yml)
[![Arduino-lint](https://github.com/ripred/CPUTemp/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/ripred/CPUTemp/actions/workflows/arduino-lint.yml)
[![GitHub release](https://flat.badgen.net/github/release/ripred/CPUTemp)](https://github.com/ripred/CPUTemp/releases/latest)
[![License: MIT](https://flat.badgen.net/github/license/ripred/CPUTemp)](https://github.com/ripred/CPUTemp/blob/main/LICENSE)

# CPU Temperature

Read the internal temperature sensor on supported AVR microcontrollers using only the processor's internal ADC and temperature sensor. No external parts or connections are required.

## Compatibility

CPUTemp uses AVR-specific ADC registers and is intended for ATmega328P-style internal temperature sensing. The library is not compatible with non-AVR architectures such as SAMD, ESP32, Renesas, Zephyr, or megaAVR boards.

## Usage

    #include <CPUTemp.h>

    void setup() {
        Serial.begin(115200);
    }

    void loop() {
        double tempC = temperature();

        Serial.print("temperature: ");
        Serial.print(tempC);
        Serial.println(" C");

        delay(1000);
    }

## Calibration

The default call uses the nominal internal reference voltage:

    double tempC = temperature();

For better results, pass the measured ADC reference voltage and an optional temperature offset:

    double tempC = temperature(1.056, 65.0);

Function signature:

    double temperature(double aref = 1.1, double offset = 0.0);

- `aref`: actual ADC reference voltage in volts. The nominal default is `1.1`.
- `offset`: correction added to the calculated temperature in degrees Celsius.

The internal temperature sensor is useful for relative processor temperature changes, but it is not factory calibrated for precision temperature measurement. Per-chip calibration is recommended when absolute accuracy matters.

