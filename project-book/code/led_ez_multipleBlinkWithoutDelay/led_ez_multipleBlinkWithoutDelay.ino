// led_ez_multipleBlinkWithoutDelay.ino

/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example blinks 3 LED:
 * + with diffent frequencies
 * + start blink at the same time
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



#include <ezOutput.h>            // ezOutput library

ezOutput led1(41);                // create ezOutput object that attach to pin 7
ezOutput led2(40);
ezOutput led3(39);


void setup()
{
  led1.blink(1000, 5000);        // off then on
  led2.blink(500, 2000);         // 500 milliseconds OFF, 2000 milliseconds ON
  led3.blink(100, 1000);         // 100 milliseconds OFF, 1000 milliseconds ON
}


void loop()
{
  led1.loop();                   // MUST call loop() function in loop()
  led2.loop();
  led3.loop();
}
