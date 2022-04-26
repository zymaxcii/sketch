// 8led_ezPulse.ino

/*
   Created by ArduinoGetStarted.com
   This example code is in the public domain
   Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
   This example creates a high pulse when a button is pressed
*/

// Boards to run the sketch:
// my own 2x8cm pcb 8 leds and 1 switch

// 
// pin # Name to Uno Pin
// =====================
// 1  Switch   D2 (not used)
// 2  LED1     D3 (active low)
// 3  LED2     D4 (not used)
// 4  LED3     D5 (not used)
// 5  GND      GND


#include <ezButton.h>
#include <ezOutput.h>

// my standard pin assignments for 8 leds on uno and nano: 6,7,8,9,10,11,12,13
// pins 2,3,4,5 for switches; pin 2 with interrupt
ezButton button(2);        // create Button object that attach to pin 2
ezOutput led(6);           // create ezOutput object that attach to pin 3; LED D1


void setup()
{
  button.setDebounceTime(50); // set debounce time to 50 ms
  led.low();
}


void loop()
{
  button.loop();         // MUST call loop() function first
  led.loop();            // MUST call loop() function first

  if (button.isPressed())
  {
    if (led.getState() == LOW)
    {
      led.pulse(3000, 1000); // 250 ms delay, 1000 ms HIGH pulse
                             // 2000 ms delay, 3000 ms HIGH pulse
    }
  }
}

