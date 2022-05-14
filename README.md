# CPU Temperature

### Measure the internal temperature of the processor!

Retrieve the temperature of the internal ATMega processor using nothing more than the internal registers!

NO external parts necessary.  All that is needed is the Atmel micro controller.  That's it!  You can even press your finger on top of the processor for a few seconds and watch the return temperature rise.  Remove your finger and cool the processor down by blowing on it or spraying it with freeze spray and it instantly drops!

The following code demonstrates how simple it is:

#
```
    #include <Arduino.h>
    #include <CPUTemp.h>
    
    // We don't need a setup and a loop function so we just use a single main:
    int main() {
        Serial.begin(115200);
    
        char    fstr[8] { 0 };
        double  temp { 0.0 };
    
        // Read the temperature:
        temp = temperature();
    
        // Format it as a string to 2 decimal places:
        dtostrf(temp, 5, 2, fstr);
    
        // Display it:
        Serial.print("temperature: ");
        Serial.println(fstr);
    
        return 0;
    }
```

output:

#
```
    temperature: 4.73
```

