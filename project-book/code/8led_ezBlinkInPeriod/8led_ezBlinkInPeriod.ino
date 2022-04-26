// 8led_ezBlinkInPeriod.ino

/*
 * Created by ArduinoGetStarted.com
 * This example code is in the public domain
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 * This example blinks LED:
 * + blink 10 times (5 times OFF->ON, 5 times ON->OFF, interleavedly)
 * + without using delay() function
 * This is a non-blocking example 
 */

// Boards to run the sketch:
// my own 2x8cm pcb 8 leds and 1 switch

// 
// pin # Name to Uno Pin
// =====================
// 1  Switch   D2 (not used)
// 2  LED1     D3 (active low)
// 3  LED2     D4
// 4  LED3     D5
// 5  GND      GND


#include <ezOutput.h>         // ezOutput library

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
ezOutput led(6);              // create ezOutput object that attach to pin 3;


void setup()
{
  // 500 ms ON, 250 ms OFF, start immidiately
  // blink 10 times (5 times OFF->ON, 5 times ON->OFF, interleavedly)
  
  led.blink(250, 1000, 0, 51);    // even number: stay off
                                  // odd number: stay on 
}


void loop()
{
  led.loop();                 // must call led.loop() function in loop()
}
