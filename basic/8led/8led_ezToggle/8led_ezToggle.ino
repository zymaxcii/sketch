// 8led_ezToggle.ino

/*
 * Created by ArduinoGetStarted.com
 * This example code is in the public domain
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
 * This example turns ON/OFF led according to state of button
 */

// Boards to run the sketch:
// my own 2x8cm pcb 8 leds and 1 switch

// 
// pin # Name to Uno Pin
// =====================
// 1  Switch   D2
// 2  LED1     D3 (active low)
// 3  GND      GND


#include <ezButton.h>
#include <ezOutput.h>

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
ezButton button(2);
ezOutput led(6);


void setup()
{
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
}


void loop()
{
  button.loop();              // MUST call loop() function first

  if (button.isPressed())
  {
    led.toggle();
  }
}
