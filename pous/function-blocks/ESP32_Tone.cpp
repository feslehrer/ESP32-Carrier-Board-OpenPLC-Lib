(* Gibt einen Ton am  Speaker (Pin 27) des ESP32-Carrier-Board aus. iOktave:  0 ... 9 ; iNote: NOTE_C...NOTE_B (0...11); xNoteON: 1=Ton an, 0=Ton aus *)

FUNCTION_BLOCK ESP32_Tone
  VAR_EXTERNAL
  END_VAR
  VAR_INPUT
    iOktave : INT := 4;
    iNote : INT := 9;
    xNoteOn : BOOL := 0;
  END_VAR
  VAR
  END_VAR
  VAR_TEMP
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
#include <Arduino.h>


#define SPEAKER 27

#define NOTE_C  0
#define NOTE_Cs 1
#define NOTE_D  2
#define NOTE_Eb 3
#define NOTE_E  4
#define NOTE_F  5
#define NOTE_Fs 6
#define NOTE_G  7
#define NOTE_Gs 8
#define NOTE_A  9
#define NOTE_Bb 10
#define NOTE_B  11

void setup()
{
  pinMode(SPEAKER,OUTPUT);
  ledcAttach(SPEAKER,440,10);           //GPIO 27
}

void loop()
{
    if (xNoteOn)
    {
        int noteValue = (int)iNote.get();
        if (noteValue<0 || noteValue>11)
            noteValue = 9;
        ledcWriteNote(SPEAKER,(note_t)noteValue,iOktave);  // (GPIO, Note, Oktave)
        
        //ledcWriteNote(SPEAKER,NOTE_A,iOktave);  // (GPIO, Note, Oktave)
    }
    else
        ledcWrite(SPEAKER,0);
}

END_FUNCTION_BLOCK