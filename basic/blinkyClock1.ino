// https://tronixstuff.com/


/*
  "blinky" the one-eyed clock
  Version beta 1
  John Boxall August 2010/6th April 2022 - http://tronixstuff.com
  DS1307/i2c timekeeping based on code by Maurice Ribble 17-4-2008 -     http://www.glacialwanderer.com/hobbyrobotics
*/

#include "Wire.h"
#define DS1307_I2C_ADDRESS 0x68

int red = 9; // LEDs connected to these pins as you might want to PWM them to alter brightness
int green = 10;
int blue = 11;

// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return ( (val / 10 * 16) + (val % 10) );
}

// Convert binary coded decimal to normal decimal numbers 
byte bcdToDec(byte val)
{
  return ( (val / 16 * 10) + (val % 16) );
}

void setDateDs1307(byte second,        // 0-59
                   byte minute,        // 0-59
                   byte hour,          // 1-23
                   byte dayOfWeek,     // 1-7
                   byte dayOfMonth,    // 1-28/29/30/31
                   byte month,         // 1-12
                   byte year)          // 0-99
{
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write(0);
  Wire.write(decToBcd(second));    // 0 to bit 7 starts the clock
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(dayOfWeek));
  Wire.write(decToBcd(dayOfMonth));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.write(0x10); // sends 0x10 (hex) 00010000 (binary) to control register - turns on square wave
  Wire.endTransmission();
}

void getDateDs1307(byte *second,
                   byte *minute,
                   byte *hour,
                   byte *dayOfWeek,
                   byte *dayOfMonth,
                   byte *month,
                   byte *year)
{
  // Reset the register pointer
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_I2C_ADDRESS, 7);
  *second     = bcdToDec(Wire.read() & 0x7f);
  *minute     = bcdToDec(Wire.read());
  *hour       = bcdToDec(Wire.read() & 0x3f);  // Need to change this if 12 hour am/pm
  *dayOfWeek  = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month      = bcdToDec(Wire.read());
  *year       = bcdToDec(Wire.read());
}

void blinkLED(int colour, int ondelay, int offdelay, int blinks)
// blinks LED on pin 'colour' for 'blinks' times with on and off delay of 'ondelay', 'offdelay'
// colour: 9 is red, 10 is green, 11 is blue
{
  for (int a = 0; a < blinks; a++) {
    digitalWrite(colour, HIGH); delay(ondelay); digitalWrite(colour, LOW); delay(offdelay);
  }
}

void blinkTime() // blinks the time
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  float aa;
  int bb;

  getDateDs1307(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  // convert hours from 24 to 12 hour time
  if (hour == 0)
  {
    hour = 12;
  }
  if (hour > 12)
  {
    hour = hour - 12;
  }
  blinkLED(9, 500, 500, hour); // blink hours in red
  blinkLED(11, 1000, 500, 1); // show blue for one second
  aa = minute;
  aa = aa / 10;
  bb = int(aa); // find the value of tens of minutes (0~5)
  if (bb > 0)
  {
    blinkLED(10, 500, 500, bb); // blink tens of minutes
  }
  if (bb == 0) // but if the time is something like 03:02?
  {
    blinkLED(11, 200, 200, 1); // blink blue quickly for zero
  }
  aa = minute % 10; // find modulo of minutes to get single minutes
  if (bb > 0)
  {
    blinkLED(9, 500, 500, bb); 
  }
  if (bb == 0)
  {
    blinkLED(11, 200, 200, 1); // blink blue quickly for zero
  }
}

void setup()
{
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  Wire.begin();
  second = 0;
  minute = 17;
  hour = 4;
  dayOfWeek = 6; // these values are moot, but need to store something
  dayOfMonth = 28;
  month = 5;
  year = 10;
  setDateDs1307(second, minute, hour, dayOfWeek, dayOfMonth, month, year); 
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() 
{
  blinkTime();
  delay(5000); 
}

