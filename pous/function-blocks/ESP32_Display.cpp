(* Gibt die Strings TextZeile1 auf Zeile 1 und TextZeile2 auf Zeile 2 des I2C-Displays aus. In der Arduino IDE muss die Bibliothek: LiquidCrystal_I2C von Frank de Brabander installiert sein. *)

FUNCTION_BLOCK ESP32_Display
  VAR
  END_VAR
  VAR_INPUT
    TextZeile1 : STRING;
    TextZeile2 : STRING;
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

#include <Arduino.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <Wire.h>               // Wire Bibliothek für I2C-Display
#include <LiquidCrystal_I2C.h>

// I2C-Display: adresse 0x27, 2 Zeilen á 16 Zeichen
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Konvertiert UTF-8 Strings (OpenPLC) in den Zeichensatz des Standard-Textdisplays
String convertToLCDCharset(const String& input) 
{
    String output = "";
    output.reserve(input.length()); // Speicher vorab reservieren

    for (size_t i = 0; i < input.length(); i++) 
    {
        unsigned char c = input[i];

        // UTF-8 Sonderzeichen beginnen meist mit dem Startbyte 0xC3 oder 0xC2
        if (c == 0xC3 && i + 1 < input.length()) {
            unsigned char next = input[i + 1];
            i++; // Das Folgebyte direkt überspringen, da wir es jetzt verarbeiten

            switch (next) {
                case 0x9F: output += (char)0xE2; break; // ß
                case 0xA4:
                case 0x84: output += (char)0xE1; break; // ä
                case 0xB6: 
                case 0x96: output += (char)0xEF; break; // ö
                case 0xBC: 
                case 0x9C: output += (char)0xF5; break; // ü
                
                default: 
                    // Falls ein anderes 0xC3-Zeichen kommt, unverändert lassen
                    output += (char)c; 
                    output += (char)next; 
                    break;
            }
        } 
        else if (c == 0xC2 && i + 1 < input.length()) {
            unsigned char next = input[i + 1];
            if (next == 0xB0) { // UTF-8 für '°'
                output += (char)0xDF; // HD44780 spezifisches '°'
                i++;
            } else {
                output += (char)c;
            }
        }
        else {
            // Standard-ASCII-Zeichen einfach eins zu eins übernehmen
            output += (char)c;
        }
    }
    return output;
}




void setup()
{
  Wire.begin(21,22);
  lcd.init();
  lcd.clear();
}

void loop() 
{
  lcd.setCursor(0,0);
  String displayReadyString1 = convertToLCDCharset(TextZeile1.c_str());
  lcd.print(displayReadyString1);

  lcd.setCursor(0,1);
  String displayReadyString2 = convertToLCDCharset(TextZeile2.c_str());
  lcd.print(displayReadyString2.c_str());
}

END_FUNCTION_BLOCK