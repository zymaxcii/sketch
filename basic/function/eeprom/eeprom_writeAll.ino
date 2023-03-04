// eeprom_writeMore.ino
// https://linuxhint.com/eeprom-library-arduino/

#include <EEPROM.h>

int address = 0;
int value = 200;


void setup()
{
  Serial.begin(9600);
}


void loop()
{
  EEPROM.write(address, value);
  
  Serial.print("This address:");
  Serial.println(address);
  Serial.print("has value of ");
  Serial.println(value);
  Serial.println();
  
  address = address + 1;
  if (address == EEPROM.length())
  {
    address = 0;
  }
  delay(500);
}
