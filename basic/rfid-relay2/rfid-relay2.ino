// rfid-relay2.ino
// https://arduinogetstarted.com/tutorials/arduino-rfid-nfc-relay


/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-rfid-nfc-relay
 */

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 5
#define RELAY_PIN A5 // the Arduino pin connects to relay

MFRC522 rfid(SS_PIN, RST_PIN);

byte authorizedUID1[4] = {0x3A, 0xC9, 0x6A, 0xCB};
byte authorizedUID2[4] = {0x30, 0x01, 0x8B, 0x15};   

void setup() {
  Serial.begin(9600);
  SPI.begin(); // init SPI bus
  rfid.PCD_Init(); // init MFRC522
  pinMode(RELAY_PIN, OUTPUT);   // initialize pin as an output.
  digitalWrite(RELAY_PIN, LOW); // deactivate the relay

  Serial.println("Tap RFID/NFC Tag on reader");
}

void loop() {
  if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

      if (rfid.uid.uidByte[0] == authorizedUID1[0] &&
          rfid.uid.uidByte[1] == authorizedUID1[1] &&
          rfid.uid.uidByte[2] == authorizedUID1[2] &&
          rfid.uid.uidByte[3] == authorizedUID1[3] ) {
        Serial.println("Authorized Tag 1");
        digitalWrite(RELAY_PIN, HIGH); // activate the relay for 2 seconds
        delay(2000);
        digitalWrite(RELAY_PIN, LOW);  // deactivate the relay
      }
      else
      if (rfid.uid.uidByte[0] == authorizedUID2[0] &&
          rfid.uid.uidByte[1] == authorizedUID2[1] &&
          rfid.uid.uidByte[2] == authorizedUID2[2] &&
          rfid.uid.uidByte[3] == authorizedUID2[3] ) {
        Serial.println("Authorized Tag 2");
        digitalWrite(RELAY_PIN, HIGH); // activate the relay for 2 seconds
        delay(2000);
        digitalWrite(RELAY_PIN, LOW);  // deactivate the relay
      }
      else
      {
        Serial.print("Unauthorized Tag with UID:");
        for (int i = 0; i < rfid.uid.size; i++) {
          Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(rfid.uid.uidByte[i], HEX);
        }
        Serial.println();
      }

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
}


