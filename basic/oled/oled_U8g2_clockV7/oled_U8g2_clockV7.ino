// oled_U8g2_clockV7.ino
// status: compile ok, upload ok, working


// digital-clock-step-7-mode-set-interrupt-timeout
// https://www.youtube.com/watch?v=SuSqalI90G0
// https://arduino-tutorials.net/project/digital-arduino-clock
// https://github.com/BasOnTech/Arduino-Projects-EN


/*

 Bas on Tech - Digital clock
 This project is part of the courses on https://arduino-tutorials.net
  
 (c) Copyright 2018-2020 - Bas van Dijk / Bas on Tech
 This code and course is copyrighted. It is not allowed to use these courses commerically
 without explicit written approval
 
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


#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// Variables to store the time
volatile byte hours = 0;
volatile byte minutes = 0;
volatile byte seconds = 0;

// Constants for the button pins
// The FALLING interrupt is only available at pin 2 and 3 on the Arduino UNO 
const int PIN_BUTTON_MODE = 3;
const int PIN_BUTTON_SET = 2;

const int BUTTON_MODE_DEBOUNCE_TIME = 250;
const int BUTTON_SET_DEBOUNCE_TIME = 10;

const int MODE_SET_TIMEOUT = 5000;

const int MODE_SHOW_TIME = 0;
const int MODE_SET_SECONDS = 3;
const int MODE_SET_MINUTES = 2;
const int MODE_SET_HOURS = 1;

// Button state variables
unsigned long elapsedButtonModeMillis = 0;
unsigned long previousButtonModeMillis = 0;

unsigned long elapsedButtonSetMillis = 0;
unsigned long previousButtonSetMillis = 0;

// Char array for the time being showed on the display
char timeString[9];

// Variables to store the time
unsigned long currentMillis = 0;

// Int is enough to store the elapsed time
unsigned long elapsedTimeUpdateMillis = 0;
unsigned long previousTimeUpdateMillis = 0;

float percentageOfSecondElapsed = 0;

byte currentMode = MODE_SHOW_TIME;

volatile boolean buttonModePressed = false;
volatile boolean buttonSetPressed = false;

// A complete list of all displays is available at:
// https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup(void)
{
  u8g2.setFont(u8g2_font_logisoso28_tf);
  u8g2.begin();

  // Empty the interrupt queue. This makes sure there are 
  // no old pending interrupts in the queue which are processed on startup
  // More info: https://arduino.stackexchange.com/questions/30968/how-do-interrupts-work-on-the-arduino-uno-and-similar-boards
  EIFR = bit (INTF0);      // clear flag for interrupt 0
  EIFR = bit (INTF1);      // clear flag for interrupt 1

  digitalWrite(PIN_BUTTON_MODE, HIGH);
  digitalWrite(PIN_BUTTON_SET, HIGH);

  // Configure the pins of the buttons with the internal PULLUP resistor
  pinMode(PIN_BUTTON_MODE, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_BUTTON_MODE), modeButtonPressedInterrupt, FALLING);

  pinMode(PIN_BUTTON_SET, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_BUTTON_SET), setButtonPressedInterrupt, FALLING);
}


void loop(void)
{
  // millis() itself takes 1.812 micro seconds that is 0.001812 milli seconds
  // https://arduino.stackexchange.com/questions/113/is-it-possible-to-find-the-time-taken-by-millis
  currentMillis = millis();

  elapsedButtonModeMillis = currentMillis - previousButtonModeMillis;
  elapsedButtonSetMillis = currentMillis - previousButtonSetMillis;

  checkTime();

  if (currentMode == MODE_SHOW_TIME)
  {
    increaseSeconds();
  }
  else
  {
    if (elapsedButtonModeMillis > MODE_SET_TIMEOUT && elapsedButtonSetMillis > MODE_SET_TIMEOUT) 
    {
      currentMode = MODE_SHOW_TIME;
    }
    
    previousTimeUpdateMillis = currentMillis;
  }

  if (buttonModePressed)
  {
    modeButtonHandler();
  }

  if (buttonSetPressed)
  {
    buttonSetHandler();
  }
  drawScreen();
}


void checkTime()
{
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
}


void modeButtonPressedInterrupt()
{
  buttonModePressed = true;
}


void modeButtonHandler()
{
  if (elapsedButtonModeMillis > BUTTON_MODE_DEBOUNCE_TIME)
  {
    previousButtonModeMillis = currentMillis;
    currentMode++;

    if (currentMode > 3)
    {
      currentMode = 0;
    }

  }
  buttonModePressed = false;
}


void setButtonPressedInterrupt()
{
  buttonSetPressed = true;
}


void buttonSetHandler()
{
  if (elapsedButtonSetMillis > BUTTON_SET_DEBOUNCE_TIME)
  {
    previousButtonSetMillis = currentMillis;

    if (currentMode == MODE_SET_SECONDS)
    {
      seconds = 0;
    }
    
    if (currentMode == MODE_SET_MINUTES)
    {
      minutes++;
    }
    
    if (currentMode == MODE_SET_HOURS)
    {
      hours++;
    }
  }
  buttonSetPressed = false;
}


void increaseSeconds()
{
  elapsedTimeUpdateMillis = currentMillis - previousTimeUpdateMillis;

  // Check if 1000ms, 1 second, has been elapsed
  if (elapsedTimeUpdateMillis > 1000)
  {
    seconds++;

    // It might be possible that more than 1000ms has been elapsed e.g. 1200ms 
    // Then there are already 200ms elapsed of the next second. We need to
    // substract these on the "last time". So the next second will be updated 200ms earlier. 
    // This reduces the amount of time drift.
    previousTimeUpdateMillis = currentMillis - (elapsedTimeUpdateMillis - 1000);
  }
}


void drawScreen()
{
  u8g2.firstPage();

  do
  {
    if (currentMode != MODE_SHOW_TIME)
    {
      u8g2.drawTriangle((currentMode-1) * 43+5,0,currentMode*43-5,0,(currentMode-1)*43+21,5);
    }

    drawAnimation();
    drawTime();

  } while (u8g2.nextPage());
}


void drawTime()
{
  // Found at https://forum.arduino.cc/index.php?topic=371117.0
  // sprintf_P uses the Program Memory instead of RAM,
  // more info at http://gammon.com.au/progmem
  // Here we format the minutes and seconds with a leading zero: e.g. 01, 02, 03 etc.
  sprintf_P(timeString, PSTR("%2d:%02d:%02d"), hours, minutes, seconds);

  // Draw the timeString
  u8g2.drawStr(0, 45, timeString);
}


void drawAnimation()
{
  // Calculate the percentage elapsed of a second
  percentageOfSecondElapsed = elapsedTimeUpdateMillis / 1000.0;

  if (currentMode == MODE_SHOW_TIME)
  {
    // Draw the yellow lines
    u8g2.drawBox(0, 0, 127 - (127 * percentageOfSecondElapsed), 2);
    u8g2.drawBox(0, 3, (127 * percentageOfSecondElapsed), 2);
  }
}
