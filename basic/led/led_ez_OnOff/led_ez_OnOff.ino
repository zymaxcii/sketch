// led_ez_OnOff.ino

/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 *
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

const int BUTTON_PIN = 33;     // switch s1
ezOutput led(41);               // create ezOutput object that attach to pin 3


void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}


void loop()
{
  int buttonState = digitalRead(BUTTON_PIN);
  // Serial.println(buttonState);
  
  if (buttonState == HIGH)
  {
    led.high();  // internal pull up; not pressed; not light up
  }
  else
  {
    led.low();   // pressed; light up
  }
  // Serial.println(led.getState());
}
