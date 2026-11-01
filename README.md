# ESP32-Carrier-Board-OpenPLC-Lib
Stellt Hardwarefunktionen des ESP32-Carrier-Board für OpenPLC zur Verfügung
## Installation
Kopieren Sie die Datei [ESP32-Carrier-Board-Lib.stlib](https://github.com/feslehrer/ESP32-Carrier-Board-OpenPLC-Lib/blob/main/build/) in das OpenPLC-Arbeitsverzeichnis auf ihren Rechner.
Anschließend kann die Bibliothek im eigenen OpenPLC-Projekt hinzugefügt werden.
Um die Bibliotheksfunktionen zu bearbeiten, oder an eigene Hardware anzupassen empfiehlt es sich, das gesamte Repository zu clonen.

## Bibliotheksfunktionen
Auf die Bibliotheksfunktionen kann über Library zugegriffen werden:<br>
<img width="250" alt="image" src="https://github.com/user-attachments/assets/a2a7ca7c-17b5-4a58-806a-ce3b520e77c5" />

1. ESP32_DAC
Gibt eine Analoge Spannung an den Analogausgängen des ESP32 aus (Pin 25 und 26). Duch die Spannungsanpassung auf dem Carrierboard, können an den Analogausgängen 0..5V abgegriffen werden. Die Analogausgänge (DAC1 und DAC2) haben eine 8 Bit-Auflösung.<br><img width="350" alt="image" src="https://github.com/user-attachments/assets/c426f678-f6cd-4aee-b622-0b8b29655e2c" />

