(* Liest den Temperaturwert vom LM75 auf dem ESP32-Carrier-Board. fTemperature: Temperatur mit Auflösung 0.5°C als REAL (float). sTemperature: Ausgabe als String mit einer fixen Nachkommastelle. *)

FUNCTION_BLOCK ESP32_LM75
  VAR_INPUT
  END_VAR
  VAR_OUTPUT
    fTemperature : REAL := 0; (* Temperatur: -50.0 ... 150.0 °C *)
    sTemperature : STRING := '0'; (* Temperatur als String mit einer Nachkommastelle. *)
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

#include <Wire.h>

#define SensorAdresse 0x48  // I2C-Adresse fuer LM75

float lm75_read(int adress); // Prototyp

void setup() 
{
  Wire.begin();   
}

void loop() 
{ //char buffer[16];
  //fTemperature = lm75_read(SensorAdresse);
  int16_t raw_temp = 0;

  Wire.beginTransmission(SensorAdresse);
  Wire.write(0);                            // Pointer auf Temperatur-Register setzen
  Wire.endTransmission();

  Wire.requestFrom(SensorAdresse, 2);
  if (Wire.available() >= 2)
  {
    byte msb = Wire.read();
    byte lsb = Wire.read();

    raw_temp = (msb << 8) | lsb;
    raw_temp = raw_temp >> 7; 
  }
  //return (float)raw_temp * 0.5;
  fTemperature = (float)raw_temp * 0.5;

  //snprintf(buffer, sizeof(buffer), "%.1f", fTemperature);
  String tempStr = String(fTemperature, 1); 
  sTemperature.set(tempStr.c_str());
}

END_FUNCTION_BLOCK