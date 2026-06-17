# CPU Temperature

[![Arduino CI](https://flat.badgen.net/badge/Arduino%20CI/passing/2da44e?labelColor=24292f)](https://github.com/ripred/CPUTemp/actions/workflows/arduino_test_runner.yml)
[![Arduino-lint](https://flat.badgen.net/badge/Arduino-lint/passing/2da44e?labelColor=24292f)](https://github.com/ripred/CPUTemp/actions/workflows/arduino-lint.yml)
[![JSON check](https://flat.badgen.net/badge/JSON%20check/passing/2da44e?labelColor=24292f)](https://github.com/ripred/CPUTemp/actions/workflows/jsoncheck.yml)
[![Arduino Library Manager](https://flat.badgen.net/badge/Arduino%20Library%20Manager/available/00878f?labelColor=24292f)](https://www.ardu-badge.com/CPUTemp)
[![Release](https://flat.badgen.net/badge/Release/v1.0.4/8250df?labelColor=24292f)](https://github.com/ripred/CPUTemp/releases/latest)
[![License](https://flat.badgen.net/badge/License/MIT/0969da?labelColor=24292f)](https://github.com/ripred/CPUTemp/blob/main/LICENSE)
[![Stars](https://flat.badgen.net/badge/Stars/10/bf8700?labelColor=24292f)](https://github.com/ripred/CPUTemp/stargazers)
[![Forks](https://flat.badgen.net/badge/Forks/1/6f42c1?labelColor=24292f)](https://github.com/ripred/CPUTemp/network/members)

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
