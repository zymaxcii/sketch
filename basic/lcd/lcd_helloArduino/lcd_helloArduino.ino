// lcd_helloArduino.ino
// Print hello Arduino message to lcd

// lcd2004_b.ino

/*
  LiquidCrystal Library - display() and noDisplay()
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD and uses the 
 display() and noDisplay() functions to turn on and off
 the display.
 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
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

 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/LiquidCrystalDisplay

*/

// My standard hardware setup
// lcd pins:  RS EN D4 D5 D6 D7
// to MCU:    D8 D9 D4 D5 D6 D7

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//                RS EN D4 D5 D6 D7
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);




void setup() 
{
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);

  // Print a message to the LCD.
  // lcd.print("hello, yang fan!");
  // Test message
  Serial.begin(9600);
  Serial.println("Testing in progress...\n");
  
  lcd.init();                                // initialize lcd
  lcd.backlight();
                                             // (col, row) please note
  lcd.setCursor(0, 0);                       // move cursor to   (0, 0)
  lcd.print("Arduino");                      // print message at (0, 0)
  lcd.setCursor(0, 1);                       // move cursor to   (2, 1)
  lcd.print("GetStarted.com");               // print message at (2, 1)
  lcd.setCursor(0, 2);
  lcd.print("Wonderful world of");
  lcd.setCursor(0, 3);
  lcd.print("Arduino!!!!!!");
  
}


void loop() 
{
  // Turn off the display:
  lcd.noDisplay();
  delay(500);
   // Turn on the display:
  lcd.display();
  delay(500);
}
