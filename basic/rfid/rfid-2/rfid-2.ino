// rfid.ino
// http://www.arduinoprojects.net/interface-projects/mfrc522-rfid-reader-arduino-example.php#codesyntax_1


#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
 
void setup() 
{
  Serial.begin(9600);
  SPI.begin(); 
  mfrc522.PCD_Init();
  Serial.println("Place your card on the reader.");
}
 
void loop() 
{
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
 
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "D5 04 C4 AF") //change here to the UID of the card you have
  {
    Serial.println("Authorized");
    Serial.println();
    delay(3000);
  }
  else   
  {
    Serial.println("Access denied");
    delay(3000);
  }
}



