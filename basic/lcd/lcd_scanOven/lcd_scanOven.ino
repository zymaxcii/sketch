// lcd_scanOven.ino
// Simulate oven alarm system
// Non I2C version
// status: compile ok, upload ok but logic incorrect. To debug further

/*
  LiquidCrystal Library - display() and noDisplay()
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 display() and noDisplay() functions to turn on and off display
 
 The circuit:
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe 
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain
 http://arduino.cc/en/Tutorial/LiquidCrystalDisplay
*/

// My standard hardware setup
// lcd pins:  RS EN D4 D5 D6 D7
// to MCU:    D8 D9 D4 D5 D6 D7

// include the library code
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//                RS EN D4 D5 D6 D7
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


void setup()
{
  // Test message
  Serial.begin(9600);
  Serial.println("Testing in progress");
  
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  lcd.clear();
  
  // Print a message to the LCD
  lcd.print("hello, yang fan!");
  delay(1000);
  
  lcd.print("Oven Alarm Sys");
  delay(1000);
  
  lcd.clear();
  lcd.print("Scanning ovens...");
  delay(1000);
}


void loop()
{
  monitorOven();
}


void monitorOven()
{
  int numOven = 20;
  int i = 1;                      // oven counter
  char prefix[16] = "Scan oven ";
  char msg[16];
  char ovenNum[3];
  sprintf(ovenNum, "%d", i);
  strcat(msg, prefix);
  strcat(msg, ovenNum);

  Serial.println(ovenNum);

  
  for (i=1; i<numOven+1; i++)
  {
    
    lcd.clear();
    sprintf(ovenNum, "%d", i);
    strcat(msg, prefix);
    strcat(msg, ovenNum);

    Serial.println(ovenNum);
    Serial.println(prefix);
    Serial.println(msg);

    
    lcd.print(msg);
    delay(5000);

//    lcd.clear();
//    lcd.print("Scan oven 1");
//    delay(500);
//    lcd.print(" ok");
//    delay(5000);
//
//    lcd.clear();
//    lcd.print("Scan oven 2");
//    delay(500);
//    lcd.print(" ok");
//    delay(5000);
//
//    lcd.clear();
//    lcd.print("Scan oven 3");
//    delay(500);
//    lcd.print(" ok");
//    delay(5000);
  }
}
