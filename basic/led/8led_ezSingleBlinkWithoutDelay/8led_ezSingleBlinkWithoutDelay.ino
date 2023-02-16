// 8led_ezSingleBlinkWithoutDelay.ino

/*
 * Created by ArduinoGetStarted.com
 * This example code is in the public domain
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
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

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
ezOutput led(6);            // it sets pinMode() internally

void setup()
{
  led.blink(3000, 1000);     // OFF then ON
}


void loop()
{
  led.loop();              // MUST call the led.loop() function in loop()
}
