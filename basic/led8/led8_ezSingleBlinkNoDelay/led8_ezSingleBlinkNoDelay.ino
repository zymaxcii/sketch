// led8_ezSingleBlinkNoDelay.ino
// Blinks an LED without using delay() function

/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example blinks an LED without using delay() function
 * This is a non-blocking example 
 */

// Boards to run the sketch:
// my own 2x8cm pcb 8 leds and 1 switch

// 
// pin # Name to Uno Pin
// =====================
// 2  LED1     D3 (active low)
// 3  GND      GND


#include <ezOutput.h>

ezOutput led(39);          // create ezOutput object
                           // it sets pinMode() internally

void setup()
{
  led.blink(3000, 500);     // OFF then ON
}


void loop()
{
  led.loop();              // MUST call the led.loop() function in loop()
}