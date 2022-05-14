/*\
|*| CPUTemp.ino
|*|
|*| Example use of the CPUTemp library
|*|
\*/

#include <CPUTemp.h>

void setup() {
    Serial.begin(115200);
}

void loop() {
    bool bCelcius = false;
    char fstr[8];

    // Read the processor temperature in celcius:
    double temp = temperature();

    // Convert to fahrenheit if desired:
    temp = bCelcius ? temp : (temp * 2.0) + 30.0;

    // Format string of 6 total digits (incl '.') with 2 decimal places
    dtostrf(temp, 6, 2, fstr);

    Serial.print("temperature: ");
    Serial.println(fstr);

    delay(1000);
}
