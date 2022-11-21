// ds3231_setTime.ino
// Set date and time and print them to the serial monitor
// can run on my max7219 setup which has a ds3231 rtc module in it
// https://circuitdigest.com/microcontroller-projects/interfacing-ds3231-rtc-with-arduino-and-diy-digital-clock

// My standard hardware setup
// ds3231 rtc module:
// A4 RTC module, pin SDA
// A5 RTC module, pin SCL
// VCC
// GND


#include <RTClib.h>
#include <Wire.h>

RTC_DS3231 rtc;

char t[32];


void setup()
{
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  //rtc.adjust(DateTime(2019, 1, 21, 5, 0, 0));
}


void loop()
{
  DateTime now = rtc.now();
  
  sprintf(t, "%02d:%02d:%02d %02d/%02d/%02d", now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());  

  Serial.print(F("Date/Time: "));
  Serial.println(t);
  delay(1000);
}
