// led_ez_pulse.ino

/*
   Created by ArduinoGetStarted.com
   This example code is in the public domain
   Tutorial page: https://arduinogetstarted.com/tutorials/arduino-output-library
   This example create a high pulse when a button is pressed
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

ezButton button(33);       // create Button object that attach to pin 2; switch s1
ezOutput led(41);          // create ezOutput object that attach to pin 3; LED D1


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

