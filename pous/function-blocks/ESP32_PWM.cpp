(* Gibt eine PWM mit f = 1 kHz am PWM-Pin aus. PinNr: PWM-Pin (ESP32); iDutycycle:  0 ... 65535 (g: 0 ... 100%) *)

FUNCTION_BLOCK ESP32_PWM
  VAR_INPUT
    PinNr : UINT := 2; (* default: PinNr = 2 (Backlight) *)
    iDutycycle : UINT;
  END_VAR
  VAR_EXTERNAL
  END_VAR
/* ================================================================
 *  C/C++ FUNCTION BLOCK
 *
 *  ---------------------------------------------------------------
 *  - This function block runs **in sync** with the PLC runtime.
 *  - The `setup()` function is called once when the block initializes.
 *  - The `loop()` function is called at every PLC scan cycle.
 *  - Block input and output variables declared in the variable table
 *    can be accessed directly by name in this C/C++ code.
 *
 *  This block executes as part of the main PLC process and follows
 *  the configured scan time in the Resources. Use it for real-time
 *  control logic, fast I/O operations, or any C-based algorithms.
 * ================================================================ */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


const int PWM_FREQU = 1'000;
const int PWM_RES = 12;
const int MAX_DUTY_CYCLE = (int)(pow(2, PWM_RES) - 1); 

void setup()
{
  ledcAttach(PinNr,PWM_FREQU,PWM_RES);
}

void loop()
{ 
  int dimmer = map(iDutycycle,0,65535,0,MAX_DUTY_CYCLE);
  ledcWrite(PinNr, dimmer);        // (GPIO, duty_cycle)
}

END_FUNCTION_BLOCK