[![Arduino CI](https://github.com/ripred/CPUTemp/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/ripred/CPUTemp/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/ripred/CPUTemp/actions/workflows/arduino-lint.yml)
![code size:](https://img.shields.io/github/languages/code-size/ripred/CPUTemp)
[![GitHub release](https://img.shields.io/github/release/ripred/CPUTemp.svg?maxAge=3600)](https://github.com/ripred/CPUTemp/releases)
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/ripred/CPUTemp/blob/master/LICENSE)

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

