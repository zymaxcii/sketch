// led_ez_multipleBlinkWithOffset.ino

/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example blinks 3 LED:
 * + with different frequencies
 * + start blink at different time
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


#include <ezOutput.h>          // ezOutput library

ezOutput led1(41);             // create ezOutput object that attach to pin 3
ezOutput led2(40);
ezOutput led3(39);


void setup()
{
  // parameters: off then on
  led1.blink(250, 500);       // 500 ms ON, 250 ms OFF. start immediately
  led2.blink(250, 250, 1000); // 250 ms ON, 250 ms OFF. start after 1000 ms
  led3.blink(100, 100, 2000); // 100 ms ON, 100 ms OFF. start after 2000 ms
}


void loop()
{
  led1.loop();                // must call led.loop() function in loop()
  led2.loop();
  led3.loop();
}
