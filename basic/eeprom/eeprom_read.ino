// eeprom_read.ino
// http://electronoobs.com/eng_arduino_tut167.php


#include <EEPROM.h>

int brightness;         //Create an empty variable

void setup() {
  Serial.begin(9600);
  while (!Serial) { 
    // wait for user to open serial monitor
  }
}

void loop() {
  // read a byte from the address "0" of the EEPROM
  brightness = EEPROM.read(0);
  Serial.println(brightness);
  delay(500);
}
