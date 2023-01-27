// ds3231_carlsen.ino
// Set date, time optionally and print date, time to serial monitor
// Why no library added?
// https://howtomechatronics.com/tutorials/arduino/arduino-ds3231-real-time-clock-tutorial/

#include <Wire.h>
#include <DS3231.h>

RTClib rtc;

// Code from the Demo Example of the DS3231 Library


void setup()
{
  Serial.begin(9600);
  // Uncomment next line if using Arduino Leonardo
  // while (!Serial) {}
  
  // Initialize the rtc object
  rtc.begin();
  
  // The following lines can be uncommented to set the date and time
  // rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  // rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
  // rtc.setDate(1, 1, 2014);   // Set the date to January 1st, 2014
}


// Code from the Demo Example of the DS3231 Library
void loop()
{
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating
  delay (1000);
}
