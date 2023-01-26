// ds3231_displaySerialMonitor.ino
// https://create.arduino.cc/projecthub/MisterBotBreak/how-to-use-a-real-time-clock-module-ds3231-bc90fe


#include <Wire.h>
#include <DS3231.h>  // ds3231?
 
struct ts t; 

 
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  
  DS3231_init(DS3231_CONTROL_INTCN);
  /*----------------------------------------------------------------------------
  In order to synchronise your clock module, insert timetable values below !
  ----------------------------------------------------------------------------*/
  t.hour = 15; 
  t.min  = 00;
  t.sec  = 0;
  t.mday = 26;
  t.mon  = 1;
  t.year = 2023;
  DS3231_set(t); 
}


void loop()
{
  DS3231_get(&t);
  Serial.print("Date : ");
  Serial.print(t.mday);
  Serial.print("/");
  Serial.print(t.mon);
  Serial.print("/");
  Serial.print(t.year);

  Serial.print("\t Hour : ");
  Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(".");
  Serial.println(t.sec);
  delay(1000);
}
