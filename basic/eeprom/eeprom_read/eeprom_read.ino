// eeprom_read.ino
// Read a byte from address "0" of EEPROM

// http://electronoobs.com/eng_arduino_tut167.php


#include <EEPROM.h>

int brightness;


void setup()
{
  Serial.begin(9600);
  while (!Serial)
  { 
    // wait for user to open serial monitor
  }
}


void loop()
{
  // read a byte from address "0" of EEPROM
  brightness = EEPROM.read(0);
  Serial.println(brightness);
  delay(500);
}
