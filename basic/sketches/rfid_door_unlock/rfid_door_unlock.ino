/*
 * RFID Door Unlock
 * 
 * learnelectronics
 * 18 FEB 2017
 * 
 * www.youtube.com/c/learnelectronics\
 * 
 *  * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */

#include <MFRC522.h> 
#include <SPI.h> 

#define SDAPIN 10 
#define RESETPIN 9
#define relay 4

byte isTag; 
byte reader; 
byte data[4]; 
byte serial[5]; 
byte secret[5] = {0xB6, 0x7C, 0xBF, 0x93};

MFRC522 nfc(SDAPIN, RESETPIN); 
void setup() {
SPI.begin();
Serial.begin(9600);
pinMode(relay, OUTPUT);
digitalWrite(relay,LOW);


// Start to find an RFID Module
Serial.println("Searching for MFID RC522");
mfrc522.PCD_Init(); 
byte version = nfc.getFirmwareVersion();


if (! version) { 
Serial.print("RFID module not detected");
while(1);
}


Serial.print("RFIDRC522 located ");
Serial.print("Firmware version: 0x");
Serial.println(version, HEX);
Serial.println();
}

void loop() {


String accepted="False";



isTag = nfc.requestTag(MF1_REQIDL, data);

if (isTag == MI_OK) {
delay(200);


reader = nfc.antiCollision(TagData);
memcpy(serial, data, 4); 
Serial.println("Tag detected.");
Serial.print("Serial Number: ");
for (int i = 0; i < 4; i++) {
Serial.print(serial[i], HEX);
Serial.print(", ");
}
Serial.println("");
Serial.println();


/
for(int i=0; i < 4; i++){
if (secret[i] != serial[i]) {
break;
}
if (i == 3) { 
accepted="TRUE";
} 
}
if (accepted == "TRUE"){
Serial.println("Tag Accepted");
Serial.println();
digitalWrite(relay,HIGH);
delay(2000);
digitalWrite(relay,LOW);

delay(1000);
}
else {
Serial.println("Tag Rejected");
digitalWrite(relay,LOW);
delay(500); 
}
}
}


