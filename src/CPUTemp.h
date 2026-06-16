/*\ =========================================================================
|*|
|*| Library to use the internal registers in the ATMega cpu to calculate
|*| the internal temperature:
|*|
|*| =========================================================================
\*/

#ifndef CPUTEMP_H_INC
#define CPUTEMP_H_INC

double temperature(double aref = 1.1, double offset = 0.0);

#endif