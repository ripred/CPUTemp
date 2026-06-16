/*\ =========================================================================
|*|
|*| CPUTemp.cpp
|*|
|*| Function to use the internal registers in the ATMega cpu to calculate
|*| the internal temperature:
|*|
|*| =========================================================================
\*/

#include <avr/io.h>
#include <Arduino.h>
#include "CPUTemp.h"

double temperature(double aref, double offset) {
    // The internal temperature has to be used
    // with the internal reference of 1.1V.
    // Channel 8 can not be selected with
    // the analogRead function yet.

    // Set the internal reference and mux.
    ADMUX = ((1 << REFS1) | (1 << REFS0) | (1 << MUX3));
    ADCSRA |= (1 << ADEN);  // enable the ADC

    delay(20);            // wait for voltages to become stable.

    ADCSRA |= (1 << ADSC);  // Start the ADC

    // Detect end-of-conversion
    while (bit_is_set(ADCSRA,ADSC));

    // Reading register "ADCW" takes care of how to read ADCL and ADCH.
    uint16_t wADC = ADCW;

    // Convert the ADC reading to sensor voltage, then apply the ATmega328P
    // datasheet typical temperature curve. Offset allows chip calibration.
    double sensorVoltage = ((double)wADC / 1023.0) * aref;
    return (sensorVoltage * 942.485306465) - 272.388748950 + offset;
}
