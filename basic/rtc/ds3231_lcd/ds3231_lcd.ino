// ds3231_lcd.ino
// DIsplay date, time on LCD1602 non-i2c version
// https://howtomechatronics.com/tutorials/arduino/arduino-ds3231-real-time-clock-tutorial/
// compile error

// My standard hardware setup
// ds3231 rtc module:
// A4 RTC module, pin SDA
// A5 RTC module, pin SCL
// VCC
// GND
//
// LCD 1602
// more to add...


/*
* Arduino DS3231 Real Time Clock Module Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
* DS3231 Library made by Henning Karlsen which can be found and downloaded from his website, www.rinkydinkelectronics.com.
*
*/


#include <DS3231.h>
#include <LiquidCrystal.h>           // includes the LiquidCrystal Library 

DS3231  rtc(SDA, SCL);
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object
// Parameters: ( rs, enable, d4, d5, d6, d7) 


void setup()
{ 
  rtc.begin();                // Initialize the rtc object
  lcd.begin(16,2);            // Initializes the interface to the LCD screen
                              // and specifies the dimensions (width and height)
}


void loop()
{ 
 lcd.setCursor(0, 0);
 lcd.print("Time:  ");
 lcd.print(rtc.getTimeStr());
 
 lcd.setCursor(0, 1);
 lcd.print("Date: ");
 lcd.print(rtc.getDateStr());
 
 delay(1000); 
}