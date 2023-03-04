// eeprom_getAll.ino
// https://linuxhint.com/eeprom-library-arduino/

#include <EEPROM.h>

void setup()
{
  float f = 0.00;  
  int eeAddress = 0;
  
  Serial.begin(9600);
  Serial.print("Read float from EEPROM: ");
  
  EEPROM.get(eeAddress, f);
  Serial.println(f, 4);    
  structurevalues();
}


struct data
{
  float value1;
  byte  value2;
  char  word[8];
};


void structurevalues()
{
  int eeAddress = sizeof(float);
  data values;
  
  EEPROM.get(eeAddress, values);
  
  Serial.println("Read structure from EEPROM: ");
  Serial.println(values.value1);
  Serial.println(values.value2);
  Serial.println(values.word);
}


void loop() { }
