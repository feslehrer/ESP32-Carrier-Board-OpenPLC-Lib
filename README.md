# ESP32-Carrier-Board-OpenPLC-Lib
Stellt Hardwarefunktionen des ESP32-Carrier-Board für OpenPLC zur Verfügung
## Download
Kopieren Sie die Datei [ESP32-Carrier-Board-Lib.stlib](https://github.com/feslehrer/ESP32-Carrier-Board-OpenPLC-Lib/blob/main/build/) in das OpenPLC-Arbeitsverzeichnis auf ihren Rechner.
Anschließend kann die Bibliothek im eigenen OpenPLC-Projekt hinzugefügt werden.
Um die Bibliotheksfunktionen zu bearbeiten, oder an eigene Hardware anzupassen empfiehlt es sich, das gesamte Repository zu clonen.
## Installation
Über den Link **+ Manage Libraries** wird der Bibliotheksmanager (Library Manager) aufgerufen:<br>
<img width="200" alt="image" src="https://github.com/user-attachments/assets/f715f7cc-873c-4238-9db8-aac5048b7f37" />
<img width="400" alt="image" src="https://github.com/user-attachments/assets/57b27497-f891-4a96-af82-e56ef766943b" /><br><br>
Über das **+**-Zeichen  wird die Bibliothek vom gewählten Download-Verzeichnis installiert.<br>
<img width="400" lt="image" src="https://github.com/user-attachments/assets/adf0492a-fcdb-4e7e-ab32-e204ad2691e2" /><br>
Alternativ kann die Bibliothek auch aus dem Cloud-Katalog heruntergeladen und installiert werden.<br>
Auf die Bibliotheksfunktionen kann anschließend über Library zugegriffen werden:<br>
<img width="250" alt="image" src="https://github.com/user-attachments/assets/a2a7ca7c-17b5-4a58-806a-ce3b520e77c5" />
## Bibliotheksfunktionen
1. ESP32_DAC
Gibt eine Analoge Spannung an den Analogausgängen des ESP32 aus (Pin 25 und 26). Duch die Spannungsanpassung auf dem Carrierboard, können an den Analogausgängen 0..5V abgegriffen werden. Die Analogausgänge (DAC1 und DAC2) haben eine 8 Bit-Auflösung. <br><img width="350" alt="image" src="https://github.com/user-attachments/assets/c426f678-f6cd-4aee-b622-0b8b29655e2c" /><br>
IN1: USINT<br>
IN2: USINT<br>
Eventuell muss eine Typanpassung <img width="100" alt="image" src="https://github.com/user-attachments/assets/9cb1df54-b108-49f0-a000-d0bf355178bb" />
stattfinden.<br>
2. ESP32_Display
Mit diesem Funktions-Block(FB) können die beiden Textzeilen des LC-Displays auf dem Carrierboard beschrieben werden.
<img width="800" alt="image" src="https://github.com/user-attachments/assets/dd611d35-dd6e-48d6-97fe-256119272673" /><br>
<img width="1000" alt="image" src="https://github.com/user-attachments/assets/e68f583a-90fb-4ac1-a81e-7e65dbf33006" /><br>




