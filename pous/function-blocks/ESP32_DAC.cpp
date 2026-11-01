(* Gibt eine Analoge Spannung (0...3,3V, bzw. 0...5V am CarrierBoard) an den Analogausgängen des ESP32 aus (Pin 25 und 26) *)

FUNCTION_BLOCK ESP32_DAC
  VAR_INPUT
    IN1 : USINT := 0; (* 8-Bit Analogwert (0...255) *)
    IN2 : USINT := 0; (* 8-Bit Analogwert (0...255) *)
  END_VAR
  VAR_OUTPUT
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

#define DAC1 25
#define DAC2 26

void setup()
{
  #ifdef ARDUINO
    pinMode(DAC1, ANALOG);
    pinMode(DAC2, ANALOG);

  #endif
}

void loop()
{
  #ifdef ARDUINO
    // IN1 / IN2 sind UINT (0–65535), dacWrite erwartet 0–255
    // Skalierung: (wert * 255) / 65535 → vereinfacht: wert / 257
    uint8_t dac1_val = (uint8_t)(IN1);
    uint8_t dac2_val = (uint8_t)(IN2);

    dacWrite(DAC1, dac1_val);
    dacWrite(DAC2, dac2_val);
  #endif
}

END_FUNCTION_BLOCK