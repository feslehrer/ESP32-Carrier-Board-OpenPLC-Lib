# ESP32-Carrier-Board-OpenPLC-Lib
Stellt Hardwarefunktionen des ESP32-Carrier-Board für OpenPLC zur Verfügung
<img width="1000" alt="image" src="https://github.com/user-attachments/assets/e68f583a-90fb-4ac1-a81e-7e65dbf33006" /><br>
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
### 1. ESP32_DAC
Gibt eine Analoge Spannung an den Analogausgängen des ESP32 aus (Pin 25 und 26). Duch die Spannungsanpassung auf dem Carrierboard, kann an den beiden 2mm-Laborbuchsen die Spannung 0..5V abgegriffen werden.<br>
<img width="100" alt="image" src="https://github.com/user-attachments/assets/875acfcb-0356-4cab-be02-52ed19b26cfa" /><br>
Die Analogausgänge (DAC1 und DAC2) haben eine 8 Bit-Auflösung. <br><img width="350" alt="image" src="https://github.com/user-attachments/assets/c426f678-f6cd-4aee-b622-0b8b29655e2c" /><br>
IN1: USINT<br>
IN2: USINT<br>
Eventuell muss eine Typanpassung <img width="100" alt="image" src="https://github.com/user-attachments/assets/9cb1df54-b108-49f0-a000-d0bf355178bb" />
stattfinden.<br>
### 2. ESP32_Display
Mit diesem Funktions-Block(FB) können die beiden Textzeilen des LC-Displays auf dem Carrierboard beschrieben werden. Dabei kann konstanter Text (immer in Hochkamma 'Hallo Welt') oder Variabler Text angezeigt werden.<br>**Wichtig:** In der lokalen Arduino IDE muss die LiquidCrystal_I2C-Bibliothek von Frank de Brabander installiert sein.<br>
OpenPLC bietet eine Reihe von String-Funktionen zur Bearbeitung des Anzeige-Textes:
<img width="800" alt="image" src="https://github.com/user-attachments/assets/dd611d35-dd6e-48d6-97fe-256119272673" /><br>
TEXTZEILE1: STRING<br>
TEXTZEILE2: STRING<br>
<img width="450" alt="image" src="https://github.com/user-attachments/assets/8e41c839-4e32-4445-be11-3808dfd9755e" />
<br>
### 3. ESP_LM75
Dieser FB gibt die Temperatur des auf dem Carrier-Board verbauten Temperatursensors LM75 zurück. Der Messbereich des LM75 ist -55°C...+125°C mit einer Auflösung von 0,5°C.<br> 
Der Ausgang **STEMPERATURE** gibt einen Formatierten String mit einer Nachkommastelle aus.<br>
FTEMPERATURE: REAL<br>
STEMPERATURE: STRING<br>
### 4. ESP32_PWM
Diese FB gibt eine 12-Bit PWM am angegebenen Pin des ESP32 (PINNR). Es ist darauf zu achten, dass der Pin nicht durch andere Funktionen belegt ist. Die PWM-Frequenz ist fest auf 1000 Hz eingestellt.<br>
<img width="400" alt="image" src="https://github.com/user-attachments/assets/ee9d0d72-fe70-4dd5-b75f-556d61aac507" /><br>
PINNR: UINT (2=Backlight, 27=Speaker)<br>
IDUTYCYCLE: UINT (0...65535)<br>
### 5. ESP32_TASTER_SCHALTER
Mit diesem FB können die 4 nullaktiven Taster auf dem Carrier-Board als Schließer (NO) oder Öffner (NC) konfiguriert werden. Ebenso kann damit eine Schalterfunktion realisiert werden. 
<img width="400" alt="image" src="https://github.com/user-attachments/assets/00ad17c9-65ac-4870-aeab-cc3ee62e5553" /><br>
IN1: BOOL (S1, S2, S3, S4)<br>
PB_SW: BOOL (0:Taster (Pushbutton=default), 1:Schalter (Switch))<br>
NO_NC: BOOL (0:Schließer (NO=default), 2:Öffner (NC)) <br>
### 6. ESP32_TONE
Mit diesem FB wird ein Ton auf dem Lautsprecher (Speaker = Pin 27) des Carrier-Boards ausgegeben. Die Tonfrequenz wird aus Note und Oktave ermittelt. <br>
<img width="900" alt="image" src="https://github.com/user-attachments/assets/7c5a298c-44cc-4f3f-ba6f-91e56b5e582a" /><br>
iOktave: INT (0...9)<br>
iNote: INT (NOTE_C=0,...NOTE_B=11)<br>
xNoteOn: BOOL (0: Ton aus, 1: Ton ein)<br>
**Beispiel**: iNote = NOTE_A (9), iOktave = 4  --> Kammerton A1 = 440 Hz
