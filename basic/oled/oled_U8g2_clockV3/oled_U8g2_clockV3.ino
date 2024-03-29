// oled_U8g2_clockV3.ino
// step 3: using animation
// status: compile ok, upload ok

// https://www.youtube.com/watch?v=SuSqalI90G0
// https://arduino-tutorials.net/project/digital-arduino-clock
// https://github.com/BasOnTech/Arduino-Projects-EN

/*
 Bas on Tech - Digital clock
 This project is part of the courses on https://arduino-tutorials.net
 (c) Copyright 2018-2020 - Bas van Dijk / Bas on Tech
 This code and course is copyrighted. It is not allowed to use these courses 
 commerically without explicit written approval
 
 YouTube:    https://www.youtube.com/c/BasOnTech
 Facebook:   https://www.facebook.com/BasOnTechChannel
 Instagram:  https://www.instagram.com/BasOnTech
 Twitter:    https://twitter.com/BasOnTech

------------------------------------------------------------------------------   

   128x64 SSD1306 OLED

   PIN CONNECTIONS:

   VCC    5V
   GND    GND
   SCL    A5
   SDA    A4
*/


#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// Variables to store the time
byte hours = 0;
byte minutes = 0;
byte seconds = 0;

// Constants for the button pins
const int PIN_BUTTON_HOURS   = 10;    // my Mega board
const int PIN_BUTTON_MINUTES = 11;

// Variables for the button state
// We are using the internal pull-up resistors via INPUT_PULLUP,
// press is LOW and not pressed is HIGH
int buttonHoursState   = HIGH;
int buttonMinutesState = HIGH;

// Char array for the time being showed on the display
char timeString[9];

// Variables to store the time
unsigned long currentMillis = 0;


// Int is enough to store the elapsed time
int elapsedTimeUpdateMillis = 0; 
unsigned long lastTimeUpdateMillis = 0;

float percentageOfSecondElapsed = 0;

// A complete list of all displays is available at:
// https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup(void)
{
  // Configure the pins of the buttons with the internal PULLUP resistor
  pinMode(PIN_BUTTON_HOURS,   INPUT_PULLUP);
  pinMode(PIN_BUTTON_MINUTES, INPUT_PULLUP);

  u8g2.setFont(u8g2_font_logisoso28_tf);
  u8g2.begin();
}


void loop(void)
{
  // millis() itself takes 1.812 micro seconds that is 0.001812 milli seconds
  // https://arduino.stackexchange.com/questions/113/is-it-possible-to-find-the-time-taken-by-millis
  currentMillis = millis();

  elapsedTimeUpdateMillis = currentMillis - lastTimeUpdateMillis;

  // Check if the hours button has been pressed
  buttonHoursState = digitalRead(PIN_BUTTON_HOURS);
  
  if (buttonHoursState == LOW)
  {
    hours++;
  }

  // Check if the minutes button has been pressed
  buttonMinutesState = digitalRead(PIN_BUTTON_MINUTES);
  
  if (buttonMinutesState == LOW)
  {
    minutes++;
  }

  // Check if a minutes has been elapsed
  if (seconds > 59)
  {
    seconds = 0;
    minutes++;
  }

  // Check if an hour has been elapsed
  if (minutes > 59)
  {
    minutes = 0;
    hours++; 
  }

  // Check if a day has been elapsed
  if (hours > 23)
  {
    hours = 0;
  }


  // Check if 1000ms, 1 second, has been elapsed
  if (elapsedTimeUpdateMillis > 1000)
  {
    seconds++;

    // It might be possible that more than 1000ms has been elapsed e.g. 1200ms 
    // Then there are already 200ms elapsed of the next second. We need to
    // substract these on the "last time".
    // So the next second will be updated 200ms earlier. 
    // This reduces the amount of time drift.
    lastTimeUpdateMillis = currentMillis - (elapsedTimeUpdateMillis - 1000);
  }

  // Calculate the percentage elapsed of a second
  percentageOfSecondElapsed = elapsedTimeUpdateMillis / 1000.0;

  u8g2.firstPage();

  do
  {
    // Draw the yellow lines
    u8g2.drawBox(0, 0, 127 - (127 * percentageOfSecondElapsed), 2);
    u8g2.drawBox(0, 3, (127 * percentageOfSecondElapsed), 2);

    // Found at https://forum.arduino.cc/index.php?topic=371117.0
    // sprintf_P uses the Program Memory instead of RAM,
    // more info at http://gammon.com.au/progmem
    // Here we format the minutes and seconds with a leading zero:
    // e.g. 01, 02, 03 etc.
    sprintf_P(timeString, PSTR("%2d:%02d:%02d"), hours, minutes, seconds);

    // Draw the timeString
    u8g2.drawStr(0, 45, timeString);
    
  } while (u8g2.nextPage());
}
