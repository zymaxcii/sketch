// eeprom_write.ino
// Write a byte to eeprom and then read back
// http://electronoobs.com/eng_arduino_tut167.php


#include <EEPROM.h>

int brightness;


void setup()
{
  Serial.begin(9600); 
  EEPROM.write(0, 2);      // write a byte on address 0
                            // Value must be between 0 and 255
}


void loop()
{
  // read a byte from address "0" of EEPROM
  brightness = EEPROM.read(0);
  Serial.println(brightness);
  delay(500);
}
