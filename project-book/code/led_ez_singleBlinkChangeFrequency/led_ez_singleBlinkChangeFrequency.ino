// led_ez_singleBlinkChangeFrequency.ino

/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
 * This example blinks an LED:
 * + with frequency changed according to the state of a button
     . if button is NOT pressed, blink slowly
     . if button is pressed, blink fast
 * + without using delay() function
 * This is a non-blocking example 
 */

// Boards to run the sketch:
// my own 2x8cm pcb 8 leds and 1 switch

// 
// pin # Name to Uno Pin
// =====================
// 1  Switch   D2
// 2  LED1     D3 (active low)
// 3  GND      GND


#include <ezOutput.h>                 // ezOutput library

const int BUTTON_PIN = 33;            // switch s1
ezOutput led(40);                     // create ezOutput object that attach to pin 3; LED D2


void setup()
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}


void loop()
{
  led.loop();                         // MUST call led.loop() function in loop()

  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH)            // button is not pressed
  {
    // parameters: off then on
    led.blink(1000, 1000);              // 500 milliseconds ON, 500 milliseconds OFF
  }
  else
  {
   // button is pressed
    led.blink(200, 200);              // 200 milliseconds ON, 200 milliseconds OFF
  }
}
