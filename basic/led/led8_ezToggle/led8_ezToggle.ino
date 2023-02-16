// led8_ezToggle.ino
// Turn ON/OFF led according to state of button

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

// with the 8 led module and mega
// switch D10
// Led    D39


#include <ezButton.h>
#include <ezOutput.h>

ezButton button(10);           // create Button object that attach to pin 7; switch s1
ezOutput led(39);              // create ezOutput object that attach to pin 9; LED D4


void setup()
{
  button.setDebounceTime(50);  // set debounce time to 50 milliseconds
}


void loop()
{
  button.loop();               // MUST call loop() function first

  if (button.isPressed())
  {
    led.toggle();
  }
}
