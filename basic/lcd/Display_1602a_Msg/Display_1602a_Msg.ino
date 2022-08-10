//
// Non I2C version
//

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

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
  // Print a message to the LCD
  // lcd.print("hello, yang fan!");
  // lcd.display();
  // delay(5000);
  // lcd.noDisplay();

  lcd.display();
  lcd.print("Oven Alarm Sys");
  // lcd.display();
  delay(5000);
  lcd.clear();
  lcd.print("Scanning ovens...");
  delay(5000);

  // Test message
  Serial.begin(9600);
  Serial.println("Testing in progress...\n");
}


void loop()
{
  //  // Turn off the display:
  //  lcd.noDisplay();
  //  delay(500);
  //   // Turn on the display:
  //  lcd.display();
  //  delay(500);

  monitorOven();
}


void monitorOven()
{
  int numOven = 20;
  int i = 1; // counter
  char prefix[16] = "Scan oven ";
  char msg[16];
  char ovenNum[2];
  sprintf(ovenNum, "%d", i);
  strcat(msg, prefix);
  strcat(msg, ovenNum);

  
  for (i=1; i<numOven+1; i++)
  {
   
    //    lcd.clear();
    //    sprintf(ovenNum, "%d", i);
    //    strcat(msg, prefix);
    //    strcat(msg, ovenNum);
    //    lcd.print(msg);
    //    delay(5000);

    lcd.clear();
    lcd.print("Scan oven 1");
    delay(500);
    lcd.print(" ok");
    delay(5000);

    lcd.clear();
    lcd.print("Scan oven 2");
    delay(500);
    lcd.print(" ok");
    delay(5000);

    lcd.clear();
    lcd.print("Scan oven 3");
    delay(500);
    lcd.print(" ok");
    delay(5000);
  }
}

