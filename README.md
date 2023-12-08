# CPU Temperature

### Measure the internal temperature of the processor.

Retrieve the temperature of the internal ATMega processor using nothing more than the internal registers.

NO external parts necessary.  All that is needed is the Atmel micro controller.  That's it.

Example use:

#
```cpp
    #include <CPUTemp.h>
    
    // We don't need a setup and a loop function so we just use a single main:
    int main() {
        Serial.begin(115200);

        // Read the processor temperature:
        double temp = temperature();
    
        // Format it as a string to 2 decimal places:
        char fstr[8];
        dtostrf(temp, 6, 2, fstr);
    
        // Display it:
        Serial.print("temperature: ");
        Serial.println(fstr);
    
        return 0;
    }
```

output:

#
```
    temperature: 96.70
```
