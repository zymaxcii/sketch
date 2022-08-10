// 8led_ezOnOff.ino

/*
 * Created by ArduinoGetStarted.com
 * This example code is in the public domain
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 * This example turn ON/OFF led according to state of button
 */

// Boards to run the sketch:
// my own 2x8cm pcb 8 leds and 1 switch

// 
// pin # Name to Uno Pin
// =====================
// 1  Switch   D2
// 2  LED1     D3 (active low)
// 3  GND      GND


#include <ezOutput.h>          // ezOutput library

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
const int BUTTON_PIN = 2;
ezOutput led(6);               // create ezOutput object that attach to pin 6


void setup()
{
  // Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}


void loop()
{
  int buttonState = digitalRead(BUTTON_PIN);
  // Serial.println(buttonState);
  
  if (buttonState == LOW)
  {
    led.high();  // pressed; light up
  }
  else
  {
    led.low();   // not pressed; light off
  }
  // Serial.println(led.getState());
}
