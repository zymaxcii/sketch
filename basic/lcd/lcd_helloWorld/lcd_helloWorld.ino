// lcd_helloWorld.ino
// Print Hello World and the time passed in seconds
// status: compile ok

/*
 * Tutorial 8: Using the LCD
 * 
 * Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 * library works with all LCD displays that are compatible with the 
 * Hitachi HD44780 driver. There are many of them out there, and you
 * can usually tell them by the 16-pin interface.
 *
 * Adjust the LCDs contrast with the Potentiometer until you
 * can see the characters on the LCD.
 *
 * The circuit:
 * - LCD RS pin to digital pin 8
 * - LCD Enable pin to digital pin 9
 * - LCD D4 pin to digital pin 4
 * - LCD D5 pin to digital pin 5
 * - LCD D6 pin to digital pin 6
 * - LCD D7 pin to digital pin 7
 * - LCD R/W pin to ground
 * - 10K potentiometer divider for LCD pin VO:
 * - 330ohm resistor betweenm LCD pin A and 5v
 * - LCD pin K to ground
 *
 * Library originally added 18 Apr 2008
 * by David A. Mellis
 * library modified 5 Jul 2009
 * by Limor Fried (http://www.ladyada.net)
 * example added 9 Jul 2009
 * by Tom Igoe
 * modified 22 Nov 2010
 * by Tom Igoe
 * modified 14 August 2013
 * by Blaise Jarrett
 *
 * This example code is in the public domain.
 *
 * Derivative work from:
 * http://www.arduino.cc/en/Tutorial/LiquidCrystal
 *
 */

// My standard hardware setup
// lcd pins:  RS EN D4 D5 D6 D7
// to MCU:    D8 D9 D4 D5 D6 D7

#include <LiquidCrystal.h>

// all of our LCD pins
int lcdRSPin = 8;
int lcdEPin =  9;
int lcdD4Pin = 4;
int lcdD5Pin = 5;
int lcdD6Pin = 6;
int lcdD7Pin = 7;

// initialize the library with the numbers of the interface pins
//                  RS EN D4 D5 D6 D7
// LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


LiquidCrystal lcd(lcdRSPin, lcdEPin, lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);


void setup()
{
    // set up the LCD's number of columns and rows
    lcd.begin(16, 2);

    // Print a message to the LCD
    lcd.print("Hello, World!");
}


void loop()
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0)
    lcd.setCursor(0, 1);

    // print the number of seconds since reset
    lcd.print(millis() / 1000);
}
