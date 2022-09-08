// rfid2.ino

// https://www.engineersgarage.com/arduino-mfrc522-rc522-rfid-reader-interfacing-access-control/


#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
byte nuidPICC[4];

String NUID_dec, NUID_hex;
String RKey;


void setup()
{ 
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 
  // Define Key
  for (byte i = 0; i < 6; i++)
  {
    key.keyByte[i] = 0xFF;
  }
  
  RKey = String(key.keyByte[0], HEX) + " "
           +String(key.keyByte[1], HEX) + " "
           +String(key.keyByte[2], HEX) + " " 
           +String(key.keyByte[3], HEX) + " "
           +String(key.keyByte[4], HEX) + " "
           +String(key.keyByte[5], HEX);
RKey.toUpperCase();
Serial.print(F("MFRC522 Key: "));
Serial.println(RKey);
}

void loop()
{
// Reset the loop if no new card present on the sensor/reader.
if ( ! rfid.PICC_IsNewCardPresent()) return;

// Verify if the NUID has been readed
if ( ! rfid.PICC_ReadCardSerial()) return;

Serial.print(F("PICC type: "));
MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
Serial.println(rfid.PICC_GetTypeName(piccType));

/* 
// Check is the PICC of Classic MIFARE type
if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
}*/

NUID_dec = String(rfid.uid.uidByte[0])+ " " 
           +String(rfid.uid.uidByte[1]) + " "
           +String(rfid.uid.uidByte[2]) + " "
           +String(rfid.uid.uidByte[3]);
Serial.print("NUID Tag (DEC): "); 
Serial.println(NUID_dec); 

NUID_hex = String(rfid.uid.uidByte[0], HEX) + " "
           +String(rfid.uid.uidByte[1], HEX) + " "
           +String(rfid.uid.uidByte[2], HEX) + " " 
           +String(rfid.uid.uidByte[3], HEX);
NUID_hex.toUpperCase();
Serial.print("NUID Tag (HEX): "); 
Serial.println(NUID_hex);

for (byte i = 0; i < 4; i++) {
nuidPICC[i] = rfid.uid.uidByte[i];
}

if (compareNUID(nuidPICC, 41, 153, 94, 89)) Serial.println("Access Granted"); 
else  Serial.println("Access Denied"); 

Serial.println();

// Halt PICC
rfid.PICC_HaltA();

// Stop encryption on PCD
rfid.PCD_StopCrypto1();
}


boolean compareNUID(byte x[4], byte x0, byte x1, byte x2, byte x3)
{
  if (x[0] == x0 && x[1] == x1 && x[2] == x2 && x[3] == x3)
  return true; 
  else return false;
}
