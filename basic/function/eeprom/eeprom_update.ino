// eeprom_update.ino
// https://linuxhint.com/eeprom-library-arduino/


#include <EEPROM.h>

int address = 4;
int value;
int value1 = 300;


void setup()
{
  Serial.begin(9600);
  
  value = EEPROM.read(address);
  
  Serial.print("This address:");
  Serial.println(address);
  Serial.print("previously value of ");
  Serial.println(value);
  Serial.println();  
  
  EEPROM.update(address, value1);
  
  Serial.print("This address:");
  Serial.println(address);
  Serial.print(" updated value of ");
  Serial.println(value1);
  Serial.println();
}


void loop() { }
