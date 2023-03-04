// eeprom_putAll.ino
// https://linuxhint.com/eeprom-library-arduino/

#include <EEPROM.h>

struct data
{
  float value1;
  byte value2;
  char word[8];
};


void setup()
{
  Serial.begin(9600);
  
  float f = 967.817;
  int eeAddress = 0;
   
  EEPROM.put(eeAddress, f);
  
  Serial.print("This address:");
  Serial.println(eeAddress);
  Serial.print("has float value  of ");
  Serial.println(f);
  Serial.println();
  
  data values =
  {
    2.65,
    89,
    "Hello!"
  };
  
  eeAddress += sizeof(float);
  EEPROM.put(eeAddress, values);
  
  Serial.print("This address:");
  Serial.print(eeAddress);
  Serial.print('\t');
  Serial.print("has structure having the information:");
  Serial.println();
  Serial.println(values.value1);
  Serial.println(values.value2);
  Serial.println(values.word);
}


void loop() { }
