// eeprom_writeAnything.ino
// http://electronoobs.com/eng_arduino_tut167.php


#include <EEPROM.h>   // We need this library
#include   // for type definitions

//We create two fucntions for writing and reading data from the EEPROM
template <class T> int EEPROM_writeAnything(int ee, const T& value)
{
  const byte* p = (const byte*)(const void*)&value;
  unsigned int i;
  for (i = 0; i < sizeof(value); i++)
    EEPROM.write(ee++, *p++);
    return i;
}
template <class T> int EEPROM_readAnything(int ee, T& value)
{
    byte* p = (byte*)(void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          *p++ = EEPROM.read(ee++);
    return i;
}
void setup() {
  Serial.begin(9600);               //Use serial to check the data
  /*The next line, will store the 1200 number on positions 0, 1, 2, 3 and 4 of the EEPROM automatically
  since 1200 divided by 254 = 4,7 so it will fit in 5 bytes. */
  EEPROM_writeAnything(0, 1200);  
  /*We know that bytes 0 to 5 are already ocupied by previous line so we write the second number starting 
  from position 5. The function will automatically fill bytes 5, 6, 7 and so on...*/
  EEPROM_writeAnything(5, 2000);   
}


void loop() {
  int my_value_1, my_value_2;
  /*With the next line we read the number starting on position "0" and store into the my_value_1 variable.
  So, with the next line, my_value_1 will be equal to 1200, which is the value we haev stored before */
  EEPROM_readAnything(0, my_value_1); 
  /*With the next line we read the number starting on position "5" and store into the my_value_2 variable.
  So, with the next line, my_value_1 will be equal to 2000, which is the value we haev stored before */
  EEPROM_readAnything(5, my_value_2);
  Serial.print("Value 1: "); 
  Serial.print(my_value_1);           //Check the value
  Serial.print("    Value 2: ");  
  Serial.println(my_value_2);         //Check the value
}


